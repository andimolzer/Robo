#include "CrashSensor.h"
#include "globals.h"

CrashSensor::CrashSensor()
{
	pinMode(C_SENSOR_LH, INPUT);
	pinMode(C_SENSOR_LV, INPUT);
	pinMode(C_SENSOR_RH, INPUT);
	pinMode(C_SENSOR_RV, INPUT);
}


CrashSensor::~CrashSensor()
{
}

int CrashSensor::Scan()
{
	if(digitalRead(C_SENSOR_LV))
	return 0;
}
