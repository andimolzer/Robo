#include <servo.h>
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
						int escapeRoute = 0;
						Antrieb.Stop();
						escapeRoute=UltrasonicFront.CheckLR();
					
						switch (escapeRoute) {
						case 1: Antrieb.TurnLeft((int)TIME_90DEGREE / random(1, 3));
							while(UltrasonicFront.Scan())
								Antrieb.TurnLeft((int)TIME_90DEGREE / random(1, 3));
							Antrieb.Forward(100);
							break;
						case 2: Antrieb.TurnRight((int)TIME_90DEGREE / random(1, 3));
							while (UltrasonicFront.Scan())
								Antrieb.TurnRight((int)TIME_90DEGREE / random(1, 3));
							Antrieb.Forward(100);
							break;
						case 3: Antrieb.Backward(50);
							while (UltrasonicFront.CheckLR() == 3)
								delay(500);
							Antrieb.Stop();
							escapeRoute = UltrasonicFront.CheckLR();
							switch (escapeRoute) {
							case 1: Antrieb.TurnLeft((int)TIME_90DEGREE / random(1, 3));
								while (UltrasonicFront.Scan())
									Antrieb.TurnLeft((int)TIME_90DEGREE / random(1, 3));
								Antrieb.Forward(100);
								break;
							case 2: Antrieb.TurnRight((int)TIME_90DEGREE / random(1, 3));
								while (UltrasonicFront.Scan())
									Antrieb.TurnRight((int)TIME_90DEGREE / random(1, 3));
								Antrieb.Forward(100);
								break;
							}
							break;
						}

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
	case STOP:		break;
	}


  																			    
}
