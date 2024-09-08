# MBC5 Variant

This board is for the MBC5 version.

## Board Characteristics and Order Information

Stuff.

## Bill of Materials (BOM)

### Group A Components (Required for Every Build)
| Reference | Value/Part Number     | Package             | Description             | Source                                                       |
| --------- | --------------------- | ------------------- | ----------------------- | ------------------------------------------------------------ |
| C1        | 0.01uF                | 0603                | Capacitor (MLCC)        | https://mou.sr/3AsRwK1                                       |
| C2        | 0.01uF                | 0603                | Capacitor (MLCC)        | https://mou.sr/3AsRwK1                                       |
| C3        | 0.01uF                | 0603                | Capacitor (MLCC)        | https://mou.sr/3AsRwK1                                       |
| C4        | 0.01uF                | 0603                | Capacitor (MLCC)        | https://mou.sr/3AsRwK1                                       |
| C5        | 0.01uF                | 0603                | Capacitor (MLCC)        | https://mou.sr/3AsRwK1                                       |
| C6        | 0.01uF                | 0603                | Capacitor (MLCC)        | https://mou.sr/3AsRwK1                                       |
| C7        | 22uF                  | 4mm x 5.5mm         | Capacitor (ALEL)        | https://mou.sr/4cVQXbO                                       |
| C8        | 4.7uF                 | 4mm x 5.5mm         | Capacitor (ALEL)        | https://mou.sr/4cRhEhW                                       |
| C9        | 4.7uF                 | 4mm x 5.5mm         | Capacitor (ALEL)        | https://mou.sr/4cRhEhW                                       |
| C10       | 0.1uF                 | 0603                | Capacitor (MLCC)        | https://mou.sr/3ENc15O                                       |
| C11       | 0.1uF                 | 0603                | Capacitor (MLCC)        | https://mou.sr/3ENc15O                                       |
| C13       | 10pF                  | 0603                | Capacitor (MLCC)        | https://mou.sr/3XA5J3N                                       |
| C14       | 10pF                  | 0603                | Capacitor (MLCC)        | https://mou.sr/3XA5J3N                                       |
| C15       | 33pF                  | 0603                | Capacitor (MLCC)        | https://mou.sr/4cYZLxw                                       |
| C16       | 51pF                  | 0603                | Capacitor (MLCC)        | https://mou.sr/3XjvPGV                                       |
| C17       | 51pF                  | 0603                | Capacitor (MLCC)        | https://mou.sr/3XjvPGV                                       |
| C18       | 0.01uF                | 0603                | Capacitor (MLCC)        | https://mou.sr/3AsRwK1                                       |
| R1        | 510k                  | 0603                | Resistor                | https://mou.sr/3zi8ayj                                       |
| R2        | 910                   | 0603                | Resistor                | https://mou.sr/4gj68i7                                       |
| R3        | 910                   | 0603                | Resistor                | https://mou.sr/4gj68i7                                       |
| R4        | 220                   | 0603                | Resistor                | https://mou.sr/3ARwrf3                                       |
| R5        | 220                   | 0603                | Resistor                | https://mou.sr/3ARwrf3                                       |
| R6        | 220                   | 0603                | Resistor                | https://mou.sr/3ARwrf3                                       |
| R7        | 510                   | 0603                | Resistor                | https://mou.sr/3IJHtni                                       |
| R8        | 10k                   | 0603                | Resistor                | https://mou.sr/3riR7IH                                       |
| R9        | 330                   | 0603                | Resistor                | https://mou.sr/3PWP8Ti                                       |
| R10       | 330                   | 0603                | Resistor                | https://mou.sr/3PWP8Ti                                       |
| R11       | 330                   | 0603                | Resistor                | https://mou.sr/3PWP8Ti                                       |
| R12       | 330                   | 0603                | Resistor                | https://mou.sr/3PWP8Ti                                       |
| R13       | 330                   | 0603                | Resistor                | https://mou.sr/3PWP8Ti                                       |
| R14       | 330                   | 0603                | Resistor                | https://mou.sr/3PWP8Ti                                       |
| R15       | 330                   | 0603                | Resistor                | https://mou.sr/3PWP8Ti                                       |
| R16       | 330                   | 0603                | Resistor                | https://mou.sr/3PWP8Ti                                       |
| R28       | 10k                   | 0603                | Resistor                | https://mou.sr/3riR7IH                                       |
| U1        | CPU SGB               | QFP-80              | Super Game Boy CPU      | Donor Super Game Boy                                         |
| U2        | ICD2                  | QFP-44              | SGB-SNES Interface Chip | Donor Super Game Boy                                         |
| U3        | LH52A64N / AS6C6264   | SOIC-28             | 64K SRAM                | Donor Super Game Boy / https://mou.sr/4cWBw3f                |
| U4        | LH52A64N / AS6C6264   | SOIC-28             | 64K SRAM                | Donor Super Game Boy / https://mou.sr/4cWBw3f                |
| U5        | SYS-SGB               | SOIC-32             | Mask ROM (SNES)         | Donor Super Game Boy                                         |
| U6        | CIC / PIC12F629       | SSOP-18 / SOIC-8    | Lockout Chip            | Donor Super Game Boy / https://mou.sr/4dSUh90                |

