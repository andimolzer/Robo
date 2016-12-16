#include "Antrieb2Motor.h"
#include <Arduino.h>
#include "L298.h"

Antrieb2Motor::Antrieb2Motor(int L_IN1, int L_IN2, int L_ENA, int R_IN1, int R_IN2, int R_ENA)
{
	LMotor.SetPins(L_IN1, L_IN2, L_ENA);
	RMotor.SetPins(R_IN1, R_IN2, R_ENA);
}

Antrieb2Motor::~Antrieb2Motor()
{

}

// gerade Vorwaerts
void Antrieb2Motor::Forward(int speed)
{
	LMotor.Forward(speed);
	RMotor.Forward(speed);
	_status = FORWARD;
}

// gerade Zurueck
void Antrieb2Motor::Backward(int speed)
{
	LMotor.Backward(speed);
	RMotor.Backward(speed);
	_status = BACKWARD;
}

// Motor auslaufen lassen
void Antrieb2Motor::Rollout(void)
{
	LMotor.Rollout();
	RMotor.Rollout();
	_status = STOP;
}

// Motor bremsen/stehen bleiben
void Antrieb2Motor::Stop(void)
{
	LMotor.Break();
	RMotor.Break();
	_status = STOP;
}

void Antrieb2Motor::TurnLeft(int millisec=360)
{
	DEBUG_PRINT("Turn Links: ");
	DEBUG_PRINTLN(millisec);
	int speedLeft = LMotor.getSpeedPerc();
	LMotor.Break();
	delay(millisec);
	LMotor.SetSpeed(speedLeft);
}

void Antrieb2Motor::TurnRight(int millisec=360)
{
	DEBUG_PRINT("Turn Links: ");
	DEBUG_PRINTLN(millisec);
	int speedRight = RMotor.getSpeedPerc();
	RMotor.Break();
	delay(millisec);
	RMotor.SetSpeed(speedRight);
}

int Antrieb2Motor::GetMovement(void)
{
	return _status;
}





