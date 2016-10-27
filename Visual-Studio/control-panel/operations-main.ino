/*
	Contains controlling functions of panel while operating
*/

void operationsLoops() {
	setModeLed();
	stopListener();
	setPowerLed();
	if (!stop) {
		typeChecker();
		stopBlinker();
	}
	else {
		if (!estopPressed) {
			stopReset();
		}
	}
}

//sets the mode Led based on functionEnabled? and the mode
void setModeLed() {
	//has not been tested
	if (!modeAuto) {
		if (functionEnabled) {
			if (m250) {
				digitalWrite(modeLed, HIGH);
			}
			else {
				digitalWrite(modeLed, LOW);
			}
		}
		else {
			digitalWrite(modeLed, HIGH);
		}
	}
	else if (functionEnabled) {
		if (m500) {
			digitalWrite(modeLed, HIGH);
		}
		else {
			digitalWrite(modeLed, LOW);
		}
	}
	else {
		digitalWrite(modeLed, LOW);
	}
}
