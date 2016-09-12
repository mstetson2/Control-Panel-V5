#ifdef __IN_ECLIPSE__
//This is a automatic generated file
//Please do not modify this file
//If you touch this file your change will be overwritten during the next build
//This file has been generated on 2016-09-12 16:54:50

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
void setup() ;
void loop() ;
void buttonStates() ;
void blink100() ;
void blink250() ;
void blink500() ;
void blink1000() ;
void lampsOff() ;
void lcdPosition(int row, int col) ;
void lcdC();
void backlightOn() ;
void backlightOff();
void serCommand();
void lcdN() ;
void setModeLed() ;
void restraints() ;
void gates() ;
void dispatchChecker() ;
void dispatchAutoChecker() ;
void dispatchManualChecker() ;
void dispatchBypassChecker() ;
void autoUnlock() ;
void dispatch() ;
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
void eStopListener() ;
void rideStopListener() ;
void errorListeners() ;
void typeError() ;
void extraFunctionsChoose() ;
void functionsSelect() ;
void function1() ;
void function2() ;
void function3() ;
void loopedVoids() ;
void blinkPowerLed() ;
void booter() ;
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

#include "Control_Panel_V5.ino"

#include "Engine-Methods.ino"
#include "LCD-Methods.ino"
#include "Operations-Methods.ino"
#include "Serial-Messages.ino"
#include "Stop-Listeners.ino"
#include "errorListener.ino"
#include "functionsSelect.ino"
#include "loopedVoids.ino"
#include "startup.ino"
#include "startupMethods.ino"

#endif
