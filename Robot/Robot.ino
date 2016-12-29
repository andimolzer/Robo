#include "doRobot.h"
#include "globals.h"
// #include <Servo.h>

DoRobot Robot;


// the setup function runs once when you press reset or power the board
void setup() {
	randomSeed(analogRead(0));
	Robot.init();
	/* Zufallsgenerator starten */ 
}

// the loop function runs over and over again forever
void loop() {
	Robot.run();


/*
	switch (modus) {
	case AUTO:		DEBUG_PRINTLN("im AutomatikModus");
					obstacle = 0;
					if(Antrieb.getStatus()==0)
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
					Antrieb.Stop();
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

*/
  																			    
}
