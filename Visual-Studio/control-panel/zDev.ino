void dev() {
	//put functions to run in here. called by loop()
	var_check();
}

void dev_debug() {

}

void var_check() {
	int testprint = test.dev();
	if (testprint == 1) {
		Serial.print("ride start pressed");
	}
	else
		Serial.println("ride start not pressed.");
}