#include "doRobot.h"

char DoRobot::CheckSerial()
{
	char incomingByte = 0;

	if (Serial.available() > 0) {
		incomingByte = Serial.read();
	}
	if (Serial1.available() > 0) {
		incomingByte = Serial.read();
	}
	if (Serial2.available() > 0) {
		incomingByte = Serial.read();
	}
	if (Serial3.available() > 0) {
		incomingByte = Serial.read();
	}

	if (incomingByte != 0) {
		switch (toupper(incomingByte))
		{
		case KEY_MODE_AUTO:
			DEBUG_PRINTLN("switching to Automatic");
			this->modus = AUTO;
			break;
		case KEY_MODE_GOHOME:	
			DEBUG_PRINTLN("going Home");
			this->modus = GO_HOME;
			break;
		case KEY_MODE_REMOTE:	
			DEBUG_PRINTLN("switching Remotecontrol");
			this->modus = BT_REMOTE;
			Vorderachse.Stop();
			break;
		case KEY_MODE_OFF:
			DEBUG_PRINTLN("switching OFF");
			this->modus = OFF;
			break;
		default:
			break;
		}
	}
	return incomingByte;
}

void DoRobot::ModeRemotecontrol()
{
	char instruction = CheckSerial();
	if (modus != BT_REMOTE)
		return;
	delay(200);

	
}

void DoRobot::ModeAuto()
{
	int x = 0;
	CheckSerial();
	if (modus != AUTO) {
		Vorderachse.Stop();
		return;
	}
	if (Vorderachse.getStatus() == 0)
		Vorderachse.Forward(100);
	DEBUG_PRINTLN("ModeAuto:");
	x = FrontSensor.Scan();
	if (x) {
		DEBUG_PRINT("ModeAuto: FrontSensor.Scan(): ");
		DEBUG_PRINTLN(x);
		Vorderachse.Stop();
		doEscape(FrontSensor.CheckLR());
	}
}

void DoRobot::ModeGoHome()
{
	char instruction = CheckSerial();
	if (modus != GO_HOME) {
		Vorderachse.Stop();
		return;
	}

}

void DoRobot::ModeOff()
{
	char instruction = CheckSerial();
	if (modus != OFF) {
		return;
	}
	Vorderachse.Stop();
	
	// Mähmotor off
}

void DoRobot::doEscape(const int direction)
{
	int x = 0;
	switch (direction) {
		case ESCAPE_LEFT:
			DEBUG_PRINTLN("DoRobot::doEscape ESCAPE_LEFT");
			Vorderachse.Backward(50);
			delay(100);
			Vorderachse.Stop();
			delay(100);
			Vorderachse.TurnLeft((int)TIME_90DEGREE / random(1, 3));
			x = FrontSensor.Scan();
			while (x) {
				Vorderachse.TurnLeft((int)TIME_90DEGREE / random(1, 3));
				x = FrontSensor.Scan();
				DEBUG_PRINT("in Whileschleife: ");
				DEBUG_PRINTLN(x);
			}
			Vorderachse.Forward(100);
		break;
		case ESCAPE_RIGHT:
			DEBUG_PRINTLN("DoRobot::doEscape ESCAPE_RIGHT");
			Vorderachse.Backward(50);
			delay(100);
			Vorderachse.Stop();
			delay(100);
			Vorderachse.TurnRight((int)TIME_90DEGREE / random(1, 3));
			x = FrontSensor.Scan();
			while (x) {
				Vorderachse.TurnRight((int)TIME_90DEGREE / random(1, 3));
				x = FrontSensor.Scan();
				DEBUG_PRINT("in Whileschleife: ");
				DEBUG_PRINTLN(x);
			}
			Vorderachse.Forward(100);
			break;
		case ESCAPE_BACK: Vorderachse.Backward(50);
			while (FrontSensor.CheckLR() == ESCAPE_BACK)
				delay(100);
			Vorderachse.Stop();
			doEscape(FrontSensor.CheckLR());
         	break;
		default:
			break;
	}
}

DoRobot::DoRobot()
{
	Vorderachse.setPins(MOTOR_IN_1, MOTOR_IN_2, MOTOR_IN_ENA, MOTOR_IN_3, MOTOR_IN_4, MOTOR_IN_ENB);
	Vorderachse.Stop();
	FrontSensor.setPins(US_FS_TRIGGER_PIN, US_FS_ECHO_PIN, US_FS_SERVO_PIN);
	modus = AUTO;
	Serial.begin(BAUD);
	Serial1.begin(BAUD);
	Serial2.begin(BAUD);
	Serial3.begin(BAUD);
}

void DoRobot::init()
{

}

//------------------------------------------------------------------
// Function:     run()
// Class:        DoRobot
// Description:  Hauptschleife des Roboters
// Returns:      -
//
// Created:      2016-12-29 (14:33), by Andreas Moelzer
//------------------------------------------------------------------

void DoRobot::run()
{
	while (1) {
		CheckSerial();
		switch (modus) {
		case BT_REMOTE:
			DEBUG_PRINTLN("in Modus BT_REMOTE");
			ModeRemotecontrol();
		break;
		case AUTO:
			DEBUG_PRINTLN("im Modus AUTO");
			ModeAuto();
		break;
		case GO_HOME:
			DEBUG_PRINTLN("im Modus GO_HOME");
			ModeGoHome();
			break;
		case OFF:
			DEBUG_PRINTLN("im Modus OFF");
			ModeOff();
			break;
		default:
			break;
		}
	}
}
