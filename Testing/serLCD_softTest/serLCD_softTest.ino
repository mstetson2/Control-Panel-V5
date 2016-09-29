#include <SoftwareSerial.h>

#define txPin 14

SoftwareSerial LCD = SoftwareSerial(0, 14);
// since the LCD does not send data back to the Arduino, we should only define the txPin
const int LCDdelay=10;  // conservative, 2 actually works

// wbp: goto with row & column
void lcdPosition(int row, int col) {
  LCD.write(0xFE);   //command flag
  LCD.write((col + row*64 + 128));    //position 
  delay(LCDdelay);
}
void clearLCD(){
  LCD.write(0xFE);   //command flag
  LCD.write(0x01);   //clear command.
  delay(LCDdelay);
}
void backlightOn() {  //turns on the backlight
  LCD.write(0x7C);   //command flag for backlight stuff
  LCD.write(157);    //light level.
  delay(LCDdelay);
}
void backlightOff(){  //turns off the backlight
  LCD.write(0x7C);   //command flag for backlight stuff
  LCD.write(128);     //light level for off.
   delay(LCDdelay);
}
void serCommand(){   //a general function to call the command flag for issuing all other commands   
  LCD.write(0xFE);
}

void setup()
{
  pinMode(txPin, OUTPUT);
  LCD.begin(9600);
  clearLCD();
  lcdPosition(0,0);
  LCD.print("Hello world!");

}

void loop()
{
    delay(1000);
  backlightOff();
  delay(1000);
  backlightOn();
  delay(2000);
  clearLCD();
  lcdPosition(0,0);
  LCD.print("STATUS 001: TURN PANEL KEY ON");
  delay(5000);
  lcdPosition(0,0);
  LCD.print("PANEL VERSION 1.0.0 BY MATT STETSON");
}
