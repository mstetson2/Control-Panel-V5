// 
// 
// 

#include "testclass.h"
#include <Arduino.h>

void testclass::init()
{


}

void testclass::test_void()
{
	Serial.println("testS");
}

int testclass::dev() {
	if (ride_start_pressed)
		return 1;
	else
		return 0;
	Serial.println("ride_start_tested.;");
}

testclass test;

