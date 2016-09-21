#include <Arduino.h>

boolean eStopHandled;
boolean rideStopHandled;
boolean rideStopBlink;
boolean keyboardStopSent;

int esrHoldCounter;
int startHoldCounter;

int stopDelay = 500;

void stopListener() {
	if (!panelOn) {
		eStop = true;
		stop = true;
		rideError(100);
		eStopHandled = true;
	}
	if (estopPressed) {
		eStop = true;
		stop = true;
	}
	if (ridestopPressed) {
		rideStop = true;
		rideStopBlink = true;
		stop = true;
	}
	if (error) {
		//stop = true;
	}
	if (eStop) {
		eStopController();
	}
	if (rideStop) {
		rideStopController();
	}
}

void eStopController() {
	if (!eStopHandled) {
		eStopHandle();
	}
	if (estopPressed) {
		digitalWrite(estopLed, HIGH);
	} else {
		if (m500) {
			digitalWrite(estopLed, LOW);
		} else {
			digitalWrite(estopLed, HIGH);
		}
	}
}
void eStopHandle() {
	lampsOff();
	digitalWrite(acknowledgeLed, LOW);
	digitalWrite(ridestopLed, HIGH);
	Serial.println("E-STOP PRESSED");
	rideError(150);
	if(!keyboardStopSent) {
		//TODO send keyboard e-stop
		keyboardStopSent = true;
	}

	eStopHandled = true;
}
void eStopResetHandle() {

	digitalWrite(ridestartLed, LOW);
	digitalWrite(estopLed, LOW);
	esrHoldCounter = 0;
	eStop = false;
	eStopHandled = false;
}

void rideStopController() {
	if (!rideStopHandled) {
		rideStopHandle();
	}
	if (rideStopBlink) {
		if (m500) {
			digitalWrite(ridestopLed, LOW);
		} else {
			digitalWrite(ridestopLed, HIGH);
		}
	}

}
void rideStopHandle() {
	lampsOff();
	digitalWrite(acknowledgeLed, LOW);
	digitalWrite(ridestartLed, LOW);
	Serial.println("RIDE STOP PRESSED");
	if(!keyboardStopSent) {
		//TODO send keyboard e-stop
		keyboardStopSent = true;
	}
	delay(stopDelay);
	rideStopHandled = true;
}
void rideStopResetHandle() {

	digitalWrite(ridestartLed, HIGH);
	startHoldCounter = 0;
	rideStop = false;
	rideStopBlink = false;
	stop = false;
	keyboardStopSent = false;
	rideStopBlink = false;
	//restraintsLocked = false;

	rideStopHandled = true;
	delay(500);
}



void stopReset() {

	if (eStop) {
		if (modeBypass) {
			lcdC();
			LCD.print("PRESS RIDE START");
			lcdN();
			LCD.print("TO ESR RESET");

			if (esrHoldCounter < 5) {
				//Serial.println(esrHoldCounter);
				if (ridestartPressed) {
					digitalWrite(ridestartLed, HIGH);
					esrHoldCounter++;
				} else {
					if (m500) {
						digitalWrite(ridestartLed, HIGH);
					} else {
						digitalWrite(ridestartLed, LOW);
					}
					esrHoldCounter = 0;
				}
			}
			else {
				eStopResetHandle();
			}

		} else {
			lcdC();
			LCD.print("E-STOP ACTIVE");
			lcdN();
			LCD.print("Switch to BYPASS!");
		}

	} else if (error) {
		if(modeManual) {
		error = false;
		}

	} else if (stop) {
		lcdC();
		LCD.print("PRESS RIDE START");
		//lcdN();
		//LCD.print("TO  RESET");

		if (startHoldCounter < 10) {
			//Serial.println(esrHoldCounter);
			if (ridestartPressed) {
				digitalWrite(ridestartLed, HIGH);
				startHoldCounter++;
			} else {
				if (m500) {
					digitalWrite(ridestartLed, HIGH);
				} else {
					digitalWrite(ridestartLed, LOW);
				}
				startHoldCounter = 0;
			}
		}
		else {
			rideStopResetHandle();
		}
	}

}

void stopBlinker() {
	digitalWrite(ridestartLed, HIGH);
	if (m1000) {
		digitalWrite(estopLed, LOW);
		digitalWrite(ridestopLed, LOW);
	} else {
		digitalWrite(estopLed, HIGH);
		digitalWrite(ridestopLed, HIGH);
	}
}

void setPowerLed() {
	if (panelOn) {
		digitalWrite(powerLed, HIGH);
		lcdC();
		LCD.print("STATUS: 000");
		lcdN();
		LCD.print("PANEL KEY OFF");
	} else {
		stop = true;
		eStop = true;
		lampsOff();
		digitalWrite(acknowledgeLed, LOW);
		if (m1000) {
			digitalWrite(powerLed, LOW);
		} else {
			digitalWrite(powerLed, HIGH);
		}
	}
}
