#include "../include/main.h"
#include "v5setup.hpp"
#include "autos/autos.hpp"

void opcontrol()
{
	if(secretSettings)
	{
		testControl();
	}
	if(!secretSettings)
	{
		regControl();
	}


}
