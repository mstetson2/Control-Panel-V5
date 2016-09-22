#include <Arduino.h>



void modeCheck1() {
	if(modeAuto) {
		autoMode1();
	} else if(modeManual) {

	} else if(modeBypass) {

	} else {
		debugM("UNKNOWN MODE");
		//error = 10;
	}
}

void autoMode1() {
	if(!dispatching) {
		airgates();
		restraints();
		dispatchReadyCheck();
		dispatchIsReady();
	}
	else {
		if(dispatchPressed) {

		}
		else {
			lcdC();
			LCD.print("AIRGATES:    OK!");
			lcdN();
			LCD.print("RESTRAINTS:  OK!");
			dispatchDone = true;
			dispatchReady = false;
			if(rAutoUnlock) {
				autoUnlock();
			}
			dispatching = false;
		}
	}

}

void manualMode1() {
	if(!dispatching) {
		airgates();
		restraints();
		dispatchIsReady();
	}
	else {
		if(!dispatchPressed) {
			dispatching = false;
		}
	}
}

void bypassMode1() {
	airgates();
	restraints();

	if(dispatchRPressed) {
		if(!dispatching) {
			dispatch();
		}
	}
	else {
		dispatching = false;
		if(m1000) {
			digitalWrite(dispatchRLed, HIGH);
		}
		else {
			digitalWrite(dispatchRLed, HIGH);
		}
	}

}

