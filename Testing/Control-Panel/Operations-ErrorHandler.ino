//TODO levels of severity cause different types of stops & blink speeds

#include <Arduino.h>

boolean errorHandled;
int errorSeverity;

void rideError(int e) {
	error = true;
	errorCode = e;
}

void errorController() {
	if (!errorHandled) {
		errorHandler();
	}
	if (m1000) {
		digitalWrite(troubleLed, HIGH);
	} else {
		digitalWrite(troubleLed, LOW);
	}
}
void errorHandler() {
	if (!stop) {
		lampsOff();
		digitalWrite(acknowledgeLed, LOW);
		stop = true;
	}
	lcdC();
	LCD.print("ERROR:       ");
	LCD.print(errorCode);
	errorHandled = true;
}
void errorView() {
	Serial.println("ERROR: ");
	Serial.print(errorCode);
	lcdC();
	LCD.print("ERROR:       ");
	LCD.print(errorCode);

	switch (errorCode) {
	case 050:
		Serial.println("COMM ERROR");
		break;
	case 070:
		Serial.println("INTERNAL ERROR. SEE DEBUG LOG");
		break;
	case 100:
		Serial.println("PANEL KEYED OFF");
		break;
	case 101:
		Serial.println("POWER Keyswitch was switched off.");
		break;
	case 110:
		Serial.println("Panel was inactive for too long. Timed out.");
		break;
	case 150:
		Serial.println("Main panel e-stop pressed!");
		break;
	default:
		Serial.println("NO ERROR");
		break;
	}

}
void errorReset() {
	boolean errorCleared;
	boolean errorDisplayed;
	if (modeManual) {
		if (!errorDisplayed) {
			errorView();
			errorDisplayed = true;
		}
		if (!errorCleared) {
			if (acknowledgePressed) {
				digitalWrite(acknowledgeLed, HIGH);
				errorCode = 000;
				Serial.println("Error Cleared. Press TROUBLE to reset.");
				errorCleared = true;
			} else {
				if (m1000) {
					digitalWrite(acknowledgeLed, LOW);
				} else {
					digitalWrite(acknowledgeLed, HIGH);
				}
			}
		} else {
			if (troublePressed) {
				errorClearHandle();
			}
			digitalWrite(acknowledgeLed, LOW);
		}
	} else {
		digitalWrite(acknowledgeLed, LOW);
		errorDisplayed = false;
	}
}
void errorClearHandle() {
	digitalWrite(troubleLed, LOW);
	Serial.println("Error Reset");
	errorCode = 000;
	error = false;
}

void errorListener() {
	//typeError();
	if (modeAuto) {
		//autoAcknowledge();
	}
}

/*
 void typeError() {
 boolean prevTypeInit;
 if (!prevTypeInit) {
 prevType = type;
 prevTypeInit = true;
 }
 if (prevType != type) {
 error = true;
 errorCode = 0;
 }

 }
 */
//ERROR CODES:
//0XX: SYSTEM ERROR (INTERNAL CONTROL SYSTEM)
//09X: CRITICAL SYSTEM ERROR
//1XX:
//2XX:
//3XX
//9XX:
