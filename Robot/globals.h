#pragma once


#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#define DEBUG /* Debugging ON/OFF */

#ifdef DEBUG
#define DEBUG_PRINT(x)  Serial.print(x)
#define DEBUG_PRINTLN(x)  Serial.println(x)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)
#endif

/**************************************************************************/
/************************ Arbeitsmodi *************************************/
/**************************************************************************/
enum Mode {AUTO, IR_REMOTE, STOP, OFF, GO_HOME, AT_HOME, CHARGING};

/**************************************************************************/
/************************ Motorsteuerung **********************************/
/**************************************************************************/

/* Pins fuer linken/rechten Motor */
#define MOTOR_IN_1  6
#define MOTOR_IN_2  7
#define MOTOR_IN_3  8
#define MOTOR_IN_4  9
#define MOTOR_IN_ENA  5    /* muss PWM sein */
#define MOTOR_IN_ENB  11   /* muss PWM sein */
#define MIN_PWM 80     /* Minimalwert PWM bevor Motor stehen bleibt */
#define MAX_PWM 255    /* Maximalgeschwindigkeit PWM                */
#define TIME_90DEGREE 180 /* zeit in Millisekunden die ca. für eine 90° Kurve benötigt wird */

/*************************************************************************/
/********************** Ultraschallsensor auf Servo **********************/
/*************************************************************************/
#define US_FS_SERVO_PIN 3
#define US_FS_TRIGGER_PIN 19 // UltraSonicFrontSensor
#define US_FS_ECHO_PIN 18
#define SONIC_TIMEOUT 400  // millisikunden die wir maximal auf ein Echo warten, alles was grösser ist weit weg
#define DANGER_RANGE 25.0  // ab welcher Entfernung in cm wird es gefaehrlich  ?

/*************************************************************************/
/********************* Crash-Sensoren ************************************/
/*************************************************************************/
#define C_SENSOR_LV 14
#define C_SENSOR_RV 15
#define C_SENSOR_LH 16
#define C_SENSOR_RH 17

#endif // __GLOBALS_H__

