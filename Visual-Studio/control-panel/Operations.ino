char slant[] = { "/////////////////////////////////////////////" };
char vert[] = { "|||||||||||||||||||||||||||||||||||||||||||" };
String space = "";
String debug = "DEBUG: ";
int bM;
int ltM;
int stM;
boolean preStarted;
boolean startInitMessage;
boolean s1;
boolean s2;
boolean s3;
boolean s4;
boolean s5;
boolean b1;
boolean b2;
boolean b3;
boolean b4;
boolean b5;
boolean b6;
boolean b7;
boolean b8;
boolean b9;
boolean b10;
boolean f1;
boolean f1a;
boolean f1b;
boolean f2;
boolean f2a;
boolean f2b;
boolean f3;
boolean f3a;
boolean f3b;




void panelview(int line, int content) {
	int y = line - 1;
	int screen;
	String screenTitle[] = {
		"Startup",
		"Operations",
		"Error Status",
		"Messages",
		"Stops" };
	//LINE 1:
	writeView(y - 1, screenTitle[screen]);



}

void writeView(int line, String content) {
	//lcd.setCursor;
}

//OPERATIONS DIRECTOR::

void typeChecker() {
	if (typeOne) {
		modeCheck1();
	}
	else if (typeTwo) {
		//modeCheck2();
	}
	else if (typeThree) {
		//modeCheck3();
	}
	else {
		debugM("UNKNOWN MODE");
	}
}

void dispatchReadyCheck() {

	if (type == 1) {
		if (gatesLocked && restraintsLocked) {
			dispatchReady = true;
		}
		else {
			dispatchReady = false;
		}
	}
	else if (type == 2) {
		if (gatesLocked && restraintsLocked) {
			dispatchReady = true;
			if (floorDown) {
				dispatchClear = true;
			}
		}
		else {
			dispatchReady = false;
			dispatchClear = false;
		}
	}
	else if (type == 3) {
		if (gatesLocked && restraintsLocked) {
			dispatchReady = true;
			if (flyerLocked) {
				dispatchClear = true;
			}
		}
		else {
			dispatchReady = false;
			dispatchClear = false;
		}
	}
}
void dispatchIsReady() {
	if (dispatchReady) {
		if (m100) {
			digitalWrite(dispatchLLed, HIGH);
			digitalWrite(dispatchRLed, HIGH);
		}
		else {
			digitalWrite(dispatchLLed, LOW);
			digitalWrite(dispatchRLed, LOW);
		}
		if (dispatchPressed) {
			dispatch();
		}
	}
	else {
		digitalWrite(dispatchLLed, LOW);
		digitalWrite(dispatchRLed, LOW);
	}
}
void dispatch() {
	if (!dispatching) {
		digitalWrite(dispatchRLed, HIGH);
		digitalWrite(dispatchLLed, HIGH);
		digitalWrite(restraintLed, LOW);
		kDispatch();
		lcdC();
		LCD.print("STATUS 100:");
		lcdN();
		LCD.print("DISPATCHING!");
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print("STATUS 100: ");
		lcd.setCursor(0, 1);
		lcd.print("DISPATCHING!");
		dispatching = true;
	}
}

void airgates() {
	if (gatesOpen) {
		if (gatesLocked) {
			kOpenGates();
			gatesLocked = false;
			lcdPosition(0, 0);
			LCD.print("AIRGATES:  OPEN!");
		}
	}
	else {
		if (!gatesLocked) {
			kCloseGates();
			lcdPosition(0, 0);
			LCD.print("AIRGATES:    OK!");
			gatesLocked = true;
		}
	}
}