### Group B Components (For a Fixed 4.194304 MHz Clock)
| Reference | Value/Part Number     | Package             | Description             | Source                                                       |
| --------- | --------------------- | ------------------- | ----------------------- | ------------------------------------------------------------ |
| C23       | 27pF                  | 0603                | Capacitor (MLCC)        | https://mou.sr/3XiK3HJ                                       |
| C24       | 27pF                  | 0603                | Capacitor (MLCC)        | https://mou.sr/3XiK3HJ                                       |
| R18       | 1M                    | 0603                | Resistor                | https://mou.sr/3xhFdS3                                       |
| X1        | 4.194304 MHz          | HC-49/US            | Crystal Oscillator      | https://mou.sr/3yXaoDq                                       |

### Group C Components (For a Fixed 4.194304 MHz Clock, with Overclocking and Underclocking)
| Reference | Value/Part Number     | Package             | Description             | Source                                                       |
| --------- | --------------------- | ------------------- | ----------------------- | ------------------------------------------------------------ |
| C30       | 1uF                   | 0603                | Capacitor (MLCC)        | https://mou.sr/47lY3oP                                       |
| C31       | 0.1uF                 | 0603                | Capacitor (MLCC)        | https://mou.sr/3ENc15O                                       |
| C32       | 0.1uF                 | 0603                | Capacitor (MLCC)        | https://mou.sr/3ENc15O                                       |
| C33       | 0.1uF                 | 0603                | Capacitor (MLCC)        | https://mou.sr/3ENc15O                                       |
| Q1        | BSS138                | SOT-23              | MOSFET (N-ch)           | https://mou.sr/3TjlOs3                                       |
| Q2        | BSS138                | SOT-23              | MOSFET (N-ch)           | https://mou.sr/3TjlOs3                                       |
| SW1       | CAS-220A1             | A-type              | DPDT                    | https://mou.sr/4ewSJSb                                       |
| U11       | NCP161ASN330T1G       | SOT-23-5            | 3.3V Regulator          | https://mou.sr/3iqSHDt                                       |
| U12       | Si5351A-B-GT          | MSOP-10             | Clock Generator         | https://mou.sr/3Wyr1LG                                       |
| U13       | ATTINY85              | SOIC-8              | Microcontroller         | https://mou.sr/3OpMtBA                                       |
| X2        | 25.000 MHz            | 3.2mm x 2.5mm       | Crystal Oscillator      | https://mou.sr/3MAK5pD                                       |

