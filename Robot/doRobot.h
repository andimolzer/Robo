// doRobot.h

#ifndef _DOROBOT_h
#define _DOROBOT_h
#include "Antrieb2Motor.h"
#include "ultrasonic.h"
#include "globals.h"
#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class DoRobot
{
	protected:
		enum Mode { AUTO, BT_REMOTE, STOP, OFF, GO_HOME, AT_HOME, CHARGING };

	private:
		char incomingByte;
		Mode modus;
		Antrieb2Motor Vorderachse; // Antriebsachse
		Ultrasonic FrontSensor;

		char CheckSerial();

		void ModeRemotecontrol();
		void ModeAuto();
		void ModeGoHome();
		void ModeOff();
		void doEscape(const int direction);


	public:
		DoRobot();
		void init();
		void run();
};



#endif

