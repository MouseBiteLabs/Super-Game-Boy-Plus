# Super Game Boy Plus (SGB+) QOL/Bugfix Branch

[MouseBiteLabs](https://github.com/MouseBiteLabs) designed a neat retro hardware project, the [Super Game Boy Plus](https://github.com/MouseBiteLabs/Super-Game-Boy-Plus) that took the proprietary components from a Super Game Boy and allowed the user to not only install a 4.194MHz crystal to fix the timing issues the 4.295MHz clock from the SNES introduced, but also to allow the user to Over- and Under-clock the system at will using button presses.  I thought that was brilliant, but a few things stood out to me.

- First, I prefer to use an 8bitdo SN30 controller, and one of the things that this controller does is allow the user to turn it off by holding [START] for several seconds.  This conflicts with the SGB+ clock alteration function.
- Secondly, the length of time necessary to hold the buttons was flow-breaking; having to hold [SELECT], wait a second, and then hold [START] for another second was _annoying_.  Plus, the 'hold to fast-forward/rewind' thing is cute, but not really meaningful when you only have a couple of clockdivs one way or the other.
- Thirdly, there is a bug or oversight in the original firmware, where employing the Clock Reset function (holding both [SELECT] and [START] for 5 seconds resets the clock to baseline) causes that state to be persistent - use it, and you won't be able to alter clock timing until you power cycle the SGB+.

Neither of these first two are _critical issues_, but I think they can be much more user-friendly.  The third is definitely an annoyance.

In this fork, I've included the original project files, as well as **SGB_Clock_Control_Tap_ALTERED.ino**, which can be written to an ATTINY85 using an AVR-capable Arduino Uno (my recommendation is the r3 Uno; don't make the same mistake I did and grab the Uno Q - it's ARM-based and can't address ATTINY stuff as a programmer).

The chief differences in my **SGB_Clock_Control_Tap_ALTERED.ino** file:

- Over/Underclock done by holding [SELECT/START] and _tapping_ the other.
- Clock Reset timing reduced to 2500ms from 5000ms.
- Clock Reset no longer continuously triggers once activated; once Clock Reset occurs, it resets itself, allowing for as much time-based shenanigans as one would care.

- Full credit for the project, design, and the vast majority of the code go to [MouseBiteLabs](https://github.com/MouseBiteLabs); all I did was riff on his project and fix a few things to my liking.