### Group D Components (For Adding a Link Port)
| Reference | Value/Part Number     | Package                          | Description                 | Source                                                       |
| --------- | --------------------- | -------------------------------- | --------------------------- | ------------------------------------------------------------ |
| A1        | Link Adapter PCB v1.3 | N/A                              | Adapter circuit board       |                                                              |
| C25       | 100pF                 | 0603                             | Capacitor (MLCC)            | https://mou.sr/47fshd2                                       |
| C26       | 100pF                 | 0603                             | Capacitor (MLCC)            | https://mou.sr/47fshd2                                       |
| C27       | 100pF                 | 0603                             | Capacitor (MLCC)            | https://mou.sr/47fshd2                                       |
| C28       | 100pF                 | 0603                             | Capacitor (MLCC)            | https://mou.sr/47fshd2                                       |
| C29       | 0.01uF                | 0603                             | Capacitor (MLCC)            | https://mou.sr/3AsRwK1                                       |
| D1        | BAV99S                | SOT-363                          | Dual series diodes          | https://mou.sr/3X97NOE                                       |
| D2        | BAV99S                | SOT-363                          | Dual series diodes          | https://mou.sr/3X97NOE                                       |
| D3        | ES07D                 | SMF                              | Diode                       | https://mou.sr/3XdX1Xr                                       |
| J1        | 610106249121          | 2x3, 2.54mm spacing, right angle | Programming header          | https://mou.sr/3XygS4Z                                       |
| J2        | G800WC306018EU        | 1x2, 2.54mm spacing              | Header pins (structural)    | https://mou.sr/3yXak6E                                       |
| J3        | 2MM-HB-D03-VT-02-H-TB | 2x3, 2mm spacing                 | Header pins (link port PCB) | https://mou.sr/3TfU2wA                                       |
| P2        | Link Port             | 2x3, 2mm spacing                 | Link Port                   | https://tinyurl.com/m3y35e3z                                 |
| R19       | 220                   | 0603                             | Resistor                    | https://mou.sr/3ARwrf3                                       |
| R20       | 220                   | 0603                             | Resistor                    | https://mou.sr/3ARwrf3                                       |
| R21       | 220                   | 0603                             | Resistor                    | https://mou.sr/3ARwrf3                                       |
| R22       | 220                   | 0603                             | Resistor                    | https://mou.sr/3ARwrf3                                       |
| R23       | 10k                   | 0603                             | Resistor                    | https://mou.sr/3riR7IH                                       |
| R24       | 10k                   | 0603                             | Resistor                    | https://mou.sr/3riR7IH                                       |
| R25       | 10k                   | 0603                             | Resistor                    | https://mou.sr/3riR7IH                                       |
| R26       | 10k                   | 0603                             | Resistor                    | https://mou.sr/3riR7IH                                       |
| R27       | 10k                   | 0603                             | Resistor                    | https://mou.sr/3riR7IH                                       |

### Group E Components (For an Enhanced SGB Board)
| Reference | Value/Part Numbe  r     | Package                          | Description                 | Source                                                       |
| --------- | ----------------------- | -------------------------------- | --------------------------- | ------------------------------------------------------------ |
| P1        | Game Boy Cart Connector | N/A                              | SGB Game Boy Cart Connector | Donor Super Game Boy                                         |

### Group F Components (For a Single-Game SGB Board)
| Reference | Value/Part Number     | Package             | Description             | Source                                                       |
| --------- | --------------------- | ------------------- | ----------------------- | ------------------------------------------------------------ |
| C19       | 0.1uF                 | 0603                | Capacitor (MLCC)        | https://mou.sr/3ENc15O                                       |
| C20       | 0.1uF                 | 0603                | Capacitor (MLCC)        | https://mou.sr/3ENc15O                                       |
| C21       | 0.1uF                 | 0603                | Capacitor (MLCC)        | https://mou.sr/3ENc15O                                       |
| C22       | 0.1uF                 | 0603                | Capacitor (MLCC)        | https://mou.sr/3ENc15O                                       |
| R17       | 10k                   | 0603                | Resistor                | https://mou.sr/3riR7IH                                       |
| U7        | M29F160               | TSOP-48             | Flash EEPROM (Game Boy) | https://mou.sr/3N0a9eL                                       |
| U8        | MBC5                  | QFP-32              | MBC5 Mapper             | Donor Game Boy Game                                          |
| U9        | FM18W08-SG            | SOIC-28             | FRAM                    | https://mou.sr/4cRIJlb                                       |
| U10       | SN74LVC1G332          | SOT-363             | 3-input Or Gate         | https://mou.sr/3XdbXoN                                       |

### Other Components - Do Not Populate
| Reference | Value/Part Number     | Package             | Description             | Group | Source                                                       |
| --------- | --------------------- | ------------------- | ----------------------- | ----- | ------------------------------------------------------------ |
| C12       | 10pF (DNP)            | 0603                | Capacitor (MLCC)        | DNP   | https://mou.sr/3XA5J3N                                       |
