#include <Arduino.h>

//OPS VARS:
boolean down;
boolean stop;
boolean rideStop;
boolean eStop;
boolean error;
int errorCode;

void operationsLoops() {
	setModeLed();
	stopListener();
	setPowerLed();
	if (!stop) {
		typeChecker();
		stopBlinker();
	} else {
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

void panelview(int line,int content) {
	int y = line - 1;
	int screen;
	String screenTitle[] = {
			"Startup",
			"Operations",
			"Error Status",
			"Messages",
			"Stops"};
	//LINE 1:
	writeView(y -1,screenTitle[screen]);



}

void writeView(int line, String content) {
	//lcd.setCursor;
}
