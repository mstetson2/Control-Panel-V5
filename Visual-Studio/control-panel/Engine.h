// Engine.h

#ifndef _ENGINE_h
#define _ENGINE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class EngineClass
{
protected:


public:
	boolean buttonHold(int press_time, unsigned long p);
	 
};

class ButtonClass
{
public:
	void button_state_recieve(
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
		boolean _hmi,
		boolean _restraints
	);

	boolean trouble;
	boolean eStop;
	boolean enable; //panel power
	boolean mode_auto;
	boolean mode_manual;
	boolean mode_bypass;
	boolean esr;
	boolean func_enable;
	boolean type_1;
	boolean type_2;
	boolean type_3;
	boolean rStart;
	boolean rStop;
	boolean ack;
	boolean ops;
	boolean lDispatch;
	boolean rDispatch;
	boolean gates;
	boolean hmi;
	boolean restraints;
};

extern ButtonClass button;
extern EngineClass engine;

#endif

