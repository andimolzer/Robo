// ultrasonic.h
#ifndef _ULTRASONIC_h
#define _ULTRASONIC_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Servo.h>
#include "globals.h"

class Ultrasonic {
private:
	int _triggerPin, _echoPin, _servoPin;
	Servo _servo;

	/* ermittelt die Entfernung */
	int distance(void);
	
	public:
		Ultrasonic();
		Ultrasonic(int TriggerPin, int EchoPin, int ServoPin);
		void setPins(const int TriggerPin,const int EchoPin,const int ServoPin);
		// scannt in gerader Linie (Servo 90°) und gibt 0/1 bei Hinderniss zurück
		int Scan();
		int CheckLR(void);

};

#endif

