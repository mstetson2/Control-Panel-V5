// testclass.h

#ifndef _TESTCLASS_h
#define _TESTCLASS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class testclass
{
 protected:


 public:
	void init();
	void test_void();
	int dev();
};

extern testclass test;

#endif

