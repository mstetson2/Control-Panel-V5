#include <Arduino.h>

void errorListeners() {
  typeError();
  if (modeAuto) {
    //autoAcknowledge();
  }
}

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

