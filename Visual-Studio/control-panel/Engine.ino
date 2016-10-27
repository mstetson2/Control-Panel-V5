//MAIN:

#include <Arduino.h>

boolean m100;
boolean m250;
boolean m500;
boolean m1000;

long p100;
long p250;
long p500;
long p1000;
long pHold;

void buttonStates() {
	if (digitalRead(trouble_pressed) == LOW) {
		troublePressed = true;
	}
	else {
		troublePressed = false;

	}

	if (digitalRead(emergency_stop_notpressed) != LOW) {
		estopPressed = true;
	}
	else {
		estopPressed = false;
	}

	if (digitalRead(control_power_on) == LOW) {
		panelOn = true;
	}
	else {
		panelOn = false;
	}

	if (digitalRead(mode_auto_selected) == LOW) {
		modeAuto = true;
		modeManual = false;
		modeBypass = false;
		mode = 1;
	}
	else if (digitalRead(mode_bypass_selected) == LOW) {
		modeAuto = false;
		modeManual = false;
		modeBypass = true;
		mode = 3;
	}
	else if (digitalRead(mode_auto_selected) != LOW
		&& digitalRead(mode_bypass_selected) != LOW) {
		modeAuto = false;
		modeManual = true;
		modeBypass = false;
		mode = 2;
	}
	else {
		Serial.println("PROGRAMM ERROR: UNKNOWN MODE!!");
	}

	if (digitalRead(esr_reset_pressed) == LOW) {
		esrPressed = true;
	}
	else {
		esrPressed = false;
	}

	if (digitalRead(ride_start_pressed) == !LOW) {
		ridestartPressed = false;
	}
	else {
		ridestartPressed = true;
	}

	if (digitalRead(ride_stop_notpressed) != LOW) {
		ridestopPressed = true;
	}
	else {
		ridestopPressed = false;
	}

	if (digitalRead(function_enable_enabled) == LOW) {
		functionEnabled = true;
	}
	else {
		functionEnabled = false;
	}

	if (digitalRead(airgates_closed) == LOW) {
		gatesOpen = false;
	}
	else {
		gatesOpen = true;
	}

	if (digitalRead(hmi_pressed) == LOW) {
		hmiPressed = true;
	}
	else {
		hmiPressed = false;
	}

	if (digitalRead(ops_pressed) == LOW) {
		opsPressed = true;
	}
	else {
		opsPressed = false;
	}

	if (digitalRead(type_1_selected) == LOW) {
		typeOne = true;
		typeTwo = false;
		typeThree = false;
		type = 1;
	}
	else if (digitalRead(type_1_selected) != LOW
		&& digitalRead(type_3_selected) != LOW) {
		typeOne = false;
		typeTwo = true;
		typeThree = false;
		type = 2;
	}
	else if (digitalRead(type_3_selected) == LOW) {
		typeOne = false;
		typeTwo = false;
		typeThree = true;
		type = 3;
	}
	else {
		Serial.println(F("PROGRAMM ERROR: UNKNOWN TYPE!!"));
	}

	if (digitalRead(acknowledge_pressed) == LOW) {
		acknowledgePressed = true;
	}
	else {
		acknowledgePressed = false;
	}

	if (digitalRead(restraint_pressed) == LOW) {
		restraintPressed = true;
	}
	else {
		restraintPressed = false;
	}

	if (digitalRead(dispatch_l_pressed) == LOW) {
		dispatchLPressed = true;
	}
	else {
		dispatchLPressed = false;
	}

	if (digitalRead(dispatch_r_pressed) == LOW) {
		dispatchRPressed = true;
	}
	else {
		dispatchRPressed = false;
	}

	if ((dispatchLPressed && dispatchRPressed)
		|| (dispatchLPressed && singleDispatch)) {
		dispatchPressed = true;
	}
	else {
		if (!modeBypass) {
			dispatchPressed = false;
		}
	}
}


void blink100() {
	unsigned long c100 = millis();
	if (c100 - p100 > 100) {
		p100 = c100;
		if (m100 == false) {
			m100 = true;
		}
		else {
			m100 = false;
		}
	}
}
void blink250() {
	unsigned long c250 = millis();
	if (c250 - p250 > 250) {
		p250 = c250;
		if (m250 == false) {
			m250 = true;
		}
		else {
			m250 = false;
		}
	}
}
void blink500() {
	unsigned long c500 = millis();
	if (c500 - p500 > 500) {
		p500 = c500;
		if (m500 == false) {
			m500 = true;
		}
		else {
			m500 = false;
		}
	}
}
void blink1000() {
	unsigned long c1000 = millis();
	if (c1000 - p1000 > 1000) {
		p1000 = c1000;
		if (m1000 == false) {
			m1000 = true;
		}
		else {
			m1000 = false;
		}
	}
}

void lampsOff() {
	digitalWrite(dispatchLLed, LOW);
	digitalWrite(dispatchRLed, LOW);
	digitalWrite(estopLed, LOW);
	digitalWrite(ridestopLed, LOW);
	digitalWrite(ridestartLed, LOW);
	digitalWrite(restraintLed, LOW);
	digitalWrite(troubleLed, LOW);
	digitalWrite(modeLed, LOW);
	digitalWrite(opsLed, LOW);
	digitalWrite(esrLed, LOW);
}



void statusStack() {

}


//DEVICES:


// -- FOR WIRE COMMUNICATION -- //
int key;
int k0 = 0;
int k1 = 0;

int wireConnect() {
	int c;
	if (!connection) {
		//check connection
		Wire.requestFrom(8, 1);
		while (Wire.available()) {
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

void lp(int x, int y) {
	lcd.setCursor(x, y);
}
void ln(int y) {
	lcd.setCursor(0, y);
}

void l(String s, int y) {
	lcd.setCursor(0, y);
	lcd.print("                    ");
	lcd.setCursor(0, y);
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


//ENGINE LOOPS:

#include <Arduino.h>

void loopedVoids() {
	//ALWAYS:
	blink100();
	blink250();
	blink500();
	blink1000();
	buttonStates();

	//set which methods will be running depending on if booted or not
	if (booted == false) {
		booter();
	}
	else {
		//Operations
		operationsLoops();
	}
}

