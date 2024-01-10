#include <PicoGamepad.h>
#include "PluggableUSBHID.h"
#include <Bounce2.h>
PicoGamepad gamepad;



//SETTING BBOUNCE FOR EACH BBUTTON

const int numButtons = 8;
Bounce buttons[numButtons] = {
  Bounce(4, 10),
  Bounce(9, 10),
  Bounce(18, 10),
  Bounce(6, 10),
  Bounce(22, 10),
  Bounce(1, 10),
  Bounce(17, 10),
  Bounce(20, 10)
};


/*
Bounce button0 = Bounce(4, 10);
Bounce button1 = Bounce(9, 10);  // 10 = 10 ms debounce time
Bounce button2 = Bounce(18, 10);  // which is appropriate for
Bounce button3 = Bounce(6, 10);  // most mechanical pushbuttons
Bounce button4 = Bounce(22, 10);
Bounce button5 = Bounce(1, 10);
Bounce button6 = Bounce(17, 10);
Bounce button7 = Bounce(20, 10);
*/


void setup() {

  //START POINT BY BOARD
  Serial.begin(115200);
      //set hat to minimal so it is not giving any bugs to ingame experience 
     gamepad.SetHat(0,3);
  // Setting pins on the board for pull-up resistor method
  for (int i = 0; i < numButtons; i++) {
    pinMode(buttons[i].getPin(), INPUT_PULLUP);
  }

/*
//SETTING PINS ON BOARD FOR PULLUP RESISTOR METHOD
  pinMode(20,  INPUT_PULLUP);//ON BOARD -> 7
  pinMode(1, INPUT_PULLUP);//5
  pinMode(4, INPUT_PULLUP);//R
  pinMode(6, INPUT_PULLUP);//3
  pinMode(9, INPUT_PULLUP);//1
  pinMode(17, INPUT_PULLUP);//6
  pinMode(18, INPUT_PULLUP);//2
  pinMode(22, INPUT_PULLUP);//4
*/
 
}

void loop() {

  gamepad.send_update();

for (int i = 0; i < numButtons; i++) {
    buttons[i].update();

 /* button0.update();
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
*/

 if (buttons[i].fallingEdge()) {
      gamepad.SetButton(i, true);
      Serial.println("Button " + String(i) + " pressed");
    } else if (buttons[i].risingEdge()) {
      gamepad.SetButton(i, false);
      Serial.println("Button " + String(i) + " not pressed");
    }
  }
/*
  if (button0.fallingEdge()) {
    gamepad.SetButton(0, true);
    Serial.println("pressed");
  }

  // BUTTON IS NOT PRESSED (RISING EDGE)
  // GIVES 0 FOR OUTPUT
  else if (button0.risingEdge()) {
    gamepad.SetButton(0, false);
    Serial.println("not pressed");
  }
*/

}
