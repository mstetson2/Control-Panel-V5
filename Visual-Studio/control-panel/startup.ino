#include <Arduino.h>
/*
void startupTest() {
	Serial.print("test_start");
}
*/

//DIRECTOR:
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
	}
	else {
		if (panelOn) {
			if (!s1) {
				bootSerial(2);
			}
			if (!lampTested) {
				lampTest();
			}
			else if (!stopTested) {
				stopTest();
			}
			else if (!longWarninged) {
				if (!functionSelectStartup) {
					functionRequestHandler();
				}
				else {
					longWarning();
				}
			}
			else if (!estopReseted) {
				estopResetStartup();
			}
			else if (!finalStarted) {
				finalStartup();
			}
			else {
				bootComplete();
			} //TODO error reset
		}
		else {
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
			}
			else {
				digitalWrite(estopLed, HIGH);
			}
		}
		else {

			if (m1000) {
				digitalWrite(estopLed, LOW);
			}
			else {
				digitalWrite(estopLed, HIGH);
			}
		}
	}

	if (estopReseted) {
		if (m1000) {
			digitalWrite(ridestopLed, LOW);
		}
		else {
			digitalWrite(ridestopLed, HIGH);
		}
	}
}

//METHODS:

void lampTest() {
	//LAMP TEST:
	//MODE:AUTO
	//If function enable, different functions available
	if (modeAuto) {
		if (functionEnabled) {
			if (!b2) {
				lampTestSerial(2);
			}
			lampTestFunction();
		}
		else {
			if (!b1) {
				lampTestSerial(1);
			}
			lampTestAuto();
		}

		if (acknowledgePressed) {
			lampTestEnd();
		}
	}
	else {
		lampsOff();
		digitalWrite(acknowledgeLed, LOW);
	}
}
void lampTestAuto() {
	if (!m1000) {
		digitalWrite(modeLed, HIGH);
		digitalWrite(troubleLed, HIGH);
		digitalWrite(estopLed, HIGH);
		digitalWrite(ridestartLed, HIGH);
		digitalWrite(ridestopLed, HIGH);
		digitalWrite(restraintLed, HIGH);
		digitalWrite(dispatchLLed, HIGH);
		digitalWrite(dispatchRLed, HIGH);
		digitalWrite(opsLed, HIGH);
		digitalWrite(esrLed, HIGH);
		digitalWrite(acknowledgeLed, LOW);
	}
	else {
		digitalWrite(modeLed, LOW);
		digitalWrite(troubleLed, LOW);
		digitalWrite(estopLed, LOW);
		digitalWrite(ridestartLed, LOW);
		digitalWrite(ridestopLed, LOW);
		digitalWrite(restraintLed, LOW);
		digitalWrite(dispatchLLed, LOW);
		digitalWrite(dispatchRLed, LOW);
		digitalWrite(opsLed, LOW);
		digitalWrite(esrLed, LOW);
		digitalWrite(acknowledgeLed, HIGH);
	}
}
void lampTestFunction() {
	//RIDE STOP: Skip boot
	//Trouble Button: test horn
	if (!gatesOpen) {
		if (!m1000) {
			digitalWrite(modeLed, HIGH);
			digitalWrite(troubleLed, LOW);
			digitalWrite(estopLed, HIGH);
			digitalWrite(ridestartLed, LOW);
			digitalWrite(ridestopLed, LOW);
			digitalWrite(restraintLed, HIGH);
			digitalWrite(dispatchLLed, HIGH);
			digitalWrite(dispatchRLed, HIGH);
			digitalWrite(acknowledgeLed, LOW);
		}
		else {
			digitalWrite(modeLed, LOW);
			digitalWrite(troubleLed, HIGH);
			digitalWrite(estopLed, LOW);
			digitalWrite(ridestartLed, HIGH);
			digitalWrite(ridestopLed, HIGH);
			digitalWrite(restraintLed, LOW);
			digitalWrite(dispatchLLed, LOW);
			digitalWrite(dispatchRLed, LOW);
			digitalWrite(acknowledgeLed, HIGH);
		}
	}
	else {
		digitalWrite(modeLed, HIGH);
		digitalWrite(troubleLed, HIGH);
		digitalWrite(estopLed, HIGH);
		digitalWrite(ridestartLed, HIGH);
		digitalWrite(ridestopLed, HIGH);
		digitalWrite(restraintLed, HIGH);
		digitalWrite(dispatchLLed, HIGH);
		digitalWrite(dispatchRLed, HIGH);
	}
	if (ridestopPressed) {
		skipBoot();
	}
	if (troublePressed) {
		analogWrite(warning_horn, hornTone);
	}
	else {
		analogWrite(warning_horn, 0);
	}
	if (ridestartPressed) {
		debugM("Warning horn test");
	}
}
void skipBoot() {
	booted = true;
	lampTested = true;
	stopTested = true;
	functionSelectStartup = true;
	estopReseted = true;
	finalWarninged = true;
	lampsOff();

}
void lampTestEnd() {
	//turns off all leds,
	lampsOff();
	lampTested = true;
	digitalWrite(acknowledgeLed, LOW);
	lampTestSerial(3);
	bFalse();
}

