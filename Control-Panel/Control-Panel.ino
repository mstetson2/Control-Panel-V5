/* Arduino Control Panel
 * Meant for use with NoLimits Coaster Simulation
 * By Matt Stetson
 * stetson2@illinois.edu
 * mstetson717@gmail.com
 *
 * Started:
 * Last Edited: 9/23/2016
 */
#include <Arduino.h>
#include <Wire.h> //Used to communicate between the Arduino Due and Mega. This Arduino (mega) sends commands to the Due to send Keyboard strokes to the PC to control the simulation.
#include <SoftwareSerial.h> //Used for the LCD screen.

String version = "5.0.0 alpha 1";

boolean lampTested = true;
boolean stopTested = true;
boolean functionSelectStartup = true;
boolean longWarninged = true;
boolean estopReseted = true;
boolean finalStarted = true;
boolean finalWarninged = true;

boolean connection;
//--START OF INPUTS SETUP--
//INPUTS:
//Additional:
//25: old 2 pos keyswitch
//32: old function enable
const int trouble_pressed = 24;
const int emergency_stop_notpressed = 48;
const int control_power_on = 30;
const int mode_auto_selected = 31;
const int mode_bypass_selected = 33;
const int ride_start_pressed = 46;
const int ride_stop_notpressed = 50;
const int function_enable_enabled = 34;
const int type_1_selected = 36;
const int type_3_selected = 35;
const int acknowledge_pressed = 38;
const int restraint_pressed = 40;
const int dispatch_l_pressed = 29;
const int dispatch_r_pressed = 44;
const int airgates_closed = 42;
//OUTPUTS:
const int powerLed = 37;
const int modeLed = 39;
const int troubleLed = 41;
const int estopLed = 53;
const int ridestartLed = 51;
const int ridestopLed = 52;
const int acknowledgeLed = 45;
const int restraintLed = 47;
const int dispatchLLed = 43;
const int dispatchRLed = 49;
const int warning_horn = 5;
//FOR LCD:
SoftwareSerial LCD = SoftwareSerial(0, 14);
const int LCDdelay = 2;  // conservative, 2 actually works
boolean troublePressed;
boolean estopPressed;
boolean panelOn;
boolean modeAuto;
boolean modeManual;
boolean modeBypass;
boolean ridestartPressed;
boolean ridestopPressed;
boolean functionEnabled;
boolean typeOne;
boolean typeTwo;
boolean typeThree;
boolean acknowledgePressed;
boolean restraintPressed;
boolean dispatchLPressed;
boolean dispatchRPressed;
boolean dispatchPressed;
boolean gatesOpen;

boolean estopActive;

int mode;
int type;
int prevType = 0;
int prevMode = 0;

int hornTone = 150;
//----- END OF INPUTS SETUP -----

boolean booted;

boolean rAutoUnlock = true;
boolean supervisorMode;
boolean singleDispatch;
boolean pTroubleAlarm;
boolean pWarningHorn;
boolean pWarningMessage;
boolean willTimeout;
boolean quickTroubleReset;
boolean quickEstopReset;
boolean randomEvents;
boolean disableTrouble;
boolean persistantTrouble;
boolean evacError;
boolean lightCurtain;
boolean trainNoDispatch;
boolean weatherDowntimes;

void setup() {
  Serial.begin(9600);
  //FOR LCD:
  LCD.begin(9600);
  lcdC();
  lcdPosition(0, 0);
  //For Wire (Keyboard) Communication:
  Wire.begin(); // join i2c bus (address optional for master)

  //INPUTS
  pinMode(trouble_pressed, INPUT);
  pinMode(emergency_stop_notpressed, INPUT);
  pinMode(control_power_on, INPUT);
  pinMode(mode_auto_selected, INPUT);
  pinMode(mode_bypass_selected, INPUT);
  pinMode(ride_start_pressed, INPUT);
  pinMode(ride_stop_notpressed, INPUT);
  pinMode(function_enable_enabled, INPUT);
  pinMode(type_1_selected, INPUT);
  pinMode(type_3_selected, INPUT);
  pinMode(acknowledge_pressed, INPUT);
  pinMode(restraint_pressed, INPUT);
  pinMode(dispatch_l_pressed, INPUT);
  pinMode(dispatch_r_pressed, INPUT);
  pinMode(airgates_closed, INPUT);
  //OUTPUTS
  pinMode(powerLed, OUTPUT);
  pinMode(modeLed, OUTPUT);
  pinMode(troubleLed, OUTPUT);
  pinMode(estopLed, OUTPUT);
  pinMode(ridestartLed, OUTPUT);
  pinMode(ridestopLed, OUTPUT);
  pinMode(acknowledgeLed, OUTPUT);
  pinMode(restraintLed, OUTPUT);
  pinMode(dispatchLLed, OUTPUT);
  pinMode(dispatchRLed, OUTPUT);
  //pinMode(warning_horn, OUTPUT);
  //^is analog
  digitalWrite(trouble_pressed, HIGH);
  digitalWrite(emergency_stop_notpressed, HIGH);
  digitalWrite(control_power_on, HIGH);
  digitalWrite(mode_auto_selected, HIGH);
  digitalWrite(mode_bypass_selected, HIGH);
  digitalWrite(ride_start_pressed, HIGH);
  digitalWrite(ride_stop_notpressed, HIGH);
  digitalWrite(function_enable_enabled, HIGH);
  digitalWrite(type_1_selected, HIGH);
  digitalWrite(type_3_selected, HIGH);
  digitalWrite(restraint_pressed, HIGH);
  digitalWrite(acknowledge_pressed, HIGH);
  digitalWrite(dispatch_l_pressed, HIGH);
  digitalWrite(dispatch_r_pressed, HIGH);
  digitalWrite(airgates_closed, HIGH);
}

void loop() {
  loopedVoids();
}
