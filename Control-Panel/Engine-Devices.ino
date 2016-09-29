#include <Arduino.h>

// -- FOR WIRE COMMUNICATION -- //
int key;
int k0 = 0;
int k1 = 0;

int wireConnect() {
	int c;
	if (!connection) {
//check connection
		Wire.requestFrom(8, 1);
		while(Wire.available()) {
		c = Wire.read();
		}
		//Serial.print(c);
		if (c == 1) {
			Serial.println("Connected to Keyboard Simulator!");
			connection = true;
			delay(50);
			return 1;
		}
		else
			return 0;
	}
return 1;
}

/*  KEYBOARD CODES
 *  00 = CLEAR
 *  01 = ESTOP
 *  02 = DISPATCH
 *  03 = OPEN_GATES
 *  04 = CLOSE_GATES
 *  05 = OPEN_RESTRAINTS
 *  06 = CLOSE_RESTRAINTS
 *  07 = RAISE_FLOOR
 *  08 = LOWER_FLOOR
 *  09 = LOCK_FLYER
 *  10= UNLOCK_FLYER
 */

void kClear() {
	k0 = 0;
	k1 = 0;
	Wire.beginTransmission(8); //clear
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
}

void kEstop() {
	k0 = 0;
	k1 = 1;
	Wire.beginTransmission(8); //send keystroke
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
	k0 = 0;
	k1 = 0;
	Wire.beginTransmission(8); //clear
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
}

void kDispatch() {
	k0 = 0;
	k1 = 2;
	Wire.beginTransmission(8); //send keystroke
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
	k0 = 0;
	k1 = 0;
	Wire.beginTransmission(8); //clear
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
}

void kOpenGates() {
	k0 = 0;
	k1 = 3;
	Wire.beginTransmission(8); //send keystroke
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
	k0 = 0;
	k1 = 0;
	Wire.beginTransmission(8); //clear
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
}

void kCloseGates() {
	k0 = 0;
	k1 = 4;
	Wire.beginTransmission(8); //send keystroke
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
	k0 = 0;
	k1 = 0;
	Wire.beginTransmission(8); //clear
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
}

void kOpenRestraints() {
	k0 = 0;
	k1 = 5;
	Wire.beginTransmission(8); //send keystroke
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
	k0 = 0;
	k1 = 0;
	Wire.beginTransmission(8); //clear
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
}

void kCloseRestraints() {
	k0 = 0;
	k1 = 6;
	Wire.beginTransmission(8); //send keystroke
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
	k0 = 0;
	k1 = 0;
	Wire.beginTransmission(8); //clear
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
}

void kRaiseFloor() {
	k0 = 0;
	k1 = 7;
	Wire.beginTransmission(8); //send keystroke
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
	k0 = 0;
	k1 = 0;
	Wire.beginTransmission(8); //clear
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
}

void kLowerFloor() {
	k0 = 0;
	k1 = 8;
	Wire.beginTransmission(8); //send keystroke
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
	k0 = 0;
	k1 = 0;
	Wire.beginTransmission(8); //clear
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
}

void kLockFlyer() {
	k0 = 0;
	k1 = 9;
	Wire.beginTransmission(8); //send keystroke
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
	k0 = 0;
	k1 = 0;
	Wire.beginTransmission(8); //clear
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
}

void kUnlockFlyer() {
	k0 = 1;
	k1 = 0;
	Wire.beginTransmission(8); //send keystroke
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
	k0 = 0;
	k1 = 0;
	Wire.beginTransmission(8); //clear
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
}

//-- //

void lp(int x,int y) {
	lcd.setCursor(x,y);
}
void ln(int y) {
	lcd.setCursor(0,y);
}

void l(String s, int y) {
	lcd.setCursor(0,y);
	lcd.print("                    ");
	lcd.setCursor(0,y);
	lcd.print(s);
}

// -- FOR LCD SCREEN (16x2) -- //
void lcdPosition(int row, int col) {
	LCD.write(0xFE);   //command flag
	LCD.write((col + row * 64 + 128));    //position
	delay(LCDdelay);
}
void lcdC() {
	LCD.write(0xFE);   //command flag
	LCD.write(0x01);   //clear command.
	lcdPosition(0, 0);
	delay(LCDdelay);
}
void backlightOn() {  //turns on the backlight
	LCD.write(0x7C);   //command flag for backlight stuff
	LCD.write(157);    //light level.
	delay(LCDdelay);
}
void backlightOff() {  //turns off the backlight
	LCD.write(0x7C);   //command flag for backlight stuff
	LCD.write(128);     //light level for off.
	delay(LCDdelay);
}
void serCommand() { //a general function to call the command flag for issuing all other commands
	LCD.write(0xFE);
}

void lcdN() {
	lcdPosition(1, 0);
}
// ---- //
