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
		digitalWrite(acknowledgeLed, LOW);
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
		digitalWrite(ridestopLed, HIGH);
		bFalse();
		digitalWrite(estopLed, HIGH);
		delay(1000);
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
	unsigned long currentMillis = millis();
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

			if (currentMillis - previousMillis > 1000) {
				previousMillis = currentMillis;

				if (acknowledgePressed) {
					digitalWrite(acknowledgeLed, HIGH);
					ackHold++;
				} else {
					ackHold = 0;
				}
			}

			if (ackHold == 2) {
				longStartupSerial(3);
				digitalWrite(acknowledgeLed, LOW);
				rideChecked = true;
			}

			if (m1000) {
				digitalWrite(acknowledgeLed, HIGH);
			} else {
				if (!acknowledgePressed) {
					digitalWrite(acknowledgeLed, LOW);
				}
			}

		} else {
			digitalWrite(acknowledgeLed, LOW);
			if (currentMillis - previousMillis > 1000) {
				previousMillis = currentMillis;

				if (ridestartPressed) {
					digitalWrite(ridestartLed, HIGH);
					startCount++;
				} else {
					startCount = 0;
				}
			}

			if (startCount == 10) {
				longStartupSerial(4);
				longWarningComplete();
			}

			if (m1000) {
				digitalWrite(ridestartLed, HIGH);
			} else {
				if (!ridestartPressed) {
					digitalWrite(ridestartLed, LOW);
				}
			}

			if (functionEnabled && !functionsSelected) {
				if (m1000) {
					digitalWrite(restraintLed, HIGH);
				} else {
					digitalWrite(restraintLed, LOW);
				}
				if (restraintPressed) {
					extraFunctionsChoosing = true;
				}

			}
		}
	} else {
		digitalWrite(acknowledgeLed, LOW);
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

	unsigned long currentMillis = millis();

	if (!b1) {
		esrStartupSerial(1);
		b1 = true;
	}

	if (modeAuto) {
		if (!b2) {
			esrStartupSerial(2);
			b2 = true;
		}
		if (currentMillis - previousMillis > 1000) {
			previousMillis = currentMillis;

			if (ridestartPressed) {
				digitalWrite(ridestartLed, HIGH);
				startCount++;
			} else {
				startCount = 0;
			}
		}

		if (startCount == 10) {
			esrStartupSerial(3);
			estopResetComplete();
		}

		if (m1000) {
			digitalWrite(ridestartLed, HIGH);
		} else {
			if (!ridestartPressed) {
				digitalWrite(ridestartLed, LOW);
			}
		}
	} else {
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

}

