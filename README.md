# Super Game Boy Cartridge

TODO: Cleanup, add links to Game Boy FRAM boards, add pictures where appropriate, add 3D files and Arduino code

The Super Game Boy (SGB) was a special cartridge for the Super Nintendo (SNES) that allowed you to play original Game Boy (DMG) games on your Super Nintendo... in **living color!** Some Game Boy games can even take advantage of enhancements provided by the SGB in ways you wouldn't see on a Game Boy, including custom color palettes, enhanced audio, and screen borders. *How does that strike you??*

<p align="center">
<a href="https://youtu.be/XTdGBMhjJ7U?si=7-TzK-MHGgorscUb&t=6"><img src="https://github.com/user-attachments/assets/8218cf10-ae3c-4039-b860-1824640ebbcc" alt="Brace yourself..." /></a> 
</p>

Unfortunately, the original Super Game Boy had one "major" flaw. The clock speed was 2.4% too fast. For most people, this makes no difference, but for *true gamers* it amounts to blasphemy. The side effect of this is that the Super Game Boy cannot use a link cable to connect with other Game Boys, since the clock speeds would be too dissimilar. Japan got the Super Game Boy 2, which fixed this oversight and added a link port. But everyone else never got it! Thus, true gamers got to work, and created mods that fix the <a href="https://www.qwertymodo.com/hardware-projects/snes/super-game-boy-clock-mod">clock speed</a> and <a href="https://www.qwertymodo.com/hardware-projects/snes/super-game-boy-link-port">add a link port</a>.

Another type of mod that has cropped up over the years <a href="https://www.timeextension.com/news/2023/08/classic-pokemon-games-get-ported-to-snes-by-industrious-fan">are standalone SNES games with a single Game Boy game inside.</a> This generally includes taking the PCB out of a Super Game Boy, taking the PCB out of a Game Boy game (hopefully a reproduction and not an original!), and permanently soldering the Game Boy PCB to the SGB board. A bit rough, but it gets the job done.

The thing about all these different SGB mods is that they consist of boards soldered together to an original SGB board. There hasn't been a single, clean, standalone board that incorporates all these features in a nice, sturdy package. Until now!

![image](https://github.com/user-attachments/assets/6aafdcf8-99e1-4d85-b303-5b412fd16936)

This Super Game Boy cartridge circuit board does the following:

- Allows for three separate clock options:
  1) the original "wrong" clock speed,
  2) the correct clock speed, or
  3) **the correct clock speed with the ability to overclock and underclock in-game**
- Incorporates the link port onto the board using a small daughter board to offset it into a perfect location on the edge of a standard SNES cartridge (if you are using an SGB2 shell, it will fit without the daughter board)
- Optionally allow you to lock the board to one specific Game Boy game instead of using the cartridge connector - save data can be transplanted to/from the cartridge via the FRAM chip
- Can be used in three different SNES shells with minimal shell trimming required:
  1) an original Super Game Boy shell with the cartridge connector,
  2) a standard 46-pin SNES shell (will require two cuts on the bottom of the shell for the extra cart edge pins), and
  3) a 60-pin SNES shell used for games that used enhancement chips like the SA-1 or SuperFX
 
There are two versions of the Super Game Boy board - one that can be used for standalone MBC3 games (in development), and one that can be used for standalone MBC5 games. If you only want a Super Game Boy without locking it to a single game, you can use *either* the MBC3 or MBC5 version to accomplish this - it does not matter which you pick. Because this project is highly customizable, you must carefully follow the instructions below to help guide you through the assembly process based on your desires. 

**PLEASE READ THIS GITHUB REPOSITORY IN IT'S ENTIRETY TO ENSURE YOU ASSEMBLE THE CARTRIDGE PROPERLY.**

All gerbers and source files can be found in this repo in the two folders linked above, as this project is fully open source.

## Important Things Before You Start

1) This project requires you remove some components from an original Super Game Boy cartridge. This will require a hot air rework station or a hot plate. This will also require extensive soldering capabilities - do not attempt this project if you do not have sufficient soldering experience.
2) If you are making a single game without the cartridge connector, you need to have an original Game Boy game that uses an MBC3 or MBC5 mapper chip, so you can remove it and use it on this board. <a href="https://catskull.net/gb-rom-database/">You can find a list of games and their mappers here</a>.
3) When soldering parts on, it's a good idea to put kapton tape or otherwise cover the bottom cartridge edge. You do not want to get solder on the cartridge contacts.
4) I am not responsible for any damage you do to your self or your property. Attempt this project at your own risk.
5) I do not guarantee design compatibility. You may encounter issues with certain games. There is also a chance I have made an error in the design or the BOM - if this is the case, I will do everything I can to address the problem as quickly as possible.
6) If you are using this board to make games other than for personal use, you must have permission from the originator to use and distribute any ROM images or other related material. You are responsible for making sure you adhere to any license requirements.

