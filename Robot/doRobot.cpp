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
		switch (incomingByte)
		{
		case 'a':
			DEBUG_PRINTLN("switching to Automatic");
			this->modus = AUTO;
			break;
		case 'h':	
			DEBUG_PRINTLN("going Home");
			this->modus = GO_HOME;
			break;
		case 'r':	
			DEBUG_PRINTLN("switching Remotecontrol");
			this->modus = BT_REMOTE;
			Vorderachse.Stop();
			break;
		case 'o'||'s' :
			DEBUG_PRINTLN("switching OFF");
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

			break;
		default:
			break;
		}
	}

}




