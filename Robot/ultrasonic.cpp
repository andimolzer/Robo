#include <servo.h>
#include "ultrasonic.h"
#include "globals.h"

float Ultrasonic::distance(void)
{
	float dist = 0.0;
	digitalWrite(_triggerPin,LOW);
	delayMicroseconds(2);
	digitalWrite(_triggerPin, HIGH);
	delayMicroseconds(20);
	digitalWrite(_triggerPin, LOW);
	dist=pulseIn(_echoPin, HIGH, DANGER_RANGE) / 58;
	return (float)dist;
}

Ultrasonic::Ultrasonic(int TriggerPin, int EchoPin, int ServoPin)
{
	_triggerPin = TriggerPin;
	_echoPin = EchoPin;
	_servoPin = ServoPin;
	pinMode(_triggerPin, OUTPUT);
	pinMode(_echoPin, INPUT);
	pinMode(_servoPin, OUTPUT);
}

int Ultrasonic::Scan()
{	
	_distance[0] = this->distance() == 0.0;
	if(_distance[0]== 0.0)
		return 0;
	
	return 0;
}
