#include <Arduino.h>

/*
 * Methods:
 * functionSelect();
 * function
 *
 *
 *   "FUNCTIONS MENU: (PAGE 1 OF 3); OPERATIONS FUNCTIONS",
      "LEAD/SUPERVISORS ONLY!", "PAGE 1A: LEAD-ACCESSABLE FUNCTIONS",
      "Press LOCK RESTRAINTS to toggle AUTOMATIC RESTRAINTS UNLOCK",
      "Press DISPATCH RIGHT to LIST CURRENT OPERATIONS SETTINGS",
      "For more options, switch GATES to OPEN",
      "PAGE 2A: SUPERVISOR-ACCESSABLE FUNCTIONS",
      "Press DISPATCH RIGHT for DISPATCH TOGGLE",
      "RESTRAINTS WILL NOW AUTOMATICALLY UNLOCK IN AUTOMATIC MODE!",
      "RESTRAINTS WILL NO LONGER AUTOMATICALLY UNLOCK! IN AUTOMATIC MODE",
      "SUPERVISOR MODE ENABLED!", "SUPERVISOR MODE DISABLED!"
 *
	* "Switch OPERATIONS TYPE to TYPE 1 and ENTRANCE GATES to CLOSED!",
	  "FUNCTIONS MENU:",
	  "PAGE 1 (AUTOMATIC MODE): OPERATIONS FUNCTIONS",
	  "PAGE 2 (MANUAL MODE): MAINTENANCE SETTINGS",
	  "PAGE 3 (BYPASS MODE): TROUBLESHOOTING & DEBUG MENU; ADVANCED ONLY!"
 *
 * "Switch to AUTOMATIC MODE to continue startup!",
      "PHASE I STARTUP: EXTRA FUNCTIONS; Configure panel",
      "PRESS ACKNOWLEDGE to continue startup!",
      "Press RIDE STOP to goto functions select screen!"
          "EXTRA FUNCTIONS BOOTED TXT!!"
 *
 */
boolean functionSelect;

void functionRequestHandler() {
	if(!booted) {
		if(functionSelect) {
			functionsPageSelect();
		}
		else {
			startupFunctionPrompt();
		}
	}
	else {
		if(functionSelect) {
			functionsPageSelect();
		}
	}
}

void startupFunctionPrompt() {
	//this method handles the user being able to choose to proceed
	//into the function menu or continue startup while starting up.
	//blinks ride start to continue, restraints for function (if function enabled)
	if(!b1) {
		Serial.println("Press Ride Start to continue startup");
		Serial.println("Press restraints for functions menu");
		b1 = true;
	}

	if(m1000) {
		digitalWrite(ridestartLed, LOW);
		if(functionEnabled) {
			digitalWrite(restraintLed, HIGH);
		}
	}
		else {
			digitalWrite(ridestartLed, HIGH);
			if(functionEnabled) {
				digitalWrite(restraintLed, LOW);
		}
	}

	if(functionEnabled) {
		if(restraintPressed) {
			functionSelect = true;
		}
		else {
			lampsOff();
		}
	}

}

void functionsPageSelect() {

	if (!m1000) {
		digitalWrite(acknowledgeLed, HIGH);
	} else {
		digitalWrite(acknowledgeLed, LOW);
	}

	if (acknowledgePressed) {
		functionSelect = false;
		functionSelectStartup = true;
		//extraFunctionsChoosing = false;
		bFalse();
		lampsOff();
		digitalWrite(acknowledgeLed, LOW);
	}

	if (modeAuto) {
		function1();
	}

	if (modeManual) {
		function2();
	}

	if (modeBypass) {
		function3();
	}

}

void functionsSelect() {

	if (!m1000) {
		digitalWrite(acknowledgeLed, HIGH);
	} else {
		digitalWrite(acknowledgeLed, LOW);
	}

	if (acknowledgePressed) {
		functionSelect = false;
		functionSelectStartup = true;
		//extraFunctionsChoosing = false;
		bFalse();
		lampsOff();
		digitalWrite(acknowledgeLed, LOW);
	}

	if (modeAuto) {
		function1();
	}

	if (modeManual) {
		function2();
	}

	if (modeBypass) {
		function3();
	}

}

void function1() {

	if (!f1) {
		functionPage1Serial(1);
	}

	if (!gatesOpen) {
		digitalWrite(ridestartLed, LOW);
		if (!f1a) {
			functionPage1Serial(11);
		}

		if (m1000) {
			digitalWrite(restraintLed, HIGH);
			digitalWrite(dispatchRLed, LOW);
		} else if (!rAutoUnlock) {
			digitalWrite(restraintLed, LOW);
			digitalWrite(dispatchRLed, HIGH);
		}

		if (restraintPressed) {
			if (!rAutoUnlock) {
				rAutoUnlock = true;
				digitalWrite(restraintLed, HIGH);
				functionPage1Serial(111);
			} else {
				rAutoUnlock = false;
				functionPage1Serial(112);
			}
			delay(1000);
		}

	} else {
		digitalWrite(restraintLed, LOW);
		digitalWrite(dispatchRLed, LOW);
		if (!f1b) {
			functionPage1Serial(12);
		}

		if (m1000) {
			digitalWrite(ridestartLed, HIGH);
		} else if (!supervisorMode) {
			digitalWrite(ridestartLed, LOW);
		}

		if (ridestartPressed) {
			if (!supervisorMode) {
				supervisorMode = true;
				digitalWrite(ridestartLed, HIGH);
				functionPage1Serial(121);
			} else {
				supervisorMode = false;
				functionPage1Serial(122);
			}
			delay(1000);
		}

	}

}

void function2() {

}

void function3() {

}

