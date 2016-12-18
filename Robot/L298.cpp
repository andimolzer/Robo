// Infos zu L298N: http://www.geeetech.com/wiki/index.php/L298N_Motor_Driver_Board

#include "L298.h"
#include <Arduino.h>



L298::L298()
{
	_IN1 = 0;
	_IN2 = 0;
	_ENA = 0;
	_speedPWM = 0;
	_speedPerc = 0;
}

// Constructor fuer Motortreiber
L298::L298(int IN1, int IN2, int ENA)
{
	_IN1 = IN1;
	_IN2 = IN2;
	_ENA = ENA;
	pinMode(_IN1, OUTPUT);
	pinMode(_IN2, OUTPUT);
	pinMode(_ENA, OUTPUT);
	this->Break();
	this->EnableMotor();
}

void L298::SetPins(int IN1, int IN2, int ENA) {
	_IN1 = IN1;
	_IN2 = IN2;
	_ENA = ENA;
	pinMode(_IN1, OUTPUT);
	pinMode(_IN2, OUTPUT);
	pinMode(_ENA, OUTPUT);
}


// Aktiviert den Motortreiber
void L298::EnableMotor()
{
	pinMode(_ENA, HIGH);
}


// Setzt den Motortreiber inaktiv
void L298::DisableMotor()
{
	pinMode(_ENA, LOW);
}


// Bewegung vorwaerts
void L298::Forward()
{
	digitalWrite(_IN1, HIGH);
	digitalWrite(_IN2, LOW);
}


// Forwaerts mit Speedangabe in % (0..100)
void L298::Forward(int speed)
{
	digitalWrite(_IN1, HIGH);
	digitalWrite(_IN2, LOW);
	SetSpeed(speed);
}


// Rueckwaerts
void L298::Backward()
{
	digitalWrite(_IN1, LOW);
	digitalWrite(_IN2, HIGH);
}


// Rueckwaerts mit Speedangabe in % (0..100) 
void L298::Backward(int speed)
{
	digitalWrite(_IN1, LOW);
	digitalWrite(_IN2, HIGH);
	SetSpeed(speed);
}


// sofortiger Motorstopp
void L298::Break()
{
	digitalWrite(_IN1, LOW);
	digitalWrite(_IN2, LOW);
}


// // Motor auslaufen lassen ohne zu Bremsen
void L298::Rollout()
{
	digitalWrite(_ENA, LOW);
	digitalWrite(_IN1, LOW);
	digitalWrite(_IN2, LOW);
}


// Geschwindikeit setzen in % (0 .. 100)
int L298::SetSpeed(int speed)
{
	DEBUG_PRINT("in SetSpeed: "); DEBUG_PRINTLN(speed);
	if (speed >= 0 && speed <= 100 && speed!=_speedPerc) {
		_speedPWM = int((MAX_PWM-MIN_PWM)/100.0*speed+MIN_PWM);
		_speedPerc = speed;
		analogWrite(_ENA, _speedPWM);
		DEBUG_PRINT("_speedPWM:  "); DEBUG_PRINTLN(_speedPWM);
		DEBUG_PRINT("_speedPerc: "); DEBUG_PRINTLN(_speedPerc);
	}
	return 0;
}

//////////////////////// INFO /////////////////////////////

int L298::getMaxPWM(void) {
	return MAX_PWM;
}

int L298::getMinPWM(void) {
	return MIN_PWM;
}

int L298::getSpeedPerc(void) {
	return _speedPerc;
}

int L298::getSpeedPWM(void) {
	return _speedPWM;
}
