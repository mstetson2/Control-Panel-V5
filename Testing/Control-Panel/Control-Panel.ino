/* Arduino Control Panel
 * Meant for use with NoLimits Coaster Simulation
 * By Matt Stetson
 * stetson2@illinois.edu
 * mstetson717@gmail.com
 *
 * Started:
 * Last Edited: 9/23/2016
 */

/*
 * This is the main file of the program. *
 */
#include <Arduino.h>
#include <Wire.h> //Used to communicate between the Arduino Due and Mega. This Arduino (mega) sends commands to the Due to send Keyboard strokes to the PC to control the simulation.
#include <SoftwareSerial.h> //Used for the LCD screen.
#include <LiquidCrystal_I2C.h> //Used for the 20x4 LCD screen
#include "Engine.h"
String version = "5.0.0 dev2";

boolean booted = false;
boolean lampTested = false;
boolean stopTested = false;
boolean functionSelectStartup = false;
boolean longWarninged = false;
boolean errorReseted = false;
boolean estopReseted = false;
boolean finalStarted = false;
boolean finalWarninged = false;
boolean isHeld, pSent;
unsigned long m;

boolean connection;
//--START OF I/O SETUP--
//INPUTS:

const int trouble_pressed = 50, emergency_stop_notpressed = 48;
const int control_power_on = 30;
const int mode_auto_selected = 31;
const int mode_bypass_selected = 33;
const int esr_reset_pressed = 46;
const int function_enable_enabled = 24;
const int type_1_selected = 36;
const int type_3_selected = 35;
const int ride_start_pressed = 42;
const int ride_stop_notpressed = 32;
const int acknowledge_pressed = 25;
const int ops_pressed = 38;
const int dispatch_l_pressed = 29;
const int airgates_closed = 34;
const int hmi_pressed = 26;
const int restraint_pressed = 40;
const int dispatch_r_pressed = 44;
//OUTPUTS:
const int powerLed = 37;
const int modeLed = 39;
const int troubleLed = 41;
const int estopLed = 53;
const int esrLed = 51;
const int ridestartLed = 52;
const int ridestopLed = 28;
const int acknowledgeLed = 45;
const int opsLed = 27;
const int restraintLed = 47;
const int dispatchLLed = 43;
const int dispatchRLed = 49;
const int warning_horn = 5;
//FOR LCD:
LiquidCrystal_I2C lcd(0x27, 20, 4); //Addr: 0x3F, 20 chars & 4 lines
SoftwareSerial LCD = SoftwareSerial(0, 14);
const int LCDdelay = 2;
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
boolean esrPressed;
boolean hmiPressed;
boolean opsPressed;

boolean estopActive;

int mode;
int type;
int prevType = 0;
int prevMode = 0;

int hornTone = 150;
//----- END OF INPUTS SETUP -----

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

	//FOR LCD:
	LCD.begin(9600);
	lcdC();
	lcdPosition(0, 0);
	//FOR BIG LCD:
	lcd.init();
	lcd.backlight();
	lcd.setCursor(0, 0);
	lcd.print("WELCOME");
	lp(0, 1);
	lcd.print("Version: ");
	lcd.print(version);
	lp(0, 2);
	lcd.print("By Matt Stetson");
	Serial.begin(9600);
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
	pinMode(esr_reset_pressed, INPUT);
	pinMode(hmi_pressed, INPUT);
	pinMode(ops_pressed, INPUT);
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
	pinMode(esrLed, OUTPUT);
	pinMode(opsLed, OUTPUT);
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
	digitalWrite(esr_reset_pressed, HIGH);
	digitalWrite(hmi_pressed, HIGH);
	digitalWrite(ops_pressed, HIGH);
}

void loop() {
	loopedVoids();
}
