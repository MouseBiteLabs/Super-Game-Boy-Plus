/*
  Super Game Boy Plus CLK3 — tap-control variant
  Based on MouseBiteLabs' SGB_Clock_Control_ATTINY.ino.

  SELECT held, tap START  : one step FASTER
  START held, tap SELECT : one step SLOWER
  Press START and SELECT together, hold ~2.5 s: reset clock to 1x.
  Clock adjustments remain enabled after reset.

  Compatible with the existing SGB+ ATtiny85 wiring. No fuse changes.
  Uses Adafruit_SI5351, just like the upstream sketch.

  Bench-test on your specific board before relying on it in play.
*/

#include <Arduino.h>
#include <Adafruit_SI5351.h>

Adafruit_SI5351 clockgen = Adafruit_SI5351();

// These are the original Si5351 multisynth integer dividers, ordered
// from slowest to fastest. 25 MHz * (27 + 332101/390625) / divider.
// (The upstream firmware uses integer truncation for 0.67 and 0.8.)
const uint16_t dividers[] = {332, 249, 207, 166, 132, 111, 83};
const uint8_t SPEED_COUNT = sizeof(dividers) / sizeof(dividers[0]);
const uint8_t DEFAULT_SPEED = 3;
uint8_t speedIndex = DEFAULT_SPEED;

// Game Boy SGB button lines as wired on the original SGB+:
// PB3 (physical pin 2) = SELECT, PB4 (physical pin 3) = START,
// PB1 (physical pin 6) = P15 button polling strobe.
const uint8_t SELECT_MASK = _BV(PB3);
const uint8_t START_MASK  = _BV(PB4);
const uint8_t P15_MASK    = _BV(PB1);

// Time-based debounce is evaluated on valid P15 samples, not on
// continuously polled GPIO (the button lines are multiplexed).
const uint16_t DEBOUNCE_MS = 25;
const uint16_t MODIFIER_ARM_MS = 120;
const uint16_t LOCK_HOLD_MS = 2500;

bool selectRaw = false, startRaw = false;
bool selectStable = false, startStable = false;
uint32_t selectRawSince = 0, startRawSince = 0;
uint32_t singleSince = 0, togetherSince = 0;
bool togetherCandidate = false;
bool lockActionUsed = false;

void applySpeed(uint8_t newSpeed) {
  if (newSpeed >= SPEED_COUNT) return;
  if (newSpeed == speedIndex) return;
  speedIndex = newSpeed;
  clockgen.enableOutputs(false);
  clockgen.setupPLL(SI5351_PLL_A, 27, 332101, 390625);
  clockgen.setupMultisynth(0, SI5351_PLL_A, dividers[speedIndex], 0, 1);
  clockgen.enableOutputs(true);
}

void debounceButton(bool sample, bool &raw, bool &stable,
                    uint32_t &since, uint32_t now) {
  if (sample != raw) {
    raw = sample;
    since = now;
  }
  if (stable != raw && (uint32_t)(now - since) >= DEBOUNCE_MS) {
    stable = raw;
  }
}

void setup() {
  pinMode(PB3, INPUT);
  pinMode(PB4, INPUT);
  pinMode(PB1, INPUT);

  if (clockgen.begin() != ERROR_NONE) {
    // Preserve the upstream fail-safe: no uncontrolled CLK0 output.
    while (true) { }
  }

  clockgen.setupPLL(SI5351_PLL_A, 27, 332101, 390625);
  clockgen.setupMultisynth(0, SI5351_PLL_A, dividers[DEFAULT_SPEED], 0, 1);
  clockgen.enableOutputs(true);
}

void loop() {
  // Sample only during the SGB's active-low button polling strobe.
  uint8_t pins = PINB;
  if ((pins & P15_MASK) != 0) return;
  pins = PINB;
  if ((pins & P15_MASK) != 0) return;

  uint32_t now = millis();
  bool wasSelect = selectStable;
  bool wasStart = startStable;
  debounceButton((pins & SELECT_MASK) == 0, selectRaw, selectStable,
                 selectRawSince, now);
  debounceButton((pins & START_MASK) == 0, startRaw, startStable,
                 startRawSince, now);

  const bool both = selectStable && startStable;
  const bool previouslyBoth = wasSelect && wasStart;

  if (!selectStable && !startStable) {
    togetherCandidate = false;
    lockActionUsed = false;
    return;
  }

  // Track the time a lone modifier is held; the second button must be
  // newly pressed after the modifier is established. No key auto-repeat.
  if (selectStable && !startStable) {
    if (!wasSelect || wasStart) singleSince = now;
    togetherCandidate = false;
    lockActionUsed = false;
    return;
  }
  if (startStable && !selectStable) {
    if (!wasStart || wasSelect) singleSince = now;
    togetherCandidate = false;
    lockActionUsed = false;
    return;
  }

  if (both && !previouslyBoth) {
    // A second button pressed almost immediately counts as a simultaneous
    // reset gesture; a second button pressed after the first has
    // been held long enough generates one speed step.
    bool heldSelectFirst = wasSelect && !wasStart;
    bool heldStartFirst = wasStart && !wasSelect;
    bool armed = (uint32_t)(now - singleSince) >= MODIFIER_ARM_MS;

    togetherCandidate = !armed || (!heldSelectFirst && !heldStartFirst);
    togetherSince = now;
    lockActionUsed = false;

    if (!togetherCandidate) {
      if (heldSelectFirst && speedIndex < SPEED_COUNT - 1) {
        applySpeed(speedIndex + 1);
      } else if (heldStartFirst && speedIndex > 0) {
        applySpeed(speedIndex - 1);
      }
    }
  }

  if (both && togetherCandidate && !lockActionUsed &&
      (uint32_t)(now - togetherSince) >= LOCK_HOLD_MS) {
    // Reset only; do not disable subsequent speed changes.
    applySpeed(DEFAULT_SPEED);
    lockActionUsed = true;
  }
}
