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

}

void manualMode1() {

}

void bypassMode1() {

}
