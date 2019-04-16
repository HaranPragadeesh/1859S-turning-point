#include "../include/main.h"
#include "v5setup.hpp"
//#include "autos/autos.hpp"

void opcontrol()
{
	pros::ADIEncoder leftRawEncoder (PORT_LEFT_TOP, PORT_LEFT_BOT, true);
  pros::ADIEncoder rightRawEncoder (PORT_RIGHT_TOP, PORT_RIGHT_BOT, false);
	if(secretSettings)
	{

		testControl();
	}
	if(!secretSettings)
	{
		regControl();
	}
}
