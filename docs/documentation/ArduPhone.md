    Copyright (C) 2013 ZachWick <zach@zachwick.com>
    Permission is granted to copy, distribute, and/or modify
    this document under the terms of the GNU Free Documentation
    License, Version 1.3 or any later version published by the
    Free Software Foundation; with no Invariant Sections, no
    Front-Cover Texts, and no Back-Cover Texts. A copy of the
    license is included in the section entitled "GNU Free
    Documentation License".

    
    # Hardware
    
    ## Microcontroller

    This first version of ArduPhone is built around an Arduino
    Uno (R2 revision). 

    ## GPRS Chipset/Shield
    
    ArduPhone uses a GPRS Shield V1.0 sourced from Seeed Studio
    [http://www.seeedstudio.com/wiki/GPRS_Shield_V1.0]. This
    particular board is based on SIMCom's SIM900 Module has the
    following features:

    * Quad-Band 850 / 900/ 1800 / 1900 MHz
      * would work on GSM networks in all countries across the world.
    * Controlled via AT commands
      * Standard Commands: GSM 07.07 & 07.05
      * Enhanced Commands: SIMCOM AT Commands.
    * Short Message Service
      * so that you can send small amounts of data over the network
        * (ASCII or raw hexadecimal).
    * Embedded TCP/UDP stack
      * allows you to upload data to a web server.
    * Speaker and Headphone jacks
      * so that you can send DTMF signals or play recording like an answering machine.
    * SIM Card holder and GSM Antenna - present onboard.
    * 12 GPIOs, 2 PWMs and an ADC (all 2.8 volt logic)
      * most are just 'pass through' to your Arduino.
    * Low power consumption - 1.5mA(sleep mode)
    * Industrial Temperature Range
      * -40°C to +85 °C 

    Note that the pin mapping for 

    ## Keypad

    ## Display

    # Sofware
    
    
