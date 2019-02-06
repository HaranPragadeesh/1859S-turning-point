#include "../include/main.h"
#include "../include/v5setup.hpp"
#include "../include/v5setup.cpp"



#include "../functions/dzCorrect.cpp"

void opcontrol() {

	while (true)
	{//sets ints for right and left motor based on dead zone correction function
		int left = dzCorrect(15, -1);
		int right = dzCorrect(15, 1);
		leftFront.move(left);
		leftRear.move(left);
		rightFront.move(right);
		rightRear.move(right);




		// ----------------------------------------------------------------------FLYWHEEL-------------
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)
				&& !master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
		{
			// flip these 2 if flywheel spins backwards
			flyWheel1.move(TOP_FLAG_SPEED);
			flyWheel2.move(TOP_FLAG_SPEED);
			intake.move(COMBINE_INTAKE_SPEED);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
		{
			flyWheel1.move(TOP_FLAG_SPEED);
			flyWheel2.move(TOP_FLAG_SPEED);
			intake.move(REVERSE_FLIP_SPEED);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
		{
				flyWheel1.move(MIDDLE_FLAG_SPEED);
				flyWheel2.move(MIDDLE_FLAG_SPEED);
		}
		else if(!master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && !master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
		{
			flyWheel1.move(0);
			flyWheel2.move(0);

		}


		// ---------------------------------------------------------------------COMBINE----------------
		if(!master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)
				&& !master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)
				&& !master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
		{
				intake.move(0);
		}


		// -------------------------------------------------------------------LIFT---------------------
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
		{
			lift.move(LIFT_UP_SPEED);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
		{
			lift.move(LIFT_CLR_SPEED);
		}
		else if(!master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)
				&& !master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
		{
			lift.move(0);
		}

	// save brain cells
 	pros::delay(20);
	}
}
