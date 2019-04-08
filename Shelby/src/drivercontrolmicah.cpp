#include "../include/main.h"
#include "v5setup.hpp"

void testControl()
{


     setDriveBrakes(COAST);
	yawGyroT.reset();
	lift.set_brake_mode(HOLD);

     bool combineStop = false;
	int lastPressComb;
	bool firstPressComb = true;

	bool holding = false;
	int lastPress;
	bool firstPress = true;

     bool hasball = false;

     bool slowTurn = false;


	while (true)
	{
          // if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) && ( (pros::millis() > lastPress + 1000) || firstPress) )
          if((master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) &&
               master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) &&
                    master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) &&
                         master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))  && ( (pros::millis() > lastPress + 1000) || firstPress))
		 {
			 lastPress = pros::millis();
			 firstPress = false;
			 holding = !holding;

			 // if(holding == true)
				//  setDriveBrakes(HOLD);
			 // else
				//  setDriveBrakes(COAST);

			 firstPress = false;
		 }


		//sets ints for right and left motor based on dead zone correction function
		int left = dzCorrect( master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y),JOYSTICK_DEADZONE);
		int right = dzCorrect(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y), JOYSTICK_DEADZONE);

          if(( master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X) > 30 ) && (master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) > 30 )){
               left = 40;
               right = -40;
               slowTurn = true;
          }
          else if((master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X) < -30 )&& (master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) < -30 )){
               left = -40;
               right = 40;
               slowTurn = true;
          }
          else{
               slowTurn = false;
          }

          if(holding)
               setDriveBrakes(HOLD);
          if(slowTurn)
               setDriveBrakes(BRAKE);
          if(!slowTurn && !holding)
               setDriveBrakes(COAST);



		if(left == 0){
               LEFT_DRIVE_V(0);
          }
		else{
               LEFT_DRIVE(left * 2.5);
          }
		if(right == 0){
               RIGHT_DRIVE_V(0);
          }
		else{
               RIGHT_DRIVE(right * 2.25);

          }








          // fly
          if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
		{
               flyWheel1.move(FLYWHEEL_BOOST_SPEED);
               flyWheel2.move(FLYWHEEL_BOOST_SPEED);
		}
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && !master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
		{
               flyWheel1.move(FLYWHEEL_TOP_FLAG);
               flyWheel2.move(FLYWHEEL_TOP_FLAG);
		}
		if(!master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && !master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
		{
			flyWheel1.move(FLYWHEEL_IDLE);
			flyWheel2.move(FLYWHEEL_IDLE);
		}


          if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) && (pros::millis() > lastPressComb + 1000) || firstPressComb)
		 {
			 lastPressComb = pros::millis();
			 firstPressComb = false;
			 combineStop = true;
			 firstPressComb = false;
		 }

          // intake
          if(combineStop)
          {
               intake.move(0);
          }
          if(!combineStop)
          {
               intake.move(COMBINE_INTAKE_SPEED);
          }
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && !combineStop)
		{
			intake.move(REVERSE_FLIP_SPEED);
		}

		// Lift
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) || (limitSwitch.get_value() != 1
			&& !master.get_digital(pros::E_CONTROLLER_DIGITAL_A)))
		{
			lift.move(LIFT_UP_SPEED);
		}
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
		{
			lift.move(LIFT_CLR_SPEED);
		}
		if((!master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)
				&& !master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) || (limitSwitch.get_value() == 1))
		{
			if(limitSwitch.get_value() == 1)
			{
                    hasball = true;
				lift.move(-15);
				lift.set_brake_mode(BRAKE);
				master.rumble(".");
			}
		}


	// save brain cells
 	pros::delay(20);
	}
}
