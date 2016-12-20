// ultrasonic.h
#ifndef _ULTRASONIC_h
#define _ULTRASONIC_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
class Ultrasonic {
private:
	int _triggerPin, _echoPin, _servoPin;
	float _distance;
	Servo _servo;

	/* ermittelt die Entfernung */
	float distance(void);
	
	public:
		Ultrasonic(int TriggerPin, int EchoPin, int ServoPin);
		// scannt in gerader Linie (Servo 90°) und gibt 0/1 bei Hinderniss zurück
		int Scan();

		int CheckLR(void);

};

#endif

