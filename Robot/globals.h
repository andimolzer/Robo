#ifndef __GLOBALS_H__
#define __GLOBALS_H__
//#include "Antrieb2Motor.h";
//#include "ultrasonic.h";

#define DEBUG /* Debugging ON/OFF */

#ifdef DEBUG
#define DEBUG_PRINT(x)  Serial.print(x); Serial1.print(x)
#define DEBUG_PRINTLN(x)  Serial.println(x); Serial1.println(x)
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

/* Pins fuer linken/rechten Motor (verwendet in Antrieb2Motor bzw. L298)  */
#define MOTOR_IN_1  3
#define MOTOR_IN_2  4
#define MOTOR_IN_3  5
#define MOTOR_IN_4  6
#define MOTOR_IN_ENA  7    /* muss PWM-Pin sein */
#define MOTOR_IN_ENB  8    /* muss PWM-PIN sein */
#define MIN_PWM 80     /* Minimalwert PWM bevor Motor stehen bleibt */
#define MAX_PWM 255    /* Maximalgeschwindigkeit PWM */
#define SEN_RPM_LINKS_PIN 11 /* Pin fuer linken Drezahlsensor */
#define SEN_RPM_RECHTS_PIN 12 /* Pin fuer rechten Drezahlsensor */

/* Settings fuer Steuerung ( Antrieb2Motor ) */
#define TIME_90DEGREE 500 /* Zeit in Millisekunden die ca. für eine 90° Kurve benötigt wird */

/*************************************************************************/
/********************** Ultraschallsensor auf Servo **********************/
/*************************************************************************/

#define US_FS_SERVO_PIN 2
#define US_FS_TRIGGER_PIN 9 // UltraSonicFrontSensor
#define US_FS_ECHO_PIN 10
#define SONIC_TIMEOUT 400  // millisikunden die wir maximal auf ein Echo warten, alles was grösser ist weit weg
#define DANGER_RANGE 25.0  // ab welcher Entfernung in cm wird es gefaehrlich  ?

/*************************************************************************/
/********************* Crash-Sensoren PINS *******************************/
/*************************************************************************/

#define C_SENSOR_LV 22
#define C_SENSOR_RV 23
#define C_SENSOR_LH 24
#define C_SENSOR_RH 25

#endif // __GLOBALS_H__

