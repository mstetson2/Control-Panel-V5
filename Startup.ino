#include <Arduino.h>

void booter() {
	estopBlinkBoot();
	if (!preStarted) {
		bootCredits();
		delay(500);
		disclaimer();
		delay(1000);
		bootSerial(1);
	} else {
		if (panelOn) {
			if (!s1) {
				bootSerial(2);
			}
			if (!lampTested) {
				lampTest();
			} else {
				if (!stopTested) {
					stopTest();
				} else {
					if (!extraFunctionsChoosed) {
						extraFunctionsChoose();
					} else {
						if(!functionsSelected) {
							functionsSelect();
						} else {
						if (!estopReseted) {
							estopResetStartup();
						} else {
							if (!finalWarninged) {
								finalWarning();
							} else {
								booted = true;
							}
						}
					}
					}
				}
			}
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
}

void estopBlinkBoot() {
	if(estopReseted) {
		if(m1000) {
			digitalWrite(estopLed, HIGH);
		}
		else {
			digitalWrite(estopLed, LOW);
		}
	}
}



