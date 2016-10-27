// 
// 
// 

#include "keyboard_comm.h"

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

void keyboardCommunication::clear() {
	int k0 = 0;
	int k1 = 0;
	Wire.beginTransmission(8); //clear
	Wire.write(k0);
	Wire.write(k1);
	Wire.endTransmission();
	delay(10);
}

void keyboardCommunication::estop() {
	int k0 = 0;
	int k1 = 1;
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

void keyboardCommunication::dispatch() {
	int k0 = 0;
	int k1 = 2;
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

void keyboardCommunication::open_gates() {
	int k0 = 0;
	int k1 = 3;
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

void keyboardCommunication::close_gates() {
	int k0 = 0;
	int k1 = 4;
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

void keyboardCommunication::open_restraints() {
	int k0 = 0;
	int k1 = 5;
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

void keyboardCommunication::close_restraints() {
	int k0 = 0;
	int k1 = 6;
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

void keyboardCommunication::raise_floor() {
	int k0 = 0;
	int k1 = 7;
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

void keyboardCommunication::lower_floor() {
	int k0 = 0;
	int k1 = 8;
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

void keyboardCommunication::lock_flyer() {
	int k0 = 0;
	int k1 = 9;
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

void keyboardCommunication::unlock_flyer() {
	int k0 = 1;
	int k1 = 0;
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
