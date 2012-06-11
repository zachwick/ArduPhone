// ArduPhone main program
//   Copyright 2012 Zach Wick
//   Dual licensed under the MIT License and the GPLv3 License
//      http://www.opensource.org/licenses/mit-license.php
//      http://www.opensource.org/licenses/GPL-3.0
//

#include "../ardu_phone_keypad.h"

// Global Variables
int dial_num[10] = {4,1,9,8,9,7,4,5,9};

void setup() {
   Serial.begin(9600);
   background(0);
   draw_buttons();
}

void loop() {
   gettouch(); // Start listening for touch events and store them in
               // mouseX and mouseY respectively
   // determine which box the touch event happened in
   //  and store the number in the dial_num array
   det_touch();
}
