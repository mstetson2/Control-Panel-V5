// 
// 
// 

#include "Engine.h"

//returns true if button has been pressed for at least press_time
boolean EngineClass::buttonHold(int press_time, unsigned long p) {
	boolean tHold;
	boolean dHold;
	unsigned long cHold = millis();

	if (cHold - p > press_time) {
		return true;
		p = false;
	}
	return false;
}

//called in Engine.ino to send the button states.
void ButtonClass::button_state_recieve(
	boolean _trouble,
	boolean _eStop,
	boolean _enable, //panel power
	boolean _mode_auto,
	boolean _mode_manual,
	boolean _mode_bypass,
	boolean _esr,
	boolean _func_enable,
	boolean _type_1,
	boolean _type_2,
	boolean _type_3,
	boolean _rStart,
	boolean _rStop,
	boolean _ack,
	boolean _ops,
	boolean _lDispatch,
	boolean _rDispatch,
	boolean _gates,
	boolean _hmi, boolean _restraints) {
	trouble = _trouble;
	eStop = _eStop;
	enable = _enable; //panel power
	mode_auto = _mode_auto;
	mode_manual = _mode_manual;
	mode_bypass = _mode_bypass;
	esr = _esr;
	func_enable = _func_enable;
	type_1 = _type_1;
	type_2 = _type_2;
	type_3 = _type_3;
	rStart = _rStart;
	rStop = _rStop;
	ack = _ack;
	ops = _ops;
	lDispatch = _lDispatch;
	rDispatch = _rDispatch;
	gates = _gates;
	hmi = _hmi;
	restraints = _restraints;
}