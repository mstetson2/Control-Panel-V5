#include <Arduino.h>

void extraFunctionsChoose() {
  extraFunctionsChoosing = true;
  if (modeAuto) {

    if (!b2) {
      if (booted) {
        functionsChooseSerial(3);
      } else {
        functionsChooseSerial(2);
      }
    }

    if (m1000) {
      digitalWrite(ridestopLed, LOW);
      digitalWrite(acknowledgeLed, HIGH);
    } else {
      digitalWrite(ridestopLed, HIGH);
      digitalWrite(acknowledgeLed, LOW);
    }
    if (ridestopPressed) {
      extraFunctionsChoosed = true;
      digitalWrite(ridestopLed, LOW);
      digitalWrite(acknowledgeLed, LOW);
    }
    if (acknowledgePressed) {
      extraFunctionsChoosed = true;
      digitalWrite(ridestopLed, LOW);
    }
  } else {
    if (!b1) {
      functionsChooseSerial(1);
    }
  }
}

void functionsSelect() {

  if (!m1000) {
    digitalWrite(acknowledgeLed, HIGH);
  } else {
    digitalWrite(acknowledgeLed, LOW);
  }

  if (acknowledgePressed) {
    functionsSelected = true;
    extraFunctionsChoosing = false;
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
    } else if (!rAutoUnlock) {
      digitalWrite(restraintLed, LOW);
      digitalWrite(dispatchRLed, HIGH);
    }

    if (restraintPressed) {
      if (!rAutoUnlock) {
        rAutoUnlock = true;
        digitalWrite(restraintLed, HIGH);
        functionPage1Serial(111);
      } else {
        rAutoUnlock = false;
        functionPage1Serial(112);
      }
      delay(1000);
    }

  } else {
    digitalWrite(restraintLed, LOW);
    digitalWrite(dispatchRLed, LOW);
    if (!f1b) {
      functionPage1Serial(12);
    }

    if (m1000) {
      digitalWrite(ridestartLed, HIGH);
    } else if (!supervisorMode) {
      digitalWrite(ridestartLed, LOW);
    }

    if (ridestartPressed) {
      if (!supervisorMode) {
        supervisorMode = true;
        digitalWrite(ridestartLed, HIGH);
        functionPage1Serial(121);
      } else {
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

