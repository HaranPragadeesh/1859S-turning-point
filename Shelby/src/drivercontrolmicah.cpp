#include "main.h"
#include "v5setup.hpp"

void testControl()
{

     int flySetSpeed = 3; // 1- idle 2- high far 3- high close
     int lastPressFly;
     bool firstPressFly;

     setDriveBrakes(COAST);
	yawGyroT.reset();
	lift.set_brake_mode(HOLD);

	bool holding = false;
	int lastPress;
	bool firstPress = true;

     bool hasball = false;



	pros::Vision aimbot (PORT_AIMBOT);

	while (true)
	{
          // if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) && ( (pros::millis() > lastPress + 1000) || firstPress) )
          if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) &&
               master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) &&
                    master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) &&
                         master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
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


		//sets ints for right and left motor based on dead zone correction function
		int left = dzCorrect( master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y),JOYSTICK_DEADZONE);
		int right = dzCorrect(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y), JOYSTICK_DEADZONE);

		if(left == 0)
		{
			LEFT_DRIVE_V(0);
		}
		else{
			LEFT_DRIVE(left * 2.5);

		}

		if(right == 0)
		{
			RIGHT_DRIVE_V(0);
		}
		else{
			RIGHT_DRIVE(right * 2.25);

		}

          // flywheel
          if(master.get_digital(pros::E_CONTROLLER_R2) && ((pros::millis() > lastPressFly + 500) || firstPressFly) )
          {
   			 lastPressFly = pros::millis();
   			 firstPressFly = false;

                flySetSpeed++;
                if(flySetSpeed > 3)
                {
                     flySetSpeed = 1;
                }
               if(flySetSpeed == 1)
                    flyWheel1.move(FLYWHEEL_BOOST_SPEED);
                    flyWheel2.move(FLYWHEEL_BOOST_SPEED);
                    if(!hasball)
                         master.rumble(".    ");
                    else
                         master.rumble(".-    ");
               else if(flySetSpeed == 2)
                    flyWheel1.move(FLYWHEEL_IDLE);
                    flyWheel2.move(FLYWHEEL_IDLE);
                    if(!hasball)
                         master.rumble(".  ");
                    else
                         master.rumble(".-  ");
               else if(flySetSpeed == 3)
                    flyWheel1.move(FLYWHEEL_TOP_FLAG);
                    flyWheel2.move(FLYWHEEL_TOP_FLAG);
                    if(!hasball)
                         master.rumble(".");
                    else
                         master.rumble(".-");

          }

          // intake
          intake.move(COMBINE_INTAKE_SPEED);
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
		{
			intake.move(REVERSE_FLIP_SPEED);
		}

		// Lift
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) || (limitSwitch.get_value() != 1
			&& !master.get_digital(pros::E_CONTROLLER_DIGITAL_A)))
		{
			lift.move(LIFT_UP_SPEED);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
		{
			lift.move(LIFT_CLR_SPEED);
		}
		else if((!master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)
				&& !master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) || (limitSwitch.get_value() == 1))
		{
			if(limitSwitch.get_value() == 1)
			{
                    hasball = true;
				lift.move(-15);
				lift.set_brake_mode(BRAKE);
				//master.rumble(".");
			}
		}


	// save brain cells
 	pros::delay(20);
	}
}
