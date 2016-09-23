#ifdef __IN_ECLIPSE__
//This is a automatic generated file
//Please do not modify this file
//If you touch this file your change will be overwritten during the next build
//This file has been generated on 2016-09-23 02:56:44

#include "Arduino.h"
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <Arduino.h>
#include <Arduino.h>
#include <Arduino.h>
#include <Arduino.h>
#include <Arduino.h>
#include <Arduino.h>
#include <Arduino.h>
#include <Arduino.h>
#include <Arduino.h>
#include <Arduino.h>
#include <Arduino.h>
#include <Arduino.h>
void setup() ;
void loop() ;
void wireConnect() ;
void kClear() ;
void kEstop() ;
void kDispatch() ;
void kOpenGates() ;
void kCloseGates() ;
void kOpenRestraints() ;
void kCloseRestraints() ;
void kRaiseFloor() ;
void kLowerFloor() ;
void kLockFlyer() ;
void kUnlockFlyer() ;
void lcdPosition(int row, int col) ;
void lcdC();
void backlightOn() ;
void backlightOff();
void serCommand();
void lcdN() ;
void loopedVoids() ;
void sT(String m) ;
void bootCredits() ;
void disclaimer() ;
void bootSerial(int bM) ;
void lampTestSerial(int ltM) ;
void stopTestSerial(int stM) ;
void longStartupSerial(int lsM) ;
void esrStartupSerial(int esrsM) ;
void functionsChooseSerial(int efM) ;
void functionSerial(int fM) ;
void functionPage1Serial(int fuM) ;
void functionPage2Serial(int fuM) ;
void listSettings(int sM) ;
void debugM(String dbMessage) ;
void buttonStates() ;
void blink100() ;
void blink250() ;
void blink500() ;
void blink1000() ;
void lampsOff() ;
void operationsLoops() ;
void setModeLed() ;
void typeChecker() ;
void dispatchReadyCheck() ;
void dispatchIsReady() ;
void dispatch() ;
void airgates() ;
void restraints() ;
void autoUnlock() ;
void rideError(int e) ;
void errorController() ;
void errorHandler() ;
void errorView() ;
void errorReset() ;
void errorClearHandle() ;
void errorListener() ;
void functionRequestHandler() ;
void startupFunctionPrompt() ;
void functionsPageSelect() ;
void functionsSelect() ;
void function1() ;
void function2() ;
void function3() ;
void stopListener() ;
void eStopController() ;
void eStopHandle() ;
void eStopResetHandle() ;
void rideStopController() ;
void rideStopHandle() ;
void rideStopResetHandle() ;
void stopReset() ;
void stopBlinker() ;
void setPowerLed() ;
void modeCheck1() ;
void autoMode1() ;
void manualMode1() ;
void bypassMode1() ;
void booter() ;
void bootComplete() ;
void bFalse() ;
void estopBlinkBoot() ;
void lampTest() ;
void lampTestAuto() ;
void lampTestFunction() ;
void skipBoot() ;
void lampTestEnd() ;
void stopTest() ;
void stopTestCompleted() ;
void longWarning() ;
void longWarningComplete() ;
void estopResetStartup() ;
void estopResetComplete() ;
void finalStartup() ;
void finalStartupComplete() ;

#include "Control-Panel.ino"

#include "Engine-Devices.ino"
#include "Engine-Loops.ino"
#include "Engine-Serial.ino"
#include "Engine.ino"
#include "Operations-Backend.ino"
#include "Operations-Director.ino"
#include "Operations-ErrorHandler.ino"
#include "Operations-Functions.ino"
#include "Operations-Memory.ino"
#include "Operations-StopsHandler.ino"
#include "OperationsOne.ino"
#include "Startup-Director.ino"
#include "Startup-Methods.ino"

#endif
