#include <Arduino.h>

void loopedVoids() {
	//ALWAYS:
	blink100();
	blink250();
	blink500();
	blink1000();
	buttonStates();

	//set which methods will be running depending on if booted or not
	if (booted == false) {
		booter();
	} else {
		//Operations
		operationsLoops();
	}
}

