#include <servo.h>
#include "ultrasonic.h"

Ultrasonic::Ultrasonic()
{
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

void Ultrasonic::setPins(const int TriggerPin, const int EchoPin, const int ServoPin)
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

int Ultrasonic::distance(void)
{
	int dist = 0;
	digitalWrite(_triggerPin, LOW);
	delayMicroseconds(2);
	digitalWrite(_triggerPin, HIGH);
	delayMicroseconds(20);
	digitalWrite(_triggerPin, LOW);
	dist=(int)pulseIn(_echoPin, HIGH, SONIC_TIMEOUT) / 58;
	DEBUG_PRINT("Ultrasonic::distance: ");
	DEBUG_PRINTLN(dist);
	return dist;
}

int Ultrasonic::Scan(void)
{	
	int distance = 0;
	distance = this->distance();
	if (distance <= DANGER_RANGE && distance!=0)
		return ESCAPE;
	return 0;
}

int Ultrasonic::CheckLR()
{
	DEBUG_PRINTLN("Utrasonic::CheckLR :");
	
	int left=0, right=0;
	_servo.write(180);
	delay(500); /* wie lange braucht Servo ??*/
	left=this->distance();
	_servo.write(0);
	delay(500); /* wie lange braucht Servo ??*/
	right=this->distance();
	_servo.write(90);
	DEBUG_PRINT("left: ");
	DEBUG_PRINTLN(left);
	DEBUG_PRINT("right: ");
	DEBUG_PRINTLN(right);
	if (left == 0 && right == 0)
		return random(ESCAPE_LEFT, ESCAPE_RIGHT);               // ausweichen links oder rechts
	if (left !=0 && right !=0)
		return ESCAPE_BACK;						   // ausweichen nach hinten
	if (left > right)
		return ESCAPE_LEFT;						   // ausweichen Links
	else
		return ESCAPE_RIGHT;						   // ausweichen Rechts
	return 0;
}