void restraints() {
	if (restraintPressed) {
		if (restraintD) {
			restraintD = false;
			if (restraintsLocked) {
				restraintsLocked = false;
				kOpenRestraints();
				digitalWrite(restraintLed, LOW);
				sT("Restraints unlocked");
				lcdN();
				LCD.print("RESTRAINTS: OPEN");
				//TODO send restraints open
				delay(100);
			}
			else {
				restraintsLocked = true;
				kCloseRestraints();
				digitalWrite(restraintLed, HIGH);
				sT("Restraints locked");
				lcdN();
				LCD.print("RESTRAINTS:  OK!");
				//TODO send lock
				delay(100);
			}
		}
	}
	else {
		restraintD = true;
	}
}
void autoUnlock() {
	//TODO send unlock
	restraintsLocked = false;
	digitalWrite(restraintLed, LOW);
	Serial.println("Restraints unlocked because train stopped.");
	kOpenRestraints();
	lcdN();
	LCD.print("RESTRAINTS: OPEN");
}

//OPERATIONS ERROR HANDLER:

//TODO levels of severity cause different types of stops & blink speeds

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
	}
	else {
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
			}
			else {
				if (m1000) {
					digitalWrite(acknowledgeLed, LOW);
				}
				else {
					digitalWrite(acknowledgeLed, HIGH);
				}
			}
		}
		else {
			if (troublePressed) {
				errorClearHandle();
			}
			digitalWrite(acknowledgeLed, LOW);
		}
	}
	else {
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


//OPERATIONS FUNCTIONS::

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
	if (!booted) {
		if (functionSelect) {
			functionsPageSelect();
		}
		else {
			startupFunctionPrompt();
		}
	}
	else {
		if (functionSelect) {
			functionsPageSelect();
		}
	}
}

