/*Keyboard simulator
 * By Matt Stetson
 * stetson2@illinois.edu
 * Updated 9/8/2016 
 * Version 5.0.0 dev 1
 */
#include <Keyboard.h>
#include <Wire.h>

const int connectionLed = 13;
int k0;
int k1;

void setup() {
  pinMode(connectionLed, OUTPUT);
  
  Wire.begin(8);                //join i2c bus w address 8
  Wire.onReceive(receiveEvent); //register event
  Wire.onRequest(requestEvent); //called on request
  Serial.begin(9600);           //serial for debug
  Serial.println("Serial Monitor Connected.");
  Keyboard.begin();             //start keyboard
  delay(500);
}

void requestEvent() {
  byte connection = 1;
  Wire.beginTransmission(8);
  Wire.write(connection);
  Wire.endTransmission();
  Serial.println("connected");
  digitalWrite(connectionLed, HIGH);
}

void receiveEvent(int numBytes) {
  int k0 = Wire.read();
  int k1 = Wire.read();
  Serial.print(k0);
  Serial.print(k1);
/*
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
  if(k0 == 0) {
    switch(k1) {
      case 0:
			break;
		case 1:
			kEstop();
			break;
		case 2:
			kDispatch();
			break;
		case 3:
			kOpenGates();
			break;
		case 4:
			kCloseGates();
			break;
		case 5:
			kOpenRestraints();
			break;
		case 6:
			kCloseRestraints();
			break;
		case 7:
			kRaiseFloor();
			break;
		case 8:
			kLowerFloor();
			break;
		case 9:
			kLockFlyer();
			break;
    }
  }
  else if(k0 == 1) {
    if(k1 == 0) {
      kUnlockFlyer(); 
    }
    else {
      Serial.println("INVALID 1x");
    }
  }
  else {
    Serial.println("INVALID XX");
  }
}

void kEstop() {
	Keyboard.write(48);
	Serial.println("estop");
	//delay(50);
}
void kDispatch() {
	Keyboard.write(49);
	Serial.println("dispatch");
	//delay(50);
}
void kOpenGates() {
	Keyboard.write(52);
	Serial.println("open gates");
	//delay(50);
}  
void kCloseGates() {
	Keyboard.write(53);
	Serial.println("close gates");
	//delay(50);
}
void kOpenRestraints() {
	Keyboard.write(50);
	Serial.println("open restraints");
	//delay(50);
}
void kCloseRestraints() {
	Keyboard.write(51);
	Serial.println("close restraints");
	//delay(50);
}
void kRaiseFloor() {
	Keyboard.write(55);
	Serial.println("raise floor");
	//delay(50);
}
void kLowerFloor() {
	Keyboard.write(54);
	Serial.println("lower floor");
	//delay(50);
}
void kLockFlyer () {
	Keyboard.write(57);
	Serial.println("lock flyer");
	//delay(50);
}
void kUnlockFlyer() {
	Keyboard.write(56);
	Serial.println("unlock flyer");
	//delay(50);
}

void loop() {
//delay(50);
}
