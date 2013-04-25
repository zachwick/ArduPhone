// ArduPhone main program for TouchShield Slide
//   Copyright 2012 Zach Wick
//   Dual licensed under the MIT License and the GPLv3 License
//      http://www.opensource.org/licenses/mit-license.php
//      http://www.opensource.org/licenses/GPL-3.0
//

#include <SoftwareSerial.h>

// Global Variables
int dial_num[10] = {4,1,9,8,9,7,4,5,9};
char* dialed_num[10];
int dialed_num_counter = 0;

void setup() {
   Serial.begin(9600);
   background(0);
   draw_buttons();
}

void loop() {
   char msgCharIn = 0;
   byte i = 0;
   char msgStrIn[32] = "";
   
   while(Serial.available()) {
     msgCharIn = Serial.read();
     msgStrIn[i] = msgCharIn;
     i += 1; 
   }
   
   gettouch(); // Start listening for touch events and store them in
               // mouseX and mouseY respectively
   // determine which box the touch event happened in
   //  and store the number in the dial_num array
   det_touch();
   delay(100);
}

void update_display(char* dispChar) {
  mouseX = 0;
  mouseY = 0;
  if (dispChar == "E") {
    for (int i=0;i<dialed_num_counter;i++) {
      dialed_num[i]=" ";
      text(" ",(8 * i),0); 
    }
    dialed_num_counter = 0;
  } else if (dispChar == "C") {
      text(" ",(8 * (dialed_num_counter - 1)),0);
      dialed_num_counter--;  
  } else if (dialed_num_counter < 10) {
    dialed_num[dialed_num_counter] = dispChar;
    text(dispChar,(8 * dialed_num_counter),0); 
    dialed_num_counter++;
  } else if (dialed_num_counter == 10 && dispChar == "S") {
    text("Send Call",88,0);
    delay(1000);
    for (int i=0;i<200;i++) {
      text(" ",i,0); 
    }
  }
}

void det_touch() {
  if (mouseX < 79) {
    if (mouseY < 70) { // Touch was above all buttons
      // ignore touches in this area
    } else if (mouseY < 128) { // in 1st row
      //text("1",0,0);
      update_display("1");
    } else if (mouseY < 187) { // in 2nd row
      //text("6",0,0);
      update_display("6");
    } else {                // in 3rd row
      //text("S",0,0);
      update_display("S");
    }
  } else if (mouseX < 150) {
    if (mouseY < 70) { // Touch was above all buttons
      // ignore touches in this area
    } else if (mouseY < 128) { // in 1st row
      //text("2",0,0);
      update_display("2");
    } else if (mouseY < 187) { // in 2nd row
      //text("7",0,0);
      update_display("7");
    } else {                // in 3rd row
      //text("*",0,0);
      update_display("*");
    }
  } else if (mouseX < 212) {
    if (mouseY < 70) { // Touch was above all buttons
      // ignore touches in this area
    } else if (mouseY < 128) { // in 1st row
      //text("3",0,0);
      update_display("3");
    } else if (mouseY < 187) { // in 2nd row
      //text("8",0,0);
      update_display("8");
    } else {                // in 3rd row
      //text("#",0,0);
      update_display("#");
    }
  } else if (mouseX < 274) {
    if (mouseY < 70) { // Touch was above all buttons
      // ignore touches in this area
    } else if (mouseY < 128) { // in 1st row
      //text("4",0,0);
      update_display("4");
    } else if (mouseY < 187) { // in 2nd row
      //text("9",0,0);
      update_display("9");
    } else {                // in 3rd row
      //text("C",0,0);
      update_display("C");
    }
  } else {
    if (mouseY < 70) { // Touch was above all buttons
      // ignore touches in this area
    } else if (mouseY < 128) { // in 1st row
      //text("5",0,0);
      update_display("5");
    } else if (mouseY < 187) { // in 2nd row
      //text("0",0,0);
      update_display("0");
    } else {                // in 3rd row
      //text("E",0,0);
      update_display("E");
    }
  } 
}

void draw_buttons() {
   fill(0);
   stroke(0,255,0);
   strokeWeight(1);
   for(int i=0;i<5;i++) {
      rect(7+(65*i),70,50,50);
      rect(7+(65*i),128,50,50);
      rect(7+(65*i),187,50,50); 
   }
   stroke(255,255,255);
   text("1",30,90);
   text("2",95,90);
   text("3",160,90);
   text("4",225,90);
   text("5",290,90);
   text("6",30,150);
   text("7",95,150);
   text("8",160,150);
   text("9",225,150);
   text("0",290,150);
   text("S",30,210);
   text("*",95,210);
   text("#",160,210);
   text("C",225,210);
   text("E",290,210);
}

