#include <Servo.h>
#include "ultrasonic.h"
#include "Antrieb2Motor.h"


#define PAUSE 1000

char incomingByte;
int  obstacle;
Mode modus = AUTO;

Antrieb2Motor Antrieb(MOTOR_IN_1, MOTOR_IN_2, MOTOR_IN_ENA, MOTOR_IN_3, MOTOR_IN_4, MOTOR_IN_ENB);
Ultrasonic UltrasonicFront(US_FS_TRIGGER_PIN, US_FS_ECHO_PIN, US_FS_SERVO_PIN);

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(19200);
	Antrieb.Stop();
	obstacle = 0;
	randomSeed(analogRead(0)); /* Zufallsgenerator starten */ 

}

// the loop function runs over and over again forever
void loop() {
	
	if (Serial.available() > 0) {
		// read the incoming byte:
		incomingByte = Serial.read();
		switch (incomingByte)
		{
		case 'a' :	Serial.println(incomingByte);
					Serial.println("switching to Automatic");
					Antrieb.Stop();
					modus = AUTO;
					break;
		case 'h':	Serial.println(incomingByte);
					Serial.println("going Home");
					Antrieb.Stop();
					modus = GO_HOME;
					break;
		case 'i':	Serial.println(incomingByte);
					Serial.println("switching Remotecontrol");
					Antrieb.Stop();
					modus = IR_REMOTE;
					break;
		case 's':	Serial.println(incomingByte);
					Serial.println("switching OFF");
					Antrieb.Stop();
					modus = STOP;
					break;
		case 'o':	Serial.println(incomingByte);
					Serial.println("wer hat mich ausgeschalten ??????");
					Antrieb.Stop();
					modus = OFF;
					break;
		default:
					break;
		}
	}

	switch (modus) {
	case AUTO:		DEBUG_PRINTLN("im AutomatikModus");
					obstacle = 0;
					if(Antrieb.GetMovement()==0)
						Antrieb.Forward(100);
					if(UltrasonicFront.Scan())
					{
						float left= 0.0,right = 0.0;
						Antrieb.Stop();
						UltrasonicFront.CheckLR(&left, &right);
					

					}


					delay(1500);
					break;
	case GO_HOME:	Serial.println("on my Way home");
					delay(1500);
					break;
	case IR_REMOTE: Serial.println("ich bin Sklave einer Fernbedienung");
					delay(1500);
					break;
	case OFF:		Serial.println("ich steh da und fadisiere mich .....");
					delay(1500);
					break;
	case AT_HOME:   break; // in Ladestation .... soll er weiter mähen nachher, oder wurde er geschickt ?
	case CHARGING:  break; // ladet Akku
	}


  																			    
}
