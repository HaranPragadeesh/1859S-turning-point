#include "main.h"
#include "../v5setup.hpp"

int dzCorrect(int joy, int dz)  // USER CONTROL
{
	// should be for left side
	if(std::abs(joy) > dz){
		return joy;
	}
	else{ return 0;}
}
