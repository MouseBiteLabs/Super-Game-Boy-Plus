//#include "si5351.h"
//#include "Wire.h"

//#include <si5351-avr-tiny-minimal.h>
//#include <USI_TWI_Master.h>

// FOR USE WITH ATTINY85

#include <Adafruit_SI5351.h>

Adafruit_SI5351 clockgen = Adafruit_SI5351();

const int base_clock_factor = 166;                                                                                    // Yields correct clock speed of 4.193 MHz with a clock_speed_factor of 1
const int array_length = 7;                                                                                           // Set how many clock speed settings are stored
const float clock_speed_factor[array_length] = {0.5,0.67,0.85,1,1.25,1.5,2};                                          // Array of clock dividers (lower number = faster)
const int clock_default = 3;                                                                                          // Default speed factor setting
int clock_selection = clock_default;                                                                                  // Default speed factor selection - remember list is 0-indexed
int clock_speed = base_clock_factor;                                                                                  // Default clock divider factor for normal frequency

byte button_state;                                                                                                    // Used for storing sampled buttons when P15 falls

int button_count = 0;                                                                                                 // Variable for timing how long buttons are held
const int base_count = 1500;                                                                                          // Count value before clock speed changes for default clock speed
const int count_max[array_length] = {base_count,base_count,base_count,base_count,base_count,base_count,base_count};   // The delays before changing clock speeds for each speed setting. Default is to set them all equal, as the timing is 
                                                                                                                      //  driven by the micro's clock, not the SGB clock, but sometimes button state collection skips at higher speeds.
int start_pressed_first = 0;                                                                                          // Flag sets to 1 if start button is pressed before select
int select_pressed_first = 0;                                                                                         // Flag sets to 1 if select button is pressed before start

int disable_count = 0;                                                                                                // Disable timer variable
int disable_flag = 0;                                                                                                 // If 0, clock changing is enabled; if 1, clock changing is disabled
const int base_disable_count = base_count*2;                                                                          // How long pressing start+select at the same time to disable clock changing takes
int able2disable_flag = 1;                                                                                            // Flag used to prevent toggling of enable/disable of clock changing that would happen when holding start+select down for too long

const int debounce_delay = 100;                                                                                       // Allow delay between pressing start+select at the "same time"
int debounce_count = 0;                                                                                               // Variable for debouncing counter

void setup(void)
{
  //Serial.begin(9600);
  //pinMode(35,INPUT); //P12, PC2                                                                // Select
  //pinMode(34,INPUT); //P13, PC3                                                                // Start
  //pinMode(32,INPUT); //P15, PC5                                                                // Pin that polls face buttons
  pinMode(PCINT3,INPUT);  // P12, PB3 on pin 2 (FROM PC2)
  pinMode(PCINT4,INPUT);  // P13, PB4 on pin 3 (FROM PC3)
  pinMode(PCINT1,INPUT);  // P15, PB1 on pin 6 (FROM PC5)
  
  // SCL is pin 7 of the ATTINY85
  // SDA is pin 5 of the ATTINY85

  if (clockgen.begin() != ERROR_NONE)                                                     // Initialize clock chip
  {
    while(1);                                                                             // Loop forever if clock chip is not responding
  }

  clockgen.setupPLL(SI5351_PLL_A, 27, 332101, 390625);                                    // Set frequency to ( 25 MHz * (27 + 332101/390625) ...
  clockgen.setupMultisynth(0, SI5351_PLL_A, base_clock_factor,0,1);                       //  ... ) / 166 = 4.194304 MHz
  clockgen.enableOutputs(true);                                                           // Enable clock
}

