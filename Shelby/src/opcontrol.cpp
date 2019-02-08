#include "../include/main.h"
#include "v5setup.hpp"
#include "autos/autos.hpp"



void opcontrol() {

	testauto();

bool holding = false;

	while (true)
	{
		setDriveBrakes(HOLD);
		 if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
		 {
			 holding = true;
		 }
		 if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN))
		 {
			 holding = false;
		 }

		if(holding)
	 	{ setDriveBrakes(HOLD);  }
		else
		{ setDriveBrakes(COAST); }



		//sets ints for right and left motor based on dead zone correction function
		int left = dzCorrect(JOYSTICK_DEADZONE, LEFT);
		int right = dzCorrect(JOYSTICK_DEADZONE, RIGHT);
		leftFront.move(left);
		leftRear.move(left);
		rightFront.move(right);
		rightRear.move(right);




		// ----------------------------------------------------------------------FLYWHEEL-------------
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)
				&& !master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
		{
			// flip these 2 if flywheel spins backwards
			flyWheel1.move(FLYWHEEL_TOP_FLAG);
			flyWheel2.move(FLYWHEEL_TOP_FLAG);
			intake.move(COMBINE_INTAKE_SPEED);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
		{
			//flyWheel1.move(FLYWHEEL_TOP_FLAG);
			//flyWheel2.move(FLYWHEEL_TOP_FLAG);
			intake.move(REVERSE_FLIP_SPEED);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
		{
				flyWheel1.move(FLYWHEEL_BOOST_SPEED);
				flyWheel2.move(FLYWHEEL_BOOST_SPEED);
				intake.move(COMBINE_INTAKE_SPEED);
		}
		else if(!master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && !master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
		{
			flyWheel1.move(FLYWHEEL_IDLE);
			flyWheel2.move(FLYWHEEL_IDLE);
		}


		// ---------------------------------------------------------------------COMBINE----------------
		if(!master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)
				&& !master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)
					&& !master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
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
