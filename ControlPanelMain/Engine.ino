#include <Arduino.h>

void buttonStates() {
	if (digitalRead(trouble_pressed) == LOW) {
		troublePressed = true;
	} else {
		troublePressed = false;

	}

	if (digitalRead(emergency_stop_notpressed) != LOW) {
		estopPressed = true;
	} else {
		estopPressed = false;
	}

	if (digitalRead(control_power_on) == LOW) {
		panelOn = true;
	} else {
		panelOn = false;
	}

	if (digitalRead(mode_auto_selected) == LOW) {
		modeAuto = true;
		modeManual = false;
		modeBypass = false;
		mode = 1;
	} else if (digitalRead(mode_bypass_selected) == LOW) {
		modeAuto = false;
		modeManual = false;
		modeBypass = true;
		mode = 3;
	} else if (digitalRead(mode_auto_selected) != LOW
			&& digitalRead(mode_bypass_selected) != LOW) {
		modeAuto = false;
		modeManual = true;
		modeBypass = false;
		mode = 2;
	} else {
		Serial.println("PROGRAMM ERROR: UNKNOWN MODE!!");
	}

	if (digitalRead(ride_start_pressed) == !LOW) {
		ridestartPressed = false;
	} else {
		ridestartPressed = true;
	}

	if (digitalRead(ride_stop_notpressed) != LOW) {
		ridestopPressed = true;
	} else {
		ridestopPressed = false;
	}

	if (digitalRead(function_enable_enabled) == LOW) {
		functionEnabled = true;
	} else {
		functionEnabled = false;
	}

	if (digitalRead(airgates_closed) == LOW) {
		gatesOpen = false;
	} else {
		gatesOpen = true;
	}

	if (digitalRead(type_1_selected) == LOW) {
		typeOne = true;
		typeTwo = false;
		typeThree = false;
		type = 1;
	} else if (digitalRead(type_1_selected) != LOW
			&& digitalRead(type_3_selected) != LOW) {
		typeOne = false;
		typeTwo = true;
		typeThree = false;
		type = 2;
	} else if (digitalRead(type_3_selected) == LOW) {
		typeOne = false;
		typeTwo = false;
		typeThree = true;
		type = 3;
	} else {
		Serial.println(F("PROGRAMM ERROR: UNKNOWN TYPE!!"));
	}

	if (digitalRead(acknowledge_pressed) == LOW) {
		acknowledgePressed = true;
	} else {
		acknowledgePressed = false;
	}

	if (digitalRead(restraint_pressed) == LOW) {
		restraintPressed = true;
	} else {
		restraintPressed = false;
	}

	if (digitalRead(dispatch_l_pressed) == LOW) {
		dispatchLPressed = true;
	} else {
		dispatchLPressed = false;
	}

	if (digitalRead(dispatch_r_pressed) == LOW) {
		dispatchRPressed = true;
	} else {
		dispatchRPressed = false;
	}

	if ((dispatchLPressed && dispatchRPressed)
			|| (dispatchLPressed && singleDispatch)) {
		dispatchPressed = true;
	} else {
		if (!modeBypass) {
			dispatchPressed = false;
		}
	}
}

void blink100() {
	unsigned long c100 = millis();
	if (c100 - p100 > 100) {
		p100 = c100;
		if (m100 == false) {
			m100 = true;
		} else {
			m100 = false;
		}
	}
}
void blink250() {
	unsigned long c250 = millis();
	if (c250 - p250 > 250) {
		p250 = c250;
		if (m250 == false) {
			m250 = true;
		} else {
			m250 = false;
		}
	}
}
void blink500() {
	unsigned long c500 = millis();
	if (c500 - p500 > 500) {
		p500 = c500;
		if (m500 == false) {
			m500 = true;
		} else {
			m500 = false;
		}
	}
}
void blink1000() {
	unsigned long c1000 = millis();
	if (c1000 - p1000 > 1000) {
		p1000 = c1000;
		if (m1000 == false) {
			m1000 = true;
		} else {
			m1000 = false;
		}
	}
}

void lampsOff() {
	digitalWrite(dispatchLLed, LOW);
	digitalWrite(dispatchRLed, LOW);
	digitalWrite(estopLed, LOW);
	digitalWrite(ridestopLed, LOW);
	digitalWrite(ridestartLed, LOW);
	digitalWrite(restraintLed, LOW);
	digitalWrite(troubleLed, LOW);
	digitalWrite(modeLed, LOW);
}