void loop(void){
  if((clock_selection < 0) || (clock_selection > (array_length-1))){                      // If clock selection is outside range of array
    clock_selection = clock_default;                                                      // Reset clock selection
  }
  
  if((PINB&B00000010)==0){                                                                 // If P15 is low
    button_state = PINB;                                                                  // Store button states into this variable before P15 rises again    
    if((button_state&B00000010)==0){                                                       // Make sure P15 was captured, sometimes the delay between the previous two lines of code is too long and P15 rises back to 1
      if((button_state&B00010000)==0 && (button_state&B00001000) != 0){                   // If when P15 is polled, the start but not the select button is pressed
        debounce_count++;                                                                 // Increase debounce timer
        if(debounce_count > debounce_delay){                                              // Debounce timer for pressing start and select "simultaneously"
          select_pressed_first = 0;                                                       // Clear select flag if not already cleared
          start_pressed_first = 1;                                                        // Set start flag          
        }
      //Serial.println("Start pressed first!");
      }
      if((button_state&B00010000)!=0 && (button_state&B00001000) == 0){                   // If when P15 is polled, the select but not the start button is pressed
        debounce_count++;                                                                 // Increase debounce timer
        if(debounce_count > debounce_delay){                                              // Debounce timer for pressing start and select "simultaneously"
          start_pressed_first = 0;                                                        // Clear start flag if not already cleared
          select_pressed_first = 1;                                                       // Set select flag
        }
      //Serial.println("Select pressed first!");
      }
      if((button_state&B00010000)!=0 && (button_state&B00001000) != 0){                   // If when P15 is polled, neither start or select are pressed
        start_pressed_first = 0;                                                          // Reset flags back to 0
        select_pressed_first = 0;
        debounce_count = 0;                                                               // Reset debounce counter
        button_count = 0;                                                                 // Reset button hold timer
        disable_count = 0;                                                                // Reset disable timer counter
        able2disable_flag = 1;                                                            // Allow clock mod to mod clock
      //Serial.println("Buttons released!");
      }
      if((button_state&B00011000) == 0){                                                  // If both start and select are pressed
        //Serial.print("Both buttons pressed ");
        debounce_count = 0;                                                               // Reset debounce timer
        if(start_pressed_first == 0 && select_pressed_first == 0){                        // If neither start nor select were pressed first (aka, they were both pressed within the debounce timer interval)
          //Serial.print("at the same time");
          disable_count++;                                                                // Increment disable counter
          //Serial.print(disable_count,DEC);
          //Serial.println("");
          if((disable_count > base_disable_count) && able2disable_flag == 1){             // If the disable timer has passed the timeout, and you've let go of start+select from last time you disabled/enabled
            able2disable_flag = 0;                                                        // Prevent toggling of disabling/enabling
            if(disable_flag == 0){                                                        // If currently enabled...
              //digitalWrite(13,HIGH);
              disable_flag = 1;                                                           //  ... disable ...
              //Serial.println("Disabled");               
            }else{                                                                        //  ... otherwise ...
              //digitalWrite(13,LOW);
              disable_flag = 0;                                                           //  ... enable again
              //Serial.println("Enabled");
            }
            clock_selection = clock_default;                                              // Reset the clock selection variable to default
            clock_speed = base_clock_factor;                                              // Reset clock speed to default
            button_count = 0;                                                             // Reset button hold counter
            disable_count = 0;                                                            // Reset disable counter
            clockgen.enableOutputs(false);                                                // Pause clock output
            clockgen.setupPLL(SI5351_PLL_A, 27, 332101, 390625);                          // Set up PLL
            clockgen.setupMultisynth(0, SI5351_PLL_A, clock_speed,0,1);                   // Set up multiplier
            clockgen.enableOutputs(true);                                                 // Enable clock output
          }
        }else{
          disable_count = 0;                                                              // Reset disable counter
          button_count++;                                                                 // Increase button hold counter
          if(button_count > int(count_max[clock_selection])){                             // If counter has reached time limit
            if(start_pressed_first == 1){                                                 // If start was pressed first
              //Serial.print("Slow down!");
              //Serial.println("");
              if(clock_selection != (array_length-1)){                                    // Prevent increasing past array limit
                clock_selection++;                                                        // Increase clock speed setpoint
                //Serial.println(clock_selection,DEC);
                clock_speed = int(base_clock_factor*clock_speed_factor[clock_selection]); // Calculate new clock speed
                if(disable_flag == 0){                                                    // If clock changing is not disabled
                  clockgen.enableOutputs(false);                                          // Pause clock output
                  clockgen.setupPLL(SI5351_PLL_A, 27, 332101, 390625);                    // Set up PLL
                  clockgen.setupMultisynth(0, SI5351_PLL_A, clock_speed,0,1);             // Set up multiplier
                  clockgen.enableOutputs(true);                                           // Enable clock output
                  //Serial.println("Changed clock!");
                }else{
                  //Serial.println("Clock change is disabled!");
                }
              }
            }
            if(select_pressed_first == 1){                                                // If select was pressed first, do the same thing as above but slowing down instead
              //Serial.print("Speed up!");
              //Serial.println("");
              if(clock_selection != 0){  
                clock_selection--;
                //Serial.println(clock_selection,DEC);
                clock_speed = int(base_clock_factor*clock_speed_factor[clock_selection]); 
                if(disable_flag == 0){
                  clockgen.enableOutputs(false);
                  clockgen.setupPLL(SI5351_PLL_A, 27, 332101, 390625);
                  clockgen.setupMultisynth(0, SI5351_PLL_A, clock_speed,0,1);
                  clockgen.enableOutputs(true); 
                  //Serial.println("Changed clock!");
                }else{
                  //Serial.println("Clock change is disabled!");
                }
              }             
            }
            button_count = 0;                                                             // After changing the clock speed, reset the counter
            //Serial.println("Reset button counter");
          }
        }
      }else{
        disable_count = 0;                                                                // Reset disable counter
        //Serial.println("Reset disable counter");
      }
    }else{                                                                                // If P15 triggered the loop, but polling button states doesn't show P15 low (micro was too slow)
      //Serial.println("missed!");                                                        
    }
  }

  //Serial.println(clock_speed,DEC);

}