DO NOT use my circuit boards for profiting from stolen work - this especially includes homebrew content, ROM hacks, and using fan-made labels without permission from the originator. **Support ALL original creators!**

## Required Equipment

- You will need basic tools, like a soldering iron, hot plate, and/or hot air rework station.
- If you need the cartridge connector for an enhanced SGB build, <a href="https://hackaday.com/2017/04/03/have-you-ever-tried-desoldering-needles/">desoldering needles</a> may be helpful in removing it from the donor board.
- If you're making a single-game SGB cartridge, you will need a method of programming the ROM and FRAM (if desired). You *cannot* program the SGB cartridge with a cart programmer, like the OSCR. You need to solder pre-programmed chips.
  - In my opinion, the easiest way to do this if you have the equipment already is to make one of my FRAM-enabled Game Boy cartridges, and then transfer the ROM and FRAM chips over to the SGB board. You can use a variety of cart flashers, such as <a href="https://www.gbxcart.com/">GBxCart</a> and the <a href="https://github.com/sanni/cartreader">OSCR</a> to load the game and save data onto the catridge. Doing it this way, you can also test the game in a Game Boy before you move the chips over to make sure it's in working order.
  - Alternatively, the <a href="https://xgecu.myshopify.com/products/xgecu-new-t48-tl866-3gprogrammer-v12-01-support-28000-ics-for-spi-nor-nand-flash-emmc-bga153-162-169-100-221-tsop-sop-plcc">T48 programmer</a> with the <a href="https://xgecu.myshopify.com/products/100-original-xgecu-adp_f48_ex-1-tsop48-special-adapter-for-nor-flash-only-use-on-t48-tl866-3g-programmer">TSOP48 adapter</a> can program the ROM chip.
- If you want to add clock control options (overclocking/underclocking), you will need a way of programming an ATTINY85. My preferred method is to use an <a href="https://store-usa.arduino.cc/collections/boards-modules?filter.p.m.hardware_func.form_factor=Mega&filter.p.m.hardware_func.form_factor=Uno">Arduino Uno or Arduino Mega</a>, as I own those already. The instructions I provide will be using an Arduino to program the ATTINY. There are a multitude of other ways as well, but you will need to figure those out for yourself.

## Assembly Guide

To start off, here is a bird's-eye view of the process to populate one of these boards. Please follow this flowchart as you go. I *highly* recommend testing the board in a SNES after you solder the Group A components. This will help narrow down issues early on, before you start messing with things like overclocking.

<p align="center">
<img src="https://github.com/user-attachments/assets/6e62412a-c45b-475b-82bd-2eb3dc6275ab">
</p>

### Step 1: Getting the Boot Screen

First, populate the entire board with the Group A components. That's the majority of them. Also, solder the CLK1 solder pads on the back of the board to enable the SNES-driven clock just for testing. When you pop it into the SNES (obviously without a Game Boy game), you should see this screen:

![image](https://github.com/user-attachments/assets/c5493558-6dcc-4915-a2ab-207a86d31678)

If you've got that, then you know you at least got the essentials soldered properly. If you get the Game Boy border, but no cartridge error, then you have some kind of problem somewhere on the GB-side (like the SGB CPU, the ICD2, the RAM chips, etc). If you just get a black screen, then either the cartridge might not be making good contact with the SNES cartridge connector (or the cart connector is dirty), or you have some issue with the SNES-side components like the mask ROM or the CIC (if you're using the PIC12F629, make sure the SuperCIC code is programmed properly).

### Step 2: Choosing the Clock Generation Method

If you're not planning on fixing the clock speed, and keeping it at the incorrect 4.295 MHz frequency, then you don't have to do anything else for this step. Skip ahead to Step 3! Otherwise, read on.

Note that for all of these clock options, you can populate Group B and C components at the same time without causing any issues. The CLK pads on the back of the board will dictate which of these components have control over the clock generation, and they can't interfere with each other (as long as you only bridge one set of CLK pads).

#### Option 1: Fixed Clock Speed

This is the simplest clock modification, all you have to do is solder the few Group B components, desolder CLK1, and solder bridge CLK2. This will yield the proper clock speed of 4.194 MHz.

#### Option 2: Clock Control With ATTINY85

This one will take some work, because you will need to program the ATTINY85. You can do this before soldering, or after soldering if you use the ISP header pins. In either case, populate Group C components, desolder CLK1, and solder bridge CLK3 to set up the board for the clock generator.

In this section, I will briefly walk through how to program the ATTINY85 after it is soldered to the board, through the ISP header pins, with an Arduino Mega. If you are using a different method of programming, you will have to find instructions yourself.

