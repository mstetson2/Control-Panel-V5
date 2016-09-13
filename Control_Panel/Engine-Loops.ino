#include <Arduino.h>

void loopedVoids() {

  //ALWAYS:
  blink100();
  blink250();
  blink500();
  blink1000();
  buttonStates();

  //set which methods will be running depending on if booted or not
  if (booted == false) {
    booter();
    if (panelOn) {
      blinkPowerLed();
    } else {
      digitalWrite(powerLed, LOW);
      lampsOff();
    }
  } else {
    //Operations
    setModeLed();
    eStopListener();
    errorListeners();
    rideStopListener();

  }
}

void blinkPowerLed() {
  if (m1000) {
    if (digitalRead(powerLed == LOW)) {
      digitalWrite(powerLed, HIGH);
    } else {
      digitalWrite(powerLed, LOW);
    }
  }
}
