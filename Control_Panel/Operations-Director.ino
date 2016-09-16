#include <Arduino.h>

void typeChecker() {
	if(typeOne) {
		modeCheck1();
	} else if(typeTwo) {
		//modeCheck2();
	} else if(typeThree) {
		//modeCheck3();
	} else {
		debugM("UNKNOWN MODE");
	}
}

void dispatchReadyCheck() {

	if(type == 1) {
		if(gatesLocked && restraintsLocked) {
			dispatchReady= true;
		}
		else {
			dispatchReady = false;
		}
	}
	else if(type == 2) {
		if(gatesLocked && restraintsLocked) {
			dispatchReady = true;
			if(floorDown) {
			dispatchClear = true;
			}
		}
		else {
			dispatchReady = false;
			dispatchClear = false;
		}
	}
	else if(type == 3) {
		if(gatesLocked && restraintsLocked) {
			dispatchReady = true;
			if(flyerLocked) {
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
	if(m1000) {
		digitalWrite(dispatchLLed, HIGH);
		digitalWrite(dispatchRLed, HIGH);
	}
	else {
		digitalWrite(dispatchLLed, LOW);
		digitalWrite(dispatchRLed, LOW);
	}
	if(dispatchPressed) {
		dispatch();
	}
}

void dispatch() {
	if(!dispatching) {
  digitalWrite(dispatchRLed, LOW);
  digitalWrite(dispatchLLed, LOW);
  digitalWrite(restraintLed, LOW);
  //TODO send dispatch keyboard
  dispatching = true;
	}
}

void airgates() {
	if(gatesOpen) {
		if(gatesLocked) {
			//TODO: send gates open keyboard
			gatesLocked = false;
		}
	} else {
		if(!gatesLocked) {
			//TODO send gates close
			gatesLocked = true;
		}
	}
}

void restraints() {
  if (restraintPressed) {
    if (restraintsLocked) {
      restraintsLocked = false;
      digitalWrite(restraintLed, LOW);
      sT("Restraints unlocked");
      //TODO send restraints open
      delay(100);
    } else {
      restraintsLocked = true;
      digitalWrite(restraintLed, HIGH);
      sT("Restraints locked");
      //TODO send lock
      delay(100);
    }
  }
}

void autoUnlock() {
    //TODO send unlock
	restraintsLocked = false;
    digitalWrite(restraintLed, LOW);
    Serial.println("Restraints unlocked because train stopped.");
  }