<a href="https://www.instructables.com/How-to-Program-an-Attiny85-From-an-Arduino-Uno/">Here is detailed instructions for using an Arduino Uno to program an ATTINY85.</a> I haven't used them myself, but they look to be correct. I personally use a Mega to program my ATTINY chips; <a href="https://www.instructables.com/How-to-Burn-ATTiny85-Using-Arduino-Mega/">the detailed instructions can be found here for the Arduino Mega.</a> Follow those articles for the nitty-gritty, I will just give you the overview here that's more generic.

1. Program the host Arduino to be an ISP programmer. If using the Mega, follow the instructions in the link above to change the pin definitions in the ArduinoISP code to match the Mega instead of the Uno.
2. Put SW1 in PROG mode to allow programming of the ATTINY85.
3. Connect the Arduino pins to the ISP header as such:
  - Connect ISP pin 1 (PB1, PICO on the ATTINY85) to Arduino PICO pin (50 on Mega, 12 on Uno)
  - Connect ISP pin 2 (5V) to the Arduino 5V pin
  - Connect ISP pin 3 (PB2, SCK on the ATTINY85) to Arduino SCK pin (52 on Mega, 13 on Uno)
  - Connect ISP pin 4 (PB0, POCI on the ATTINY85) to Arduino POCI pin (51 on Mega, 11 on Uno)
  - Connect ISP pin 5 (RST, SS on the ATTINY85) to Arduino SS pin (53 on Mega, 10 on Uno)
  - Connect ISP pin 6 (GND) to the Arduino GND pin
4. Burn the bootloader to the ATTINY85. Make sure the processor is set to run on the internal 8 MHz clock, *not* an external clock.
5. Upload the Arduino sketch provided above onto the ATTINY85.
6. If it uploads correctly, unplug all the wires and switch SW1 to PLAY mode.

Remember, if you put the cartridge in your SNES and get a Game Boy border but *no blinking cartridge error* then that means there's an issue with the clock. You will know you did it right if you get the blinking error screen posted above.

#### Option 3: Qwertymodo's Clock Mod

If you don't want to deal with an ATTINY85, the board is fully compatible with <a href="https://www.qwertymodo.com/hardware-projects/snes/super-game-boy-clock-mod">qwertymodo's SGB clock mod</a>. The downside to this is that if you want to change the clock speed, you will still need to buy the Super Game Boy Commander controller from Hori... and those are *not* cheap. The main draw to qwertymodo's mod under normal circumstances is the clock speed is fixed, however since you can fix it pretty easily by soldering in the Group B components, the usefulness is a bit diminished. But in any case, it is still an option. All you have to do is follow the instructions on his site to install it, they apply to my SGB boards as well. Make sure the CLK1 pads remain bridged.

### Step 3: Adding a Link Port

Please note that if you want to add the link port, you *must* be using one of the clock options that fix the frequency (this also includes the overclocking option with the ATTINY85, as that defaults to 4.194 MHz). The link port *will not work* if your clock speed is the incorrect 4.295 MHz provided by the SNES.

Firstly, if for some reason you have a junked Japanese-only SGB2 cartridge with an in-tact shell (the blue one that has a cutout for the link port) then you only need to add the link port in the P1 socket. Again, though, the SGB2 is *not* compatible with this mod, so don't buy one as a donor, because you can't use it for parts.

![image](https://github.com/user-attachments/assets/f132504c-0d3e-40bc-96d1-7714e8759746)

*Image from gekkio's Game Boy Hardware Database.*

If you are NOT using an SGB2 shell, which I would guess you are not then you'll need to offset the link port from the board vertically to get it to fit in the shell nicely. You will also need to cut out a hole in the SNES shell, obviously.

![PXL_20240909_230033563](https://github.com/user-attachments/assets/a0dacca0-8620-4e23-83a0-5e94641303cf)

Getting the link port adapter board to sit level is a bit tricky. You also need to make sure the board is placed properly, and not flipped around. The way I do it is:
1) Solder the 2x3 headers (these have 2mm spacing instead of the standard 2.54mm spacing) into the link port adapter board. Make sure the headers are soldered onto the adapter board in such a way that it would be sandwiched between the main PCB and the adapter PCB.

![image](https://github.com/user-attachments/assets/f1d20f55-dddd-4446-8764-2213f4ebe09e)
 
2) Solder the 1x2 header (these have the standard 2.54mm spacing) onto the SGB board. You will also need to remove the black housing, as that is thicker than the housing on the 2x3 header (which is 1.5mm), so the board would be crooked if this was kept in. Use flush cutters or some other tool to carefully remove them without bending the pins.
3) Optional - place the 3D printed spacer I have linked above on top of the SGB board to help level the adapter board. If you don't have a 3D printer, you can use *another* link adapter board as a temporary shim (if you get them in the 1.6mm thickness) to achieve approximately the same effect.
4) With the adapter board placed on the main SGB board, finish soldering in the link adapter board.
5) Finally, solder the link port onto the adapter board, making sure it's placed in the right direction.

