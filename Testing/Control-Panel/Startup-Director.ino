#include <Arduino.h>

int startMessage = 0;
boolean i1;
boolean i2;
boolean i3;

void booter() {
//blink estop during boot
	estopBlinkBoot();
	if (!preStarted) {
		bootCredits();
		delay(100);
		disclaimer();
		delay(100);
		bootSerial(1);
	} else {
		if (panelOn) {
			if (!s1) {
				bootSerial(2);
			}
			if (!lampTested) {
				lampTest();
			} else if (!stopTested) {
				stopTest();
			} else if (!longWarninged) {
				if (!functionSelectStartup) {
					functionRequestHandler();
				} else {
					longWarning();
				}
			} else if (!estopReseted) {
				estopResetStartup();
			} else if (!finalStarted) {
				finalStartup();
			} else {
				bootComplete();
			} //TODO error reset
		} else {
			digitalWrite(acknowledgeLed, LOW);
			lampsOff();
			s1 = false;
			s2 = false;
			s3 = false;
			s4 = false;
			s5 = false;
		}
	}
}

void bootComplete() {
	int con = wireConnect();
	if (con == 1)
		Serial.println("Keyboard Connected.");
	else
		Serial.println("Keyboard connection failed");

	kEstop();
	kCloseRestraints();
	kCloseGates();
	lcd.clear();
	lcd.print("STARTUP COMPLETE!");
	restraintsLocked = true;
	digitalWrite(restraintLed, HIGH);
	gatesLocked = true;
	booted = true;
}

//Sets the booleans for the serial to false
void bFalse() {
	b1 = false;
	b2 = false;
	b3 = false;
	b4 = false;
	b5 = false;
	b6 = false;
	b7 = false;
	b8 = false;
	b9 = false;
	b10 = false;

	i1 = false;
	i2 = false;
	i3 = false;
	delay(1000);
}

void estopBlinkBoot() {
//blinks estop until it is reset
	if (longWarninged) {
		if (ridestartPressed) {
			if (m250) {
				digitalWrite(estopLed, LOW);
			} else {
				digitalWrite(estopLed, HIGH);
			}
		} else {

			if (m1000) {
				digitalWrite(estopLed, LOW);
			} else {
				digitalWrite(estopLed, HIGH);
			}
		}
	}

	if (estopReseted) {
		if (m1000) {
			digitalWrite(ridestopLed, LOW);
		} else {
			digitalWrite(ridestopLed, HIGH);
		}
	}
}

