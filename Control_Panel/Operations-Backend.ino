#include <Arduino.h>

void operationsLoops() {
    setModeLed();
    rideStopListener(); //in stop listener
    eStopListener(); //in stop listener
    errorListener(); //in error listener
    //if(!down) {
    typeChecker(); //in director
    //}
}
/*
void downChecker() {
	if(error != 0) {
		down = true;
	}
	if()
}
*/

//sets the mode Led based on functionEnabled? and the mode
void setModeLed() {
	//has not been tested
  if (!modeAuto) {
    if (functionEnabled) {
      if (m250) {
        digitalWrite(modeLed, HIGH);
      } else {
        digitalWrite(modeLed, LOW);
      }
    } else {
      digitalWrite(modeLed, HIGH);
    }
  } else if (functionEnabled) {
    if (m500) {
      digitalWrite(modeLed, HIGH);
    } else {
      digitalWrite(modeLed, LOW);
    }
  } else {
    digitalWrite(modeLed, LOW);
  }
}