This is how it should look from the "topside" of the board. (Note that this picture does not include the 3D printed spacer.)

![PXL_20240909_231635987](https://github.com/user-attachments/assets/a18228a8-9b22-4338-a48d-6bd32c1ab675)

I detail shell trimming farther down.

### Step 4: Adding the Game Boy Components

If you're planning on retaining the cartridge connector in your build, then solder in the cartridge connector now! (The only Group E component)

If you're planning on locking the cartridge to a single game, then you have some more work to do. You need to program the M29F160 chip with the ROM of the game you want to make. You can do this in one of two ways:

1) With a standalone programmer like the <a href="https://xgecu.myshopify.com/products/xgecu-new-t48-tl866-3gprogrammer-v12-01-support-28000-ics-for-spi-nor-nand-flash-emmc-bga153-162-169-100-221-tsop-sop-plcc">T48 programmer</a> with the <a href="https://xgecu.myshopify.com/products/100-original-xgecu-adp_f48_ex-1-tsop48-special-adapter-for-nor-flash-only-use-on-t48-tl866-3g-programmer">TSOP48 adapter</a> - just place the chip in the adapter, load the ROM file in the programming software, and flash the chip

OR

2) Build a Game Boy cartridge that uses the M29F160 (like my boards), flash the game using a cart flasher like the <a href="https://www.gbxcart.com/">GBxCart</a> or the <a href="https://github.com/sanni/cartreader">OSCR</a>, then desolder the chips and move them over to the SGB board.

The upside to #2 is that you can test the game out in an actual Game Boy before transferring the chips over, and you can flash save data onto the FRAM if you have a game already started on a different cartridge you've dumped. So personally, I use method #2 if I can.

After you've programmed your ROM (and optionally FRAM) chip(s), then solder them to the board, along with the rest of the Group F components.

At this point - you've completed assembly of the cartridge.

## Shell Trimming

Shell trimming.

## Game Controls

Since this is a Super Game Boy... probably just good to look at the <a href="https://archive.org/details/nintendo-snes-super-game-boy/mode/2up">Super Game Boy manual</a> for all the controls that go with that.

Other than that - if you've installed the clock mod onto your board, this is how you control it if you use the code I provide. You only need to use the Start and Select buttons to change speeds. In the code, I have allocated space for seven different clock settings, and it starts at 1x by default (the correct 4.194 MHz clock speed). Note that each clock speed will affect the audio as well - it is not like Dodrio mode in Pokemon Stadium's GB Tower where the audio is unaffected. This means playing games can get... annoying at really high clock speeds.

The default clock multiplier settings are in order: 0.5x, 0.67x, 0.85x, 1x, 1.25x, 1.5x, 2x. A clock multiplier of 3x works, but produces a lot of graphical glitches. 4x and higher becomes unstable and will freeze the game.

- Speeding up: Press and hold Select first, wait a second, then also press and hold Start simultaneously (imitating a "fast forward" button)
- Slowing down: Press and hold Start first, wait a second, then also press and hold Select simultaneously (imitating a "rewind" button)
- Continuing to hold these two buttons down will continue up/down the list of clock multipliers in the code until it hits the maximum/minimum, with approximately a 2 second delay between switching

Maybe you are playing a game that requires you to press Start and Select for a while, and you don't want to trip the clock change. In that case you can reset clock speed to 1x and *disable* changing the clock. To do this:

- Press and hold both Start *and* Select at the same time and hold down for approximately 5 seconds.
- The clock speed will automatically move back to 1x. At this point, pressing Start/Select in the manner described above will not change the clock speed.
- To re-enable clock control, press and hold Start *and* Select at the same time and hold down for approximately 5 seconds. Then, you will be able to change clock settings based on the controls above.

## FAQ

**Q: Does this work with a DMG CPU instead of a SGB CPU?**

A: Unfortunately, no, but it would be really nice if you could.

**Q: Does this work with a SGB2 CPU instead of a SGB CPU?**

A: No, please do not destroy a SGB2 for this project!

**Q: Can you make one for me?**

A: No.

**Q: But what if I pay you?**

A: **NO.**

**Q: Can I make Game Boy Color games with this?**

A: No.

**Q: Can you make a board that lets you play Game Boy Color games on the SNES?**

A: No.

## Resources and Acknowledgements

- Gekkio
- Qwertymodo

## License

<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/80x15.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>. You are able to copy and redistribute the material in any medium or format, as well as remix, transform, or build upon the material for any purpose (even commercial) - but you **must** give appropriate credit, provide a link to the license, and indicate if any changes were made.

©MouseBiteLabs 2024
