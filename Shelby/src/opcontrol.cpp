#include "../include/main.h"
#include "v5setup.hpp"
#include "autos/autos.hpp"
#define BLUE_FLAG_SIG 1
#define GREEN_FLAG_SIG 2
#define RED_FLAG_SIG 3

void opcontrol()
{

	//testauto();

	bool holding = false;
	int lastPress;
	bool firstPress = true;

	pros::Vision aimbot (PORT_AIMBOT);

	while (true)
	{

		std::cout << "Number of Objects Detected: " << aimbot.get_object_count() << "\n\n";
    		pros::delay(2);






		//pros::vision_object_s_t rtn = aimbot.get_by_sig(0, RED_FLAG_SIG);
		// Gets the largest object of the EXAMPLE_SIG signature


		//debug();

		 if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) && ( (pros::millis() > lastPress + 1000) || firstPress) )
		 {
			 lastPress = pros::millis();
			 firstPress = false;
			 holding = !holding;

			 if(holding == true)
			 {
				 setDriveBrakes(HOLD);

			 }
			 else{
				 setDriveBrakes(COAST);
			 }
			 firstPress = false;
		 }

 		 if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) )
 		 { setDriveBrakes(COAST); }


		//sets ints for right and left motor based on dead zone correction function
		int left = dzCorrect( master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y),JOYSTICK_DEADZONE);
		int right = dzCorrect(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y), JOYSTICK_DEADZONE);

		if(left == 0)
		{
			LEFT_DRIVE_V(0);
		}
		else{
			LEFT_DRIVE(left * 2);

		}

		if(right == 0)
		{
			RIGHT_DRIVE_V(0);
		}
		else{
			RIGHT_DRIVE(right * 2);

		}


		//leftFront.move_velocity(left);
		//leftRear.move_velocity(left);
		//rightFront.move_velocity(right);
		//rightRear.move_velocity(right);




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
