#include <SoftwareSerial.h>
#define led 51
#define in 44
int buttonState = 0;
SoftwareSerial LCD = SoftwareSerial(0, 14);
const int LCDdelay = 2;

void setup() {
  // initialize digital pin led as an output.
  pinMode(led, OUTPUT);
  pinMode(52,OUTPUT);
  pinMode(53, OUTPUT);
  pinMode(in, INPUT);
  digitalWrite(in, HIGH);
  digitalWrite(53, HIGH);
  Serial.begin(9600);
  LCD.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  buttonState = digitalRead(in);
  test();
}
boolean isHeld;
boolean pSent;
unsigned long m;
void test() {

if(buttonState == LOW) {
  if(!pSent) {
    m = millis();
    Serial.println("PSENT");
    pSent = true;
  }
  isHeld = buttonHold(2000, m);
  if(isHeld) {
    digitalWrite(led, HIGH);
    digitalWrite(52,HIGH);
  }
  else
    digitalWrite(led, LOW);
}
  else {
    pSent = false;
    digitalWrite(led, LOW);
  }

  delay(100);
}

boolean buttonHold(long pressTime, unsigned long pHold) {
  boolean tHold;
  boolean dHold;
  unsigned long cHold = millis();
  Serial.println("bH");
  Serial.println(cHold);
  Serial.println(pHold);
  Serial.println(pressTime);
    if (cHold - pHold > pressTime) {
      return true;
      Serial.println("true");
    }
  return false;
  Serial.println("false");
}

void final() {



	if (ridestartPressed) {
		digitalWrite(ridestartLed, HIGH);
		if (!pSent) {
			m = millis();
			pSent = true;
		}
		isHeld = buttonHold(5000, m);
		if (isHeld) {
			//DO
		}
	} else {
		if (m500) {
			digitalWrite(ridestartLed, HIGH);
		} else {
			digitalWrite(ridestartLed, LOW);
		}
		pSent = false;
	}


finalStartupComplete();













}
