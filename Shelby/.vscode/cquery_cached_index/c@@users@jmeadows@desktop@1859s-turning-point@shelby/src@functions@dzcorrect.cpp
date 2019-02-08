#include "main.h"
#include "../v5setup.hpp"

int dzCorrect(int dz, int side)  // USER CONTROL
{
	int joyVal;

	// should be for left side
	if(side == -1){
		if(std::abs(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)) > dz){
			joyVal = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
			return joyVal;
		}
		else{ return 0;}
	}

	// should be for right side
	if(side == 1){
		if(std::abs(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y)) > dz){
			joyVal = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
			return joyVal;
		}
		else{ return 0;}
	}
	return 0;
}
