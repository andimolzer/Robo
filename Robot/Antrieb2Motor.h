#pragma once
#ifndef __Antrieb2Motor__
#define __Antrieb2Motor__
#include "L298.h"
#include "globals.h"

class Antrieb2Motor 
{
public:
	enum movement { STOP, FORWARD, BACKWARD };
	Antrieb2Motor(int L_IN1,int L_IN2, int L_ENA, int R_IN1, int R_IN2, int R_ENA);
	Antrieb2Motor();
	~Antrieb2Motor();

private:
	L298 LMotor, RMotor;
	movement _status;

public:
	void setPins(const int L_IN1,const int L_IN2,const int L_ENA,const int R_IN1,const int R_IN2,const int R_ENA);
	// gerade Vorwaerts
	void Forward(int speed);
	// gerade Rueckwaerts
	void Backward(int speed);
	// Motor ausrollen
	void Rollout();
	// Motor blockieren
	void Stop();
	// Linksturn
	void TurnLeft(int millisec);
		// Rechtsturn
	void TurnRight(int millisec);
	// Geswindigkeit setzen
	void setSpeed(int newspeed);
	// gibt den aktuellen Bewegungsstatus retour
	int getStatus(void);

};

#endif // __Antrieb2Motor__

