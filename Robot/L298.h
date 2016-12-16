#pragma once
#ifndef _L298_H
#define _L298_H

#include "globals.h"




class L298
{
public:
	L298();
	L298(int IN1, int IN2, int ENA);

private:
	int _IN1;
	int _IN2;
	int _ENA;
	int _speedPWM;
	int _speedPerc;
	
public:
	void SetPins(int IN1, int IN2, int ENA);
	// Aktiviert den Motortreiber
	void EnableMotor();
	// Setzt den Motortreiber inaktiv
	void DisableMotor();
	// Bewegung vorwaerts
	void Forward();
	// Forwaerts mit Speedangabe in % (0..100)
	void Forward(int speed);
	// Rueckwaerts
	void Backward();
	// Rueckwaerts mit Speedangabe in % (0..100) 
	void Backward(int speed);
	// sofortiger Motorstopp
	void Break();
	// // Motor auslaufen lassen ohne zu Bremsen
	void Rollout();
	// Geschwindikeit setzen in % (0 .. 100)
	int SetSpeed(int speed);


	// gibt den maximalen zu verwendeten PWM-Wert retour
	int getMaxPWM(void);
	// gibt den minimalen zu verwendeten PWM-Wert retour
	int getMinPWM(void);
	// gibt aktuellen PWM-Wert retour
	int getSpeedPWM(void);
	// gibt aktuellen Procentwert der Geschwindigkeit zurueck
	int getSpeedPerc(void);
};

#endif // !_L298_H

