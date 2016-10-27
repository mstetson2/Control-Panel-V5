// ride-operator.h

#ifndef _RIDE-OPERATOR_h
#define _RIDE-OPERATOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Engine.h"

class rideOperator
{
protected:


public:
	boolean dispatch_check();
	boolean airgates();
	boolean restraints();
	void dispatch_ready();
	int dispatch();
	boolean gates_check();
	boolean restraints_check();
	boolean floor_check();
	boolean flyer_check();

private:
	//OPS VARS:
	boolean down;
	boolean stop;
	boolean rideStop;
	boolean eStop;
	boolean error;
	int errorCode;

	boolean gatesLocked;
	boolean restraintsLocked;
	boolean floorDown;
	boolean flyerLocked;

	boolean restraintD;

	boolean dispatchReady; //used in type 2 and 3 to say floor ready to lower
	boolean dispatchClear;
	boolean dispatching;
	boolean dispatchDone;
	int dispatchCooldown;
};

extern rideOperator op;


#endif