void startupFunctionPrompt() {
	//this method handles the user being able to choose to proceed
	//into the function menu or continue startup while starting up.
	//blinks ride start to continue, restraints for function (if function enabled)
	if (!b1) {
		Serial.println("Press Ride Start to continue startup");
		Serial.println("Press restraints for functions menu");
		b1 = true;
	}

	if (m1000) {
		digitalWrite(ridestartLed, LOW);
		if (functionEnabled) {
			digitalWrite(restraintLed, HIGH);
		}
	}
	else {
		digitalWrite(ridestartLed, HIGH);
		if (functionEnabled) {
			digitalWrite(restraintLed, LOW);
		}
	}

	if (functionEnabled) {
		if (restraintPressed) {
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
	}
	else {
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
	}
	else {
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
		}
		else if (!rAutoUnlock) {
			digitalWrite(restraintLed, LOW);
			digitalWrite(dispatchRLed, HIGH);
		}

		if (restraintPressed) {
			if (!rAutoUnlock) {
				rAutoUnlock = true;
				digitalWrite(restraintLed, HIGH);
				functionPage1Serial(111);
			}
			else {
				rAutoUnlock = false;
				functionPage1Serial(112);
			}
			delay(1000);
		}

	}
	else {
		digitalWrite(restraintLed, LOW);
		digitalWrite(dispatchRLed, LOW);
		if (!f1b) {
			functionPage1Serial(12);
		}

		if (m1000) {
			digitalWrite(ridestartLed, HIGH);
		}
		else if (!supervisorMode) {
			digitalWrite(ridestartLed, LOW);
		}

		if (ridestartPressed) {
			if (!supervisorMode) {
				supervisorMode = true;
				digitalWrite(ridestartLed, HIGH);
				functionPage1Serial(121);
			}
			else {
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

//OPERATIONS STOP HANDLER

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
		errorController();
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
	}
	else {
		if (m500) {
			digitalWrite(estopLed, LOW);
		}
		else {
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
	if (!keyboardStopSent) {
		//TODO send keyboard e-stop
		kEstop();
		keyboardStopSent = true;
	}

	eStopHandled = true;
}
void eStopResetHandle() {

	digitalWrite(esrLed, LOW);
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
		}
		else {
			digitalWrite(ridestopLed, HIGH);
		}
	}
}
void rideStopHandle() {
	lampsOff();
	digitalWrite(acknowledgeLed, LOW);
	digitalWrite(ridestartLed, LOW);
	Serial.println("RIDE STOP PRESSED");
	if (!keyboardStopSent) {
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
		l("E-STOP PRESSED", 0);
		if (modeBypass) {
			lcdC();
			LCD.print("PRESS RIDE START");
			lcdN();
			LCD.print("TO ESR RESET");
			l("To reset ESR loop:", 2);
			l("Press ESR RESET", 3);

			if (esrPressed) {
				digitalWrite(esrLed, HIGH);
				if (!pSent) {
					m = millis();
					pSent = true;
				}
				isHeld = engine.buttonHold(2000, m);
				if (isHeld) {
					eStopResetHandle();
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
			lcdC();
			LCD.print("E-STOP ACTIVE");
			lcdN();
			LCD.print("Switch to BYPASS!");
			l("Switch to BYPASS", 3);

		}

	}
	else if (error) {
		errorReset();

	}
	else if (stop) {
		lcdC();
		LCD.print("PRESS RIDE START");
		//lcdN();
		//LCD.print("TO  RESET");

		if (functionEnabled) {
			if (m1000) {
				digitalWrite(restraintLed, HIGH);
			}
			else {
				digitalWrite(restraintLed, LOW);
			}
		}
		else {
			digitalWrite(restraintLed, LOW);
		}

		if (restraintPressed) {
			functionSelect = true;
		}

		if (startHoldCounter < 10) {
			if (ridestartPressed) {
				digitalWrite(ridestartLed, HIGH);
				startHoldCounter++;
			}
			else {
				if (m500) {
					digitalWrite(ridestartLed, HIGH);
				}
				else {
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
	}
	else {
		digitalWrite(estopLed, HIGH);
		digitalWrite(ridestopLed, HIGH);
	}
}

void setPowerLed() {
	if (panelOn) {
		digitalWrite(powerLed, HIGH);
	}
	else {
		stop = true;
		eStop = true;
		lampsOff();
		digitalWrite(acknowledgeLed, LOW);
		if (m1000) {
			digitalWrite(powerLed, LOW);
		}
		else {
			digitalWrite(powerLed, HIGH);
		}
	}
}

//SERIAL:



void sT(String m) {
	Serial.println(m);
}

void bootCredits() {
	//Prints when panel is booting
	String creditMessage[] = { "Control Panel", "MATT STETSON",
		"stetson2@illinois.edu", "Last Updated: 9/8/16" };
	Serial.println(space);
	Serial.println(slant[0]);
	Serial.println(space);
	Serial.println(creditMessage[0]);
	Serial.println(creditMessage[3]);
	Serial.println(space);
	Serial.println(creditMessage[1]);
	Serial.println(creditMessage[2]);
	Serial.println("VERSION: ");
	Serial.print(version);
	Serial.println(space);
	Serial.println(slant[0]);

	lcdC();
	LCD.print("BY: MATT STETSON");
	lcdPosition(1, 0);
	LCD.print("VER:");
	LCD.print(version);
}

void disclaimer() {
	//PRINTS ON BOOT
	Serial.println("");
	Serial.println(vert[0]);
	Serial.println(F("READ OPERATING INSTRUCTIONS BEFORE USE!!"));
	Serial.println(vert[0]);
	Serial.println("");
	preStarted = true;
}

void bootSerial(int bM) {
	String bM_[] =
	{ "PANEL POWER IS OFF. SWITCH PANEL TO ON TO BEGIN STARTUP.",
		"SWITCH TO AUTO MODE TO BEGIN PHASE I STARTUP.",
		"ATTENTION: E-STOP TEST, E-STOP RESET, & WARNING HORN have been skipped. Please restart if this was a mistake." };

	switch (bM) {
	case 1:
		Serial.println(bM_[0]);
		l("STATUS 001:", 0);
		l("PANEL POWER OFF", 1);
		break;
	case 2:
		Serial.println(bM_[1]);
		s1 = true;
		l("STATUS 002:", 0);
		l("SWITCH TO AUTO", 1);
		break;
	case 3:
		Serial.println(bM_[2]);
		s2 = true;
		break;
	default:
		break;
		bM = 0;
	}
}

void lampTestSerial(int ltM) {
	String m[] =
	{
		"Phase I startup: LAMP TEST: Ensure all lamps function correctly.",
		"Press ACKNOWLEDGE to confirm all lamps function properly and continue startup.",
		"EXTRA FUNCTIONS: ",
		"Switch ENTRANCE GATES to OPEN to turn all lamps solid.",
		"Press and hold TROUBLE for STARTUP HORN test.",
		"Press and hold RIDE START for WARNING MESSAGE test",
		"Press RIDE STOP to bypass startup => MAINTAINENCE ONLY!",
		"LAMP TEST COMPLETE." };
	String eM[] = { "Cannot complete lamp test. \n Switch GATES to CLOSED." };

	switch (ltM) {
	case 1:
		Serial.println(m[0]);
		Serial.println(m[1]);
		Serial.println(space);
		lcd.clear();
		lcd.print("STARTUP: PHASE I");
		lp(0, 1);
		lcd.print("LAMP TEST");
		lp(0, 3);
		lcd.print("Press ACKNOWLEDGE");
		b1 = true;
		break;
	case 2:
		Serial.println(m[2]);
		Serial.println(m[3]);
		Serial.println(m[4]);
		Serial.println(m[5]);
		Serial.println(m[6]);
		Serial.println(space);
		lcdC();
		LCD.print("LAMP TEST:");
		lcdN();
		LCD.print("EXTRA FUNCTIONS");
		b2 = true;
		break;
	case 3:
		Serial.println(m[7]);
		b3 = true;
		break;
	case 4:
		Serial.println(eM[0]);
		b4 = true;
		break;

	default:
		break;
	}
}

void stopTestSerial(int stM) {
	String p[]{ "Switch to AUTO MODE to continue startup." };

	char* m[]{
		"PHASE I STARTUP: STOP TEST; Ensure all stop buttons function correctly.",
		"RIDE STOP TEST: Press RIDE STOP",
		"RIDE STOP functioning correctly.",
		"EMERGENCY STOP TEST: Press EMERGENCY STOP!",
		"EMERGENCY STOP PRESSED: Pull up EMERGENCY STOP",
		"E-STOP functioning correctly.",
		"STOP TEST COMPLETE. Press ACKNOWLEDGE to continue!"

	};

	switch (stM) {
	case 1:
		Serial.println(p[0]);
		lcd.clear();
		lcd.print("STARTUP: PHASE I");
		lp(0, 1);
		lcd.print("STOP TEST");
		lp(0, 3);
		lcd.print("SWITCH TO AUTO");

		b1 = true;
		break;
	case 2:
		Serial.println(m[0]);
		ln(3);
		lcd.print("Press RIDE STOP");
		b2 = true;
		break;
	case 3:
		Serial.println(m[1]);
		b3 = true;
		break;
	case 4:
		Serial.println(m[2]);
		b4 = true;
		break;
	case 5:
		Serial.println(m[3]);
		ln(3);
		lcd.print("Press EMERGENCY STOP");
		b5 = true;
		break;
	case 6:
		Serial.println(m[4]);
		ln(3);
		lcd.print("Pull EMERGENCY STOP ");
		b6 = true;
		break;
	case 7:
		Serial.println(m[5]);
		Serial.println(m[6]);
		ln(2);
		lcd.print("Stop test complete");
		ln(3);
		lcd.print("Press ACKNOWLEDGE   ");
		b7 = true;
		break;

	default:
		debugM("UKNOWN CASE stopTestSerial");
	}

}

void longStartupSerial(int lsM) {
	String p[]{ "Switch to AUTO MODE to continue startup." };

	char* m[]{ "PHASE II STARTUP: STARTUP WARNING",
		"STARTUP WARNING: CHECK THAT ALL GATES ARE SECURE AND RIDE AREA CLEAR!",
		"PRESS ACKNOWLEDGE TO CONFRIM SAFE TO OPERATE!",
		"SAFE OPERATION CONFRIMED!: Press and hold RIDE START to reset INITIATE STARTUP",
		"STARTUP WARNING SUCCESS"

	};

	switch (lsM) {
	case 1:
		Serial.println(p[0]);
		lcd.clear();
		l("STARTUP: PHASE II", 0);
		l("STARTUP WARNING", 1);
		l("Switch to AUTO MODE", 3);
		break;
	case 2:
		Serial.println(m[0]);
		Serial.println(m[1]);
		Serial.println(m[2]);
		l("CHECK RIDE AREA!!", 2);
		l("Press ACKNOWLEDGE", 3);
		break;
	case 3:
		Serial.println(m[3]);
		lcdC();
		l("", 2);
		l("Hold RIDE START", 3);
		break;
	case 4:
		Serial.println(m[4]);
		lcdC();
		break;
	default:
		debugM("ESRSTART SERIAL");

	}
}

void esrStartupSerial(int esrsM) {

	String p[]{ "Switch to AUTO MODE to continue startup." };

	char* m[]{ "PHASE II STARTUP: E-STOP RESET",
		"E-STOP RESET: Press and hold RIDE START to reset ESR LOOP",
		"E-STOP RESET SUCCESSFUL"

	};

	switch (esrsM) {
	case 1:
		Serial.println(p[0]);
		lcdC();
		LCD.print("E-STOP RESET:");
		lcdN();
		LCD.print("SWITCH TO AUTO");
		lcd.clear();
		l("STARTUP: PHASE II", 0);
		l("E-STOP RESET", 1);
		l("Switch to AUTO MODE", 3);
		break;
	case 2:
		Serial.println(m[0]);
		Serial.println(m[1]);
		lcdC();
		LCD.print("E-STOP RESET:");
		lcdN();
		LCD.print("PRESS RIDE START");
		l("To reset esr loop:", 2);
		l("Hold ESR RESET", 3);
		break;
	case 3:
		Serial.println(m[2]);
		break;
	default:
		debugM("ESRSTART SERIAL");

	}

}

void finalStartupSerial(int fsM) {

	String p[]{ "Switch to AUTO MODE to continue startup." };

	char* m[]{ "PHASE III STARTUP: RIDE START",
		"E-STOP RESET: Press and hold RIDE START to complete startup.",
		"RIDE STARTED"

	};

	switch (fsM) {
	case 1:
		Serial.println(p[0]);
		lcd.clear();
		l("STARTUP: PHASE III", 0);
		l("RIDE START", 1);
		l("Switch to AUTO MODE", 3);
		break;
	case 2:
		Serial.println(m[0]);
		Serial.println(m[1]);
		l("To complete startup:", 2);
		l("Hold RIDE START", 3);
		break;
	case 3:
		Serial.println(m[2]);
		break;
	default:
		debugM("FINALSTART SERIAL");

	}

}

void functionsChooseSerial(int efM) {

	char* em[] = { "Switch to AUTOMATIC MODE to continue startup!",
		"PHASE I STARTUP: EXTRA FUNCTIONS; Configure panel",
		"PRESS ACKNOWLEDGE to continue startup!",
		"Press RIDE STOP to goto functions select screen!"
		"EXTRA FUNCTIONS BOOTED TXT!!" };

	switch (efM) {

	case 1:
		Serial.println(em[0]);
		b1 = true;
		break;

	case 2:
		Serial.println(em[1]);
		Serial.println(em[2]);
		Serial.println(em[3]);
		b2 = true;
		break;

	case 3:
		Serial.println(em[4]);
		b2 = true;
		break;
	}
}

void functionSerial(int fM) {

	char* menu[] =
	{ "Switch OPERATIONS TYPE to TYPE 1 and ENTRANCE GATES to CLOSED!",
		"FUNCTIONS MENU:",
		"PAGE 1 (AUTOMATIC MODE): OPERATIONS FUNCTIONS",
		"PAGE 2 (MANUAL MODE): MAINTENANCE SETTINGS",
		"PAGE 3 (BYPASS MODE): TROUBLESHOOTING & DEBUG MENU; ADVANCED ONLY!" };

	switch (fM) {

	case 1:
		Serial.println(menu[0]);
		b1 = true;
		break;

	}

}

void functionPage1Serial(int fuM) {

	char* page1[] = {

		"FUNCTIONS MENU: (PAGE 1 OF 3); OPERATIONS FUNCTIONS",
		"LEAD/SUPERVISORS ONLY!", "PAGE 1A: LEAD-ACCESSABLE FUNCTIONS",
		"Press LOCK RESTRAINTS to toggle AUTOMATIC RESTRAINTS UNLOCK",
		"Press DISPATCH RIGHT to LIST CURRENT OPERATIONS SETTINGS",
		"For more options, switch GATES to OPEN",
		"PAGE 2A: SUPERVISOR-ACCESSABLE FUNCTIONS",
		"Press DISPATCH RIGHT for DISPATCH TOGGLE",
		"RESTRAINTS WILL NOW AUTOMATICALLY UNLOCK IN AUTOMATIC MODE!",
		"RESTRAINTS WILL NO LONGER AUTOMATICALLY UNLOCK! IN AUTOMATIC MODE",
		"SUPERVISOR MODE ENABLED!", "SUPERVISOR MODE DISABLED!" };

	switch (fuM) {

	case 1:
		Serial.println(page1[0]);
		Serial.println(page1[1]);
		f1 = true;
		break;

	case 11:
		Serial.println(page1[2]);
		Serial.println(page1[3]);
		Serial.println(page1[4]);
		Serial.println(page1[5]);
		f1a = true;
		f1b = false;
		break;

	case 12:
		Serial.println(page1[6]);
		Serial.println(page1[7]);
		f1b = true;
		f1a = false;
		break;

	case 111:
		Serial.println(page1[8]);
		break;

	case 112:
		Serial.println(page1[9]);
		break;
	case 121:
		Serial.println(page1[10]);
		break;
	case 122:
		Serial.println(page1[11]);
		break;

	}
}

void functionPage2Serial(int fuM) {

	//char* page2[] = { "" };

	switch (fuM) {

	case 2:
		break;

	}

}

void listSettings(int sM) {

}

void debugM(String dbMessage) {
	Serial.print("DEBUG:  ");
	Serial.print(dbMessage);
	Serial.println(space);
	delay(10);
}

void serialReader() {
	Serial.write("boob");

	// read from port 0, send to port 1:
	if (Serial.available()) {
		int inByte = Serial.read();
		Serial1.write(inByte);

	}

	if (Serial1.available()) {
		// Wait a bit for the entire message to arrive
		delay(10);
		// Clear the screen
		//lcd.clear();
		LCD.print("TEST!");
		// Write all characters received with the serial port to the LCD.
		while (Serial1.available() > 0) {
			lcd.print(Serial.read());
		}
	}

}

//l("123456789ABCDEFGHIJK",5);

//Serial: Computer serial (Pins 0,1)
//Serial1: LCD Screen (18,19)
//Serial2: Bluetooth (16,17)
//Serial3: Keyboard (14,15)

//OPERATIONS ONE::



void modeCheck1() {
	if (modeAuto) {
		autoMode1();
	}
	else if (modeManual) {

	}
	else if (modeBypass) {

	}
	else {
		debugM("UNKNOWN MODE");
		//error = 10;
	}
}

void autoMode1() {
	if (!dispatching) {
		airgates();
		restraints();
		dispatchReadyCheck();
		dispatchIsReady();
	}
	else {
		if (dispatchPressed) {

		}
		else {
			lcdC();
			LCD.print("AIRGATES:    OK!");
			lcdN();
			LCD.print("RESTRAINTS:  OK!");
			dispatchDone = true;
			dispatchReady = false;
			if (rAutoUnlock) {
				autoUnlock();
			}
			dispatching = false;
		}
	}

}

void manualMode1() {
	if (!dispatching) {
		airgates();
		restraints();
		dispatchIsReady();
	}
	else {
		if (!dispatchPressed) {
			dispatching = false;
		}
	}
}

void bypassMode1() {
	airgates();
	restraints();

	if (dispatchRPressed) {
		if (!dispatching) {
			dispatch();
		}
	}
	else {
		dispatching = false;
		if (m1000) {
			digitalWrite(dispatchRLed, HIGH);
		}
		else {
			digitalWrite(dispatchRLed, HIGH);
		}
	}

}

