#include "doRobot.h"

DoRobot Robot;

void setup() {
	randomSeed(analogRead(0));
	Robot.init();
}

void loop() {
	Robot.run();
}
