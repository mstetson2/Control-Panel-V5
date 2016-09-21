#include <Arduino.h>

boolean gatesLocked;
boolean restraintsLocked;
boolean floorDown;
boolean flyerLocked;

boolean restraintD;

boolean dispatchReady; //used in type 2 and 3 to say floor ready to lower
boolean dispatchClear;
boolean dispatching;
boolean dispatchDone;
int dispatchCooldown;

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
	if(dispatchReady) {
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
	else {
		digitalWrite(dispatchLLed, LOW);
				digitalWrite(dispatchRLed, LOW);
	}
}
void dispatch() {
	if(!dispatching) {
  digitalWrite(dispatchRLed, LOW);
  digitalWrite(dispatchLLed, LOW);
  digitalWrite(restraintLed, LOW);
  //TODO send dispatch keyboard
  dispatching = true;
  lcdC();
  LCD.print("STATUS 100:");
  lcdN();
  LCD.print("DISPATCHING!");
	}
}

void airgates() {
	if(gatesOpen) {
		if(gatesLocked) {
			//TODO: send gates open keyboard
			gatesLocked = false;
			lcdPosition(0,0);
			LCD.print("AIRGATES:  OPEN!");
		}
	} else {
		if(!gatesLocked) {
			//TODO send gates close
			lcdPosition(0,0);
			LCD.print("AIRGATES:    OK!");
			gatesLocked = true;
		}
	}
}

void restraints() {
  if (restraintPressed) {
	  if(restraintD) {
	  restraintD = false;
    if (restraintsLocked) {
      restraintsLocked = false;
      digitalWrite(restraintLed, LOW);
      sT("Restraints unlocked");
      lcdN();
      LCD.print("RESTRAINTS: OPEN");
      //TODO send restraints open
      delay(100);
    } else {
      restraintsLocked = true;
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
    lcdN();
    LCD.print("RESTRAINTS: OPEN");
  }
