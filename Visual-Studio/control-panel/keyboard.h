// keyboard.h

#ifndef _KEYBOARD_h
#define _KEYBOARD_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Wire.h>

class keyboard
{
protected:

public:
	void clear();
	void estop();
	void dispatch();
	void open_gates();
	void close_gates();
	void open_restraints();
	void close_restraints();
	void raise_floor();
	void lower_floor();
	void lock_flyer();
	void unlock_flyer();

private:
	int k0 = 0;
	int k1 = 0;
};
extern keyboard kb;

#endif

