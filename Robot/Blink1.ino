/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */
#include <Servo.h>
#include "globals.h"
#include "Antrieb2Motor.h"


Servo myservo;
Antrieb2Motor Antrieb(MOTOR_IN_1, MOTOR_IN_2, MOTOR_IN_ENA, MOTOR_IN_3, MOTOR_IN_4, MOTOR_IN_ENB);
int speed;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  myservo.attach(US_FS_SERVO_PIN);
  Antrieb.Stop();
  speed = 100;
}

// the loop function runs over and over again forever
void loop() {
	int inByte = 0;
	if (Serial.available() > 0) 
		 inByte = Serial.read();

	if (Serial1.available() > 0)
		inByte = Serial1.read();

	if (inByte!=0)
		Serial.write(inByte);
	

		switch (inByte) {

		case '1': 
			Antrieb.Forward(speed);
			Serial.println("Motor  Forward"); // Prints out “Motor 1 Forward” on the serial monitor
			Serial.println("   "); // Creates a blank line printed on the serial monitor
			break;

		case '2': 
			Antrieb.Backward(speed);
			Serial1.println("Motor  BackWard");
			Serial1.println("   ");
			break;

		case '3': 
			Antrieb.TurnLeft(TIME_90DEGREE);
			Serial1.println("Motor  LINKS");
			Serial1.println("   ");
			break;

			case '4': 
			Antrieb.TurnRight(TIME_90DEGREE);
			Serial.println("Motor RECHTS");
			Serial.println("   ");
			break;

		case '5': 
			Antrieb.Stop();
			Serial.println("Motor  Stop");
			Serial.println("   ");
			break;

		case '+': 
			if (speed < 100)
				speed += 10;
			Antrieb.SetSpeed(speed);
			Serial.println("Motor schneller");
			Serial.println("   ");
			break;

		case '-': 
			if (speed > 0)
				speed -= 10;
			Antrieb.SetSpeed(speed);
			Serial.println("Motor langsamer");
			Serial.println("   ");
			break;

		default:
			break;
		}
		
	
}
