// 
// 
// 

#include "ultrasonic.h"

Ultrasonic::Ultrasonic(int TriggerPin, int EchoPin, int ServoPin)
{
	_triggerPin = TriggerPin;
	_echoPin = EchoPin;
	_servoPin = ServoPin;
}

int Ultrasonic::Scan()
{
	return 0;
}
