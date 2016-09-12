#include <Arduino.h>

void setModeLed() {
	if (!modeAuto) {
		if (functionEnabled) {
			if (m250) {
				digitalWrite(modeLed, HIGH);
			} else {
				digitalWrite(modeLed, LOW);
			}
		} else {
			digitalWrite(modeLed, HIGH);
		}
	} else if (functionEnabled) {
		if (m500) {
			digitalWrite(modeLed, HIGH);
		} else {
			digitalWrite(modeLed, LOW);
		}
	} else {
		digitalWrite(modeLed, LOW);
	}
}

void restraints() {
	if (restraintPressed) {
		if (restraintsLocked) {
			restraintsLocked = false;
			digitalWrite(restraintLed, LOW);
			sT("Restraints unlocked");
			//send restraints
			delay(500);
		} else {
			restraintsLocked = true;
			digitalWrite(restraintLed, HIGH);
			sT("Restraints locked");
			//send lock
			delay(500);
		}
	}
}

void gates() {

}

void dispatchChecker() {

	if (mode = 1) {
		dispatchAutoChecker();
	} else if (mode = 2) {
		dispatchManualChecker();
	} else if (mode = 3) {
		dispatchBypassChecker();
	}

}

void dispatchAutoChecker() {

	if (!gatesOpen && restraintsLocked) {
		if (!singleDispatch) {
			if (dispatchLPressed && dispatchRPressed) {
				dispatch();
			} else {
				dispatching = false;
			}
		} else {
			if (dispatchRPressed) {
				dispatch();
			}
			dispatching = false;
		}
		if (m1000) {
			if (!singleDispatch) {
				digitalWrite(dispatchLLed, HIGH);
			}
			digitalWrite(dispatchRLed, HIGH);
		} else {
			if (!dispatching) {
				digitalWrite(dispatchLLed, LOW);
				digitalWrite(dispatchRLed, LOW);
			}
		}
	}
	if (rAutoUnlock) {
		autoUnlock();
	}

}

void dispatchManualChecker() {

}

void dispatchBypassChecker() {

}

void autoUnlock() {
	if (!dispatching && !autoUnlocked) {
		//send unlock
		digitalWrite(restraintLed, LOW);
		Serial.println("Restraints unlocked because train stopped.");
		autoUnlocked = true;
	}
}

void dispatch() {
	digitalWrite(dispatchRLed, HIGH);
	digitalWrite(dispatchLLed, LOW);
	//send dispatch keyboard
	dispatching = true;
	autoUnlocked = false;
}
