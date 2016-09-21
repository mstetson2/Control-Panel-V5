#include <Arduino.h>

//ERROR CODES:
//0XX: SYSTEM ERROR (INTERNAL CONTROL SYSTEM)
//09X: CRITICAL SYSTEM ERROR
//1XX:
//2XX:
//3XX
//9XX:

void errorListener() {
  //typeError();
  if (modeAuto) {
    //autoAcknowledge();
  }
}

void rideError(int e) {
	error = true;
	errorCode = e;
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

