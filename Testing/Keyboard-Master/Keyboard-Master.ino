#include <Wire.h>

const int connectionLed = 13;
boolean connection;
int key;
int k0 = 0;
int k1 = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Serial Connected!");
  pinMode(connectionLed, OUTPUT);

}

void loop() {
  if(!connection) {
  wireConnect();
  }
}

void wireConnect() {
//check connection
Wire.requestFrom(8, 1);
    int c = Wire.read();
    Serial.print(c);
    if(c == 1) {
      Serial.println("Connected to Keyboard Simulator!");
      connection = true;
      digitalWrite(connectionLed, HIGH);
      delay(1000);
  }
}

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

void kClear() {
  k0=0;
  k1=0;
  Wire.beginTransmission(8); //clear
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission(); 
  delay(10);
}

void kEstop() {
  k0=0;
  k1=1;
  Wire.beginTransmission(8); //send keystroke
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission();    
  delay(10);
  k0=0;
  k1=0;
  Wire.beginTransmission(8); //clear
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission();    
  delay(10);
}

void kDispatch() {
  k0=0;
  k1=2;
  Wire.beginTransmission(8); //send keystroke
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission();    
  delay(10);
  k0=0;
  k1=0;
  Wire.beginTransmission(8); //clear
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission();  
  delay(10);
}

void kOpenGates() {
  k0=0;
  k1=3;
  Wire.beginTransmission(8); //send keystroke
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission();    
  delay(10);
  k0=0;
  k1=0;
  Wire.beginTransmission(8); //clear
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission(); 
  delay(10); 
}

void kCloseGates() {
  k0=0;
  k1=4;
  Wire.beginTransmission(8); //send keystroke
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission();    
  delay(10);
  k0=0;
  k1=0;
  Wire.beginTransmission(8); //clear
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission(); 
  delay(10);
}

void kOpenRestraints() {
  k0=0;
  k1=5;
  Wire.beginTransmission(8); //send keystroke
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission();    
  delay(10);
  k0=0;
  k1=0;
  Wire.beginTransmission(8); //clear
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission(); 
  delay(10);
}

void kCloseRestraints() {
  k0=0;
  k1=6;
  Wire.beginTransmission(8); //send keystroke
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission();    
  delay(10);
  k0=0;
  k1=0;
  Wire.beginTransmission(8); //clear
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission(); 
  delay(10);
}

void kRaiseFloor() {
  k0=0;
  k1=7;
  Wire.beginTransmission(8); //send keystroke
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission();    
  delay(10);
  k0=0;
  k1=0;
  Wire.beginTransmission(8); //clear
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission(); 
  delay(10);
}

void kLowerFloor() {
  k0=0;
  k1=8;
  Wire.beginTransmission(8); //send keystroke
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission();    
  delay(10);
  k0=0;
  k1=0;
  Wire.beginTransmission(8); //clear
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission(); 
  delay(10);
}

void kLockFlyer() {
  k0=0;
  k1=9;
  Wire.beginTransmission(8); //send keystroke
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission();    
  delay(10);
  k0=0;
  k1=0;
  Wire.beginTransmission(8); //clear
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission(); 
  delay(10);
}

void kUnlockFlyer() {
  k0=1;
  k1=0;
  Wire.beginTransmission(8); //send keystroke
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission();    
  delay(10);
  k0=0;
  k1=0;
  Wire.beginTransmission(8); //clear
  Wire.write(k0);
  Wire.write(k1);              
  Wire.endTransmission(); 
  delay(10);
}

   /* Serial.println("Keyboard loop");
    kEstop();
    delay(500);
    kDispatch();
    delay(500);
    kOpenGates();
    delay(500);
    kCloseGates();
    delay(500);
    kOpenRestraints();
    delay(500);
    kCloseRestraints();
    delay(500);
    kLowerFloor();
    delay(500);
    kRaiseFloor();
    delay(500);
    kLockFlyer();
    delay(500);
    kUnlockFlyer();
    delay(500);
    */
