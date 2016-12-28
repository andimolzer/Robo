#pragma once
#ifndef _L298_H
#define _L298_H
#include "globals.h"

class L298
{
public:
	L298(int IN1, int IN2, int ENA);
	L298();

private:
	int _IN1;
	int _IN2;
	int _ENA;
	int _speedPWM;
	int _speedPerc;
	int _rpm;
	
public:

	// Aktiviert den Motortreiber
	void EnableMotor();
	// setzt den Motortreiber inaktiv
	void DisableMotor();


	// Bewegung vorwaerts
	void Forward();
	// Forwaerts mit Speedangabe in % (0..100)
	void Forward(const int speed);
	// Rueckwaerts
	void Backward();
	// Rueckwaerts mit Speedangabe in % (0..100) 
	void Backward(const int speed);
	// sofortiger Motorstopp
	void Break();
	// // Motor auslaufen lassen ohne zu Bremsen
	void Rollout();



	// PINs für Motor festlegen
	void setPins(const int IN1, const int IN2, const int ENA);
	// Geschwindikeit setzen in % (0 .. 100)
	void setSpeedPerc(const int speedPerc);
	// Geschwindigkeit setzen in PWM 
	void setSpeedPWM(const int speedPWM);
	// Drehzahl des Motor setzen
	int setRPM(const int rpm);



	// gibt den maximalen zu verwendeten PWM-Wert retour
	int getMaxPWM(void) const;
	// gibt den minimalen zu verwendeten PWM-Wert retour
	int getMinPWM(void) const;
	// gibt aktuellen PWM-Wert retour
	int getSpeedPWM(void) const;
	// gibt aktuellen Procentwert der Geschwindigkeit zurueck
	int getSpeedPerc(void) const;
	// gibt die Motordrezahl zurueck
	int getRPM(void) const;


};

#endif // !_L298_H

