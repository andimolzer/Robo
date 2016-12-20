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
	dist=pulseIn(_echoPin, HIGH, SONIC_TIMEOUT) / 58;
	return (float)dist;
}

Ultrasonic::Ultrasonic(int TriggerPin, int EchoPin, int ServoPin)
{
	_triggerPin = TriggerPin;
	_echoPin = EchoPin;
	_servoPin = ServoPin;
	_servo.attach(_servoPin);
	_servo.write(90);
	pinMode(_triggerPin, OUTPUT);
	pinMode(_echoPin, INPUT);
	pinMode(_servoPin, OUTPUT);
}

int Ultrasonic::Scan()
{	
	_distance = 0.0;
	_distance = this->distance();
	if(_distance== 0.0)
		return 0;
	if (_distance <= DANGER_RANGE)
		return 1;
	return 1;
}

int Ultrasonic::CheckLR()
{
	int left, right;
	_servo.write(180);
	delay(500);
	left=(int)this->distance();
	_servo.write(0);
	delay(500);
	right=(int)this->distance();
	_servo.write(90);
	if (left == 0 && right == 0)
		return random(1, 2);
	if (left !=0 && right !=0)
		return 3;
	if (left > right)
		return 1;
	else
		return 2;
	return 0;
}
