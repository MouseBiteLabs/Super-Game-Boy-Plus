# Super Game Boy Cartridge

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

### Step 2: Choosing the Clock Type

#### Fixed Clock Speed

#### Clock Control With ATTINY85

#### Qwertymodo's Clock Mod

### Step 3: Adding a Link Port

### Step 4: Adding the Game Boy Components

## Game Controls

## Shell Trimming

Shell trimming.

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
