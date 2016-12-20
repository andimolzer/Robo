// 
// 
// 
#include "mode_auto.h"
#include "globals.h"
#include "ultrasonic.h"
#include "Antrieb2Motor.h"


void modeAuto(void)
{
	DEBUG_PRINTLN("im AutomatikModus");
	obstacle = 0;
	if (Antrieb.GetMovement() == 0)
		Antrieb.Forward(100);
	if (UltrasonicFront.Scan())
	{
		int escapeRoute = 0;
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
}
