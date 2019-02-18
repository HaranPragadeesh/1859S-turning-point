#include "../include/main.h"
#include "v5setup.hpp"
#include "autos/autos.hpp"



void opcontrol()
{

	testauto();

	//testauto();
	bool holding = false;
	int lastPress;
	bool firstPress = true;

	while (true)
	{
		/*pros::lcd::set_text(1,
			"LEFTR R" + std::to_string(leftRear.get_actual_velocity()) + "    " +
		 	"LEFTF R" + std::to_string(leftFront.get_actual_velocity()));
		pros::lcd::set_text(2,
			"LEFTR V" + std::to_string(leftRear.get_voltage()) + "    " +
			"LEFTF V" + std::to_string(leftFront.get_voltage()));
		pros::lcd::set_text(3,
			"LEFTR T" + std::to_string(leftRear.get_torque()) + "    " +
			"LEFTF T" + std::to_string(leftFront.get_torque()));


		pros::lcd::set_text(4,
			"RIGHTR R" + std::to_string(rightRear.get_actual_velocity()) + "    " +
		 	"RIGHTF R" + std::to_string(rightFront.get_actual_velocity()));
		pros::lcd::set_text(5,
			"RIGHTR V" + std::to_string(rightRear.get_voltage()) + "    " +
			"RIGHTF V" + std::to_string(rightFront.get_voltage()));
		pros::lcd::set_text(6,
			"RIGHTR T" + std::to_string(leftFront.get_torque()) + "    " +
			"RIGHTF T" + std::to_string(rightFront.get_torque()));
*/



		pros::lcd::set_text(4,
			 "L: " + std::to_string(round(std::abs(LENCO))) +
			 "R: " + std::to_string(round(std::abs(RENCO))) +
			 "A: " + std::to_string(round((std::abs(LENCO) + std::abs(RENCO)) / 2))
		 );

		pros::lcd::set_text(5, "ClimbGy: " + std::to_string(round(rollGyro.get_value())));
		pros::lcd::set_text(6, "TurnGy: " + std::to_string(round(yawGyro.get_value())));
		pros::lcd::set_text(7,
			 "RPM: " + std::to_string(round(flyWheel1.get_actual_velocity() * 15)) +
			 "True RPM: " + std::to_string(round(flyWheel1.get_actual_velocity()))
		 );


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
		int left = dzCorrect(JOYSTICK_DEADZONE, LEFT) * 5;
		int right = dzCorrect(JOYSTICK_DEADZONE, RIGHT) * 5;

		LEFT_DRIVE(left);
		RIGHT_DRIVE(right);

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