void stopTest() {

	if (!b1) {
		stopTestSerial(1);
	}

	if (modeAuto) {
		if (!b2) {
			stopTestSerial(2);
		}
		//ridestopTested
		if (!i1) {
			if (!b3) {
				stopTestSerial(3);
			}
			if (m1000) {
				digitalWrite(ridestopLed, HIGH);
			}
			else {
				digitalWrite(ridestopLed, LOW);
			}
			if (ridestopPressed) {
				digitalWrite(ridestopLed, HIGH);
				if (!pSent) {
					m = millis();
					pSent = true;
				}
				isHeld = engine.buttonHold(1000, m);
				if (isHeld) {
					i1 = true;
					if (!b4) {
						stopTestSerial(4);
					}
				}
			}
			else {
				pSent = false;
			}
		}
		//estopTested
		else if (!i2) {
			if (!b5) {
				stopTestSerial(5);
			}
			if (!i3) {
				if (m1000) {
					digitalWrite(estopLed, HIGH);
				}
				else {
					digitalWrite(estopLed, LOW);
				}
			}
			if (estopPressed) {
				if (!b6) {
					stopTestSerial(6);
				}
				if (m500) {
					digitalWrite(estopLed, HIGH);
				}
				else {
					digitalWrite(estopLed, LOW);
				}
				i3 = true;
			}
		}

		if (i3 && !estopPressed) {
			stopTestCompleted();
		}

	}
	else {
		digitalWrite(acknowledgeLed, LOW);
		lampsOff();
		b2 = false;
	}
}
void stopTestCompleted() {
	digitalWrite(estopLed, HIGH);
	i2 = true;
	if (m1000 && !acknowledgePressed) {
		digitalWrite(acknowledgeLed, HIGH);
	}
	else {
		digitalWrite(acknowledgeLed, LOW);
	}
	if (acknowledgePressed) {
		digitalWrite(acknowledgeLed, HIGH);
		if (!pSent) {
			m = millis();
			pSent = true;
		}
		isHeld = engine.buttonHold(500, m);
		if (isHeld) {
			digitalWrite(acknowledgeLed, LOW);
			lampsOff();
			digitalWrite(ridestopLed, HIGH);
			bFalse();
			digitalWrite(estopLed, HIGH);
			stopTested = true;
			delay(1000);
		}
	}
	else {
		pSent = false;
	}
	if (!b7) {
		stopTestSerial(7);
	}
}

boolean rideChecked;
int ackHold;
int startCount = 0;
int previousMillis;
void longWarning() {
	digitalWrite(estopLed, HIGH);
	if (!b1) {
		longStartupSerial(1);
		b1 = true;
	}
	if (modeAuto) {
		if (!b2) {
			longStartupSerial(2);
			b2 = true;
		}
		if (!rideChecked) {
			if (acknowledgePressed) {
				digitalWrite(acknowledgeLed, HIGH);
				if (!pSent) {
					m = millis();
					pSent = true;
				}
				isHeld = engine.buttonHold(500, m);
				if (isHeld) {
					longStartupSerial(3);
					digitalWrite(acknowledgeLed, LOW);
					rideChecked = true;
				}
			}
			else {
				if (m1000) {
					digitalWrite(acknowledgeLed, HIGH);
				}
				else {
					digitalWrite(acknowledgeLed, LOW);
				}
				pSent = false;
			}
		}
		else {
			if (ridestartPressed) {
				digitalWrite(ridestartLed, HIGH);
				if (!pSent) {
					m = millis();
					pSent = true;
				}
				isHeld = engine.buttonHold(10000, m);
				if (isHeld) {
					longStartupSerial(4);
					longWarningComplete();
				}
			}
			else {
				if (m500) {
					digitalWrite(ridestartLed, HIGH);
				}
				else {
					digitalWrite(ridestartLed, LOW);
				}
				pSent = false;
			}
		}
	}
	else {
		lampsOff();
		b2 = false;
	}
}
void longWarningComplete() {
	lampsOff();
	digitalWrite(ridestartLed, LOW);
	bFalse();
	delay(1000);
	longWarninged = true;

}
//Extra functions is on functionsSelect.ino

void estopResetStartup() {

	if (!b1) {
		esrStartupSerial(1);
		b1 = true;
	}

	if (modeAuto) {
		if (!b2) {
			esrStartupSerial(2);
			b2 = true;
		}

		if (esrPressed) {
			digitalWrite(esrLed, HIGH);
			if (!pSent) {
				m = millis();
				pSent = true;
			}
			isHeld = engine.buttonHold(5000, m);
			if (isHeld) {
				esrStartupSerial(3);
				estopResetComplete();
			}
		}
		else {
			if (m250) {
				digitalWrite(esrLed, HIGH);
			}
			else {
				digitalWrite(esrLed, LOW);
			}
			pSent = false;
		}

	}
	else {
		lampsOff();
		b2 = false;
	}
}
void estopResetComplete() {
	estopReseted = true;
	startCount = 0;
	lampsOff();
	digitalWrite(ridestartLed, LOW);
	bFalse();
}

void finalStartup() {
	if (!b1) {
		finalStartupSerial(1);
		b1 = true;
	}

	if (modeAuto) {
		if (!b2) {
			finalStartupSerial(2);
			b2 = true;
		}

		if (ridestartPressed) {
			digitalWrite(ridestartLed, HIGH);
			if (!pSent) {
				m = millis();
				pSent = true;
			}
			isHeld = engine.buttonHold(3000, m);
			if (isHeld) {
				finalStartupSerial(3);
				finalStarted = true;
			}
		}
		else {
			if (m500) {
				digitalWrite(ridestartLed, HIGH);
			}
			else {
				digitalWrite(ridestartLed, LOW);
			}
			pSent = false;
		}

	}
	else {
		lampsOff();
		b2 = false;
	}
}
void finalStartupComplete() {
	finalStarted = true;
}

