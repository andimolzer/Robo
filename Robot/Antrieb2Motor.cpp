#include "Antrieb2Motor.h"
#include <Arduino.h>

Antrieb2Motor::Antrieb2Motor(){}

Antrieb2Motor::Antrieb2Motor(int L_IN1, int L_IN2, int L_ENA, int R_IN1, int R_IN2, int R_ENA)
{
	LMotor.setPins(L_IN1, L_IN2, L_ENA);
	RMotor.setPins(R_IN1, R_IN2, R_ENA);
}

Antrieb2Motor::~Antrieb2Motor()
{

}

void Antrieb2Motor::setPins(const int L_IN1, const int L_IN2, const int L_ENA, const int R_IN1, const int R_IN2, const int R_ENA)
{
	LMotor.setPins(L_IN1, L_IN2, L_ENA);
	RMotor.setPins(R_IN1, R_IN2, R_ENA);
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
	this->Stop();
	RMotor.Forward(100);
	delay(millisec);
	this->Stop();
}

void Antrieb2Motor::TurnRight(int millisec=360)
{
	DEBUG_PRINT("Turn Rechts: ");
	DEBUG_PRINTLN(millisec);
	this->Stop();
	LMotor.Forward(100);
	delay(millisec);
	this->Stop();
}

void Antrieb2Motor::CurveLeft(const int procent)
{
	int ms_L = LMotor.getSpeedPerc();
	int ms_R = RMotor.getSpeedPerc();

	if ((ms_R + procent) <= 100) {
		RMotor.setSpeedPerc(ms_R + procent);
	}
	else {
		LMotor.setSpeedPerc(ms_L - procent);
	}
}

void Antrieb2Motor::CurveRight(const int procent)
{
	int ms_L = LMotor.getSpeedPerc();
	int ms_R = RMotor.getSpeedPerc();

	if ((ms_L + procent) <= 100) {
		LMotor.setSpeedPerc(ms_L + procent);
	}
	else {
		RMotor.setSpeedPerc(ms_R - procent);
	}
}

void Antrieb2Motor::setSpeed(int newspeed)
{
	DEBUG_PRINT("set Speed: ");
	DEBUG_PRINTLN(newspeed);
	LMotor.setSpeedPerc(newspeed);
	RMotor.setSpeedPerc(newspeed);
}

int Antrieb2Motor::getStatus(void)
{
	return _status;
}
