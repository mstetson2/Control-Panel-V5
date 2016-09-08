#include <Arduino.h>
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
		} else {
			if (!b1) {
				lampTestSerial(1);
			}
			lampTestAuto();
		}

		if (acknowledgePressed) {
			lampTestEnd();
		}
	} else {
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
		digitalWrite(acknowledgeLed, LOW);
	} else {
		digitalWrite(modeLed, LOW);
		digitalWrite(troubleLed, LOW);
		digitalWrite(estopLed, LOW);
		digitalWrite(ridestartLed, LOW);
		digitalWrite(ridestopLed, LOW);
		digitalWrite(restraintLed, LOW);
		digitalWrite(dispatchLLed, LOW);
		digitalWrite(dispatchRLed, LOW);
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
		} else {
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
	} else {
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
	} else {
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
	extraFunctionsChoosed = true;
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

	if (modeBypass) {
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
			} else {
				digitalWrite(ridestopLed, LOW);
			}
			if (ridestopPressed) {
				digitalWrite(ridestopLed, HIGH);
				i1 = true;
				if (!b4) {
					stopTestSerial(4);
				}
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
				} else {
					digitalWrite(estopLed, LOW);
				}
			}
			if (estopPressed) {
				if (!b6) {
					stopTestSerial(6);
				}
				if (m500) {
					digitalWrite(estopLed, HIGH);
				} else {
					digitalWrite(estopLed, LOW);
				}
				i3 = true;
			}
		}

		if (i3 && !estopPressed) {
			stopTestCompleted();
		}

	} else {
		lampsOff();
		b2 = false;
	}
}

void stopTestCompleted() {
	digitalWrite(estopLed, HIGH);
	i2 = true;
	if (m1000) {
		digitalWrite(acknowledgeLed, HIGH);
	} else {
		digitalWrite(acknowledgeLed, LOW);
	}
	if (acknowledgePressed) {
		stopTested = true;
		digitalWrite(acknowledgeLed, LOW);
		lampsOff();
		bFalse();
	}
	if (!b7) {
		stopTestSerial(7);
	}
}

//Extra functions is on functionsSelect.ino

void estopResetStartup() {

if(modeAuto) {
	digitalWrite(estopLed, HIGH);
	if(m1000) {
		digitalWrite(ridestartLed, HIGH);
	}
	else {
		digitalWrite(ridestartLed, LOW);
	}
}

}

void finalWarning() {

}
