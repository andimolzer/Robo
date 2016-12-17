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
	pinMode(_triggerPin, OUTPUT);
	pinMode(_echoPin, INPUT);
	pinMode(_servoPin, OUTPUT);
}

int Ultrasonic::Scan()
{	
	int gefahrenstufe = 0;
	_distance = 0.0;
	_distance = this->distance();
	if(_distance== 0.0)
		return 0;
	if (_distance <= DANGER_RANGE) {
		gefahrenstufe = 1;
		// Da Servo nach links drehen
		_distance = this->distance();
		if (_distance <= DANGER_RANGE) 
			gefahrenstufe++;
		// Da Servo nach rechts drehen
		_distance = this->distance();
		if (_distance <= DANGER_RANGE)
			gefahrenstufe+=2;
	}
	return gefahrenstufe;
}

void Ultrasonic::CheckLR(float * _left, float * _right)
{
	/********************************************************/
	return;
}
