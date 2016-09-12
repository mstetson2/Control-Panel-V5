#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

//  ARDUINO CONTROL PANEL
//  MATT STETSON
//  stetson2@illinois.edu
//  mstetson717@gmail.com
String version = "5.0.0 dev 1";

char slant[] = {
		"//////////////////////////////////////////////////////////////" };
char vert[] =
		{ "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" };

String space = "";
String debug = "DEBUG: ";

//--START OF INPUTS SETUP--
//INPUTS:

//FOR QUIET E-STOP:
//const int trouble_pressed = 48;
//const int emergency_stop_notpressed = 25;

const int trouble_pressed = 25;
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
//virtual inputs
//OUTPUTS:
//HARDWARE:
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

boolean error;
int errorCode;

int hornTone = 150;
//----- END OF INPUTS SETUP -----

//START OF STARTUP VARS:======
boolean booted;
boolean preStarted;
boolean startInitMessage;

int startMessage = 0;
boolean s1;
boolean s2;
boolean s3;
boolean s4;
boolean s5;

boolean b1;
boolean b2;
boolean b3;
boolean b4;
boolean b5;
boolean b6;
boolean b7;
boolean b8;
boolean b9;
boolean b10;

boolean i1;
boolean i2;
boolean i3;

boolean f1;
boolean f1a;
boolean f1b;
boolean f2;
boolean f2a;
boolean f2b;
boolean f3;
boolean f3a;
boolean f3b;

boolean lampTested;
//SKIP STOP TEST:
boolean stopTested = true;
boolean extraFunctionsChoosed;
boolean functionsSelected;
boolean longWarninged;
boolean estopReseted;
boolean finalStarted;
boolean finalWarninged;
boolean extraFunctionsChoosing;

boolean rAutoUnlock;
boolean supervisorMode;
boolean singleDispatch;
boolean pTroubleAlarm;
boolean pWarningHorn;
boolean pWarningMessage;
boolean timeout;
boolean quickTroubleReset;
boolean quickEstopReset;
boolean randomEvents;
boolean disableTrouble;
boolean persistantTrouble;
boolean evacError;
boolean lightCurtain;
boolean trainNoDispatch;
boolean weatherDowntimes;

int bM;
int ltM;
int stM;

boolean m100;
boolean m250;
boolean m500;
boolean m1000;

long p100;
long p250;
long p500;
long p1000;

boolean restraintsLocked;
boolean gatesClosed;
boolean dispatching;
boolean autoUnlocked;

//=====END OF STARTUP VARS=====

//FOR LCD:
SoftwareSerial LCD = SoftwareSerial(0, 14);
const int LCDdelay = 10;  // conservative, 2 actually works

void setup() {
	Serial.begin(9600);
	//Serial2.begin(9600);
	//Serial3.begin(9600);

	//FOR LCD:
	LCD.begin(9600);
	lcdC();
	lcdPosition(0, 0);

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
