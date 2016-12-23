// robbi.h

#ifndef _ROBBI_h
#define _ROBBI_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Robbi
{
 protected:


 public:
	void init();
};

extern Robbi Robbi;

#endif

