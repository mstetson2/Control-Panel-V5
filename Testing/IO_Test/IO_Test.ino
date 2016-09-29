const int powerLed;//37
const int modeLed;//39?
const int troubleLed;
const int estopLed;//?
const int ridestartLed = 51;
const int ridestopLed;//28
const int acknowledgeLed;
const int restraintLed;
const int dispatchLLed;
const int dispatchRLed;
const int esrResetLed;//52
const int opsLed = 27;//27

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

void setup() {
  Serial.begin(9600);
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
  pinMode(opsLed, OUTPUT);
  pinMode(esrResetLed, OUTPUT);

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

      digitalWrite(modeLed, HIGH);
    digitalWrite(troubleLed, HIGH);
    digitalWrite(estopLed, HIGH);
    digitalWrite(ridestartLed, HIGH);
    digitalWrite(ridestopLed, HIGH);
    digitalWrite(restraintLed, HIGH);
    digitalWrite(dispatchLLed, HIGH);
    digitalWrite(dispatchRLed, HIGH);
    digitalWrite(acknowledgeLed, HIGH);
    digitalWrite(powerLed, HIGH);
    digitalWrite(opsLed, HIGH);
    digitalWrite(esrResetLed, HIGH);

    delay(5000);

}

void loop() {

if(digitalRead(control_power_on) == LOW) {
    digitalWrite(modeLed, HIGH);
    digitalWrite(troubleLed, HIGH);
    digitalWrite(estopLed, HIGH);
    digitalWrite(ridestartLed, HIGH);
    digitalWrite(ridestopLed, HIGH);
    digitalWrite(restraintLed, HIGH);
    digitalWrite(dispatchLLed, HIGH);
    digitalWrite(dispatchRLed, HIGH);
    digitalWrite(acknowledgeLed, HIGH);
    digitalWrite(powerLed, HIGH);
    digitalWrite(opsLed, HIGH);
    digitalWrite(esrResetLed, HIGH);
}
else {
    digitalWrite(modeLed, LOW);
    digitalWrite(troubleLed, LOW);
    digitalWrite(estopLed, LOW);
    digitalWrite(ridestartLed, LOW);
    digitalWrite(ridestopLed, LOW);
    digitalWrite(restraintLed, LOW);
    digitalWrite(dispatchLLed, LOW);
    digitalWrite(dispatchRLed, LOW);
    digitalWrite(acknowledgeLed, LOW);
    digitalWrite(opsLed, LOW);
    digitalWrite(esrResetLed, LOW);
}

}
