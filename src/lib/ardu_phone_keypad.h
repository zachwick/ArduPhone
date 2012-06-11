// TouchShield Slide as a phone dialer
//   Copyright 2012 Zach Wick
//   Dual licensed under the MIT License and the GPLv3 License
//      http://www.opensource.org/licenses/mit-license.php
//      http://www.opensource.org/licenses/GPL-3.0
//
//
//    Button Layout
//    ---------------------
//    | 1 | 2 | 3 | 4 | 5 |
//    ---------------------
//    | 6 | 7 | 8 | 9 | 0 |
//    ---------------------
//    | S | * | # | C | E |
//    ---------------------


void det_touch() {
  if (mouseX < 79) {
    if (mouseY < 70) { // Touch was above all buttons
      // ignore touches in this area
    } else if (mouseY < 128) { // in 1st row
      text("1",0,0);
    } else if (mouseY < 187) { // in 2nd row
      text("6",0,0);
    } else {                // in 3rd row
      text("S",0,0);
    }
  } else if (mouseX < 150) {
    if (mouseY < 70) { // Touch was above all buttons
      // ignore touches in this area
    } else if (mouseY < 128) { // in 1st row
      text("2",0,0);
    } else if (mouseY < 187) { // in 2nd row
      text("7",0,0);
    } else {                // in 3rd row
      text("*",0,0);
    }
  } else if (mouseX < 212) {
    if (mouseY < 70) { // Touch was above all buttons
      // ignore touches in this area
    } else if (mouseY < 128) { // in 1st row
      text("3",0,0);
    } else if (mouseY < 187) { // in 2nd row
      text("8",0,0);
    } else {                // in 3rd row
      text("#",0,0);
    }
  } else if (mouseX < 274) {
    if (mouseY < 70) { // Touch was above all buttons
      // ignore touches in this area
    } else if (mouseY < 128) { // in 1st row
      text("4",0,0);
    } else if (mouseY < 187) { // in 2nd row
      text("9",0,0);
    } else {                // in 3rd row
      text("C",0,0);
    }
  } else {
    if (mouseY < 70) { // Touch was above all buttons
      // ignore touches in this area
    } else if (mouseY < 128) { // in 1st row
      text("5",0,0);
    } else if (mouseY < 187) { // in 2nd row
      text("0",0,0);
    } else {                // in 3rd row
      text("E",0,0);
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


