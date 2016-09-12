#include <Arduino.h>

//Serial: Computer serial (Pins 0,1)
//Serial1: LCD Screen (18,19)
//Serial2: Bluetooth (16,17)
//Serial3: Keyboard (14,15)

void sT(String m) {
	Serial.println(m);
}

void bootCredits() {
//PRINTS ON BOOTUP

	char* creditMessage[] = { "Control Panel", "MATT STETSON",
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
	char* bM_[] =
			{ "PANEL POWER IS OFF. SWITCH PANEL TO ON TO BEGIN STARTUP.",
					"SWITCH TO AUTO MODE TO BEGIN PHASE I STARTUP.",
					"ATTENTION: E-STOP TEST, E-STOP RESET, & WARNING HORN have been skipped. Please restart if this was a mistake." };

	switch (bM) {
	case 1:
		Serial.println(bM_[0]);
		lcdC();
		LCD.print("STATUS 001:");
		lcdPosition(1, 0);
		LCD.print("PANEL POWER OFF");
		break;
	case 2:
		Serial.println(bM_[1]);
		s1 = true;
		lcdC();
		LCD.print("STATUS 002:");
		lcdN();
		LCD.print("SWITCH TO AUTO");
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
	char* m[] =
			{
					"Phase I startup: LAMP TEST: Ensure all lamps function correctly.",
					"Press ACKNOWLEDGE to confirm all lamps function properly and continue startup.",
					"EXTRA FUNCTIONS: ",
					"Switch ENTRANCE GATES to OPEN to turn all lamps solid.",
					"Press and hold TROUBLE for STARTUP HORN test.",
					"Press and hold RIDE START for WARNING MESSAGE test",
					"Press RIDE STOP to bypass startup => MAINTAINENCE ONLY!",
					"LAMP TEST COMPLETE." };
	char* eM[] = { "Cannot complete lamp test. \n Switch GATES to CLOSED." };

	switch (ltM) {
	case 1:
		Serial.println(m[0]);
		Serial.println(m[1]);
		Serial.println(space);
		lcdC();
		LCD.print("LAMP TEST: PRESS");
		lcdN();
		LCD.print("ACK TO CONTINUE");
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
	char* p[] { "Switch to AUTO MODE to continue startup." };

	char* m[] {
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
		lcdC();
		LCD.print("STOP TEST:");
		lcdN();
		LCD.print("SWITCH TO AUTO");
		b1 = true;
		break;
	case 2:
		Serial.println(m[0]);
		lcdC();
		LCD.print("STOP TEST:");
		lcdN();
		LCD.print("PRESS RIDE STOP");
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
		lcdC();
		LCD.print("STOP TEST:");
		lcdN();
		LCD.print("PRESS E-STOP");
		b5 = true;
		break;
	case 6:
		Serial.println(m[4]);
		lcdC();
		LCD.print("STOP TEST:");
		lcdN();
		LCD.print("PULL E-STOP");
		b6 = true;
		break;
	case 7:
		Serial.println(m[5]);
		Serial.println(m[6]);
		lcdC();
		LCD.print("STOP TEST: OK");
		lcdN();
		LCD.print("PRESS ACK");
		b7 = true;
		break;

	default:
		debugM("UKNOWN CASE stopTestSerial");
	}

}

void longStartupSerial(int lsM) {
	char* p[] { "Switch to AUTO MODE to continue startup." };

	char* m[] { "PHASE II STARTUP: STARTUP WARNING",
			"STARTUP WARNING: CHECK THAT ALL GATES ARE SECURE AND RIDE AREA CLEAR!",
			"PRESS ACKNOWLEDGE TO CONFRIM SAFE TO OPERATE!",
			"SAFE OPERATION CONFRIMED!: Press and hold RIDE START to reset INITIATE STARTUP",
			"STARTUP WARNING SUCCESS"

	};

	switch (lsM) {
	case 1:
		Serial.println(p[0]);
		lcdC();
		LCD.print("STARTUP WARNING:");
		lcdN();
		LCD.print("SWITCH TO AUTO");
		break;
	case 2:
		Serial.println(m[0]);
		Serial.println(m[1]);
		Serial.println(m[2]);
		lcdC();
		LCD.print("CHECK RIDE AREA!!");
		lcdN();
		LCD.print("PRESS ACKNOWLDGE");
		break;
	case 3:
		Serial.println(m[3]);
		lcdC();
		LCD.print("STARTUP WARNING:");
		lcdN();
		LCD.print("PRESS RIDE START");
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

	char* p[] { "Switch to AUTO MODE to continue startup." };

	char* m[] { "PHASE II STARTUP: E-STOP RESET",
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
		break;
	case 2:
		Serial.println(m[0]);
		Serial.println(m[1]);
		lcdC();
		LCD.print("E-STOP RESET:");
		lcdN();
		LCD.print("PRESS RIDE START");
		break;
	case 3:
		Serial.println(m[2]);
		break;
	default:
		debugM("ESRSTART SERIAL");

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

	char* page2[] = { "" };

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

