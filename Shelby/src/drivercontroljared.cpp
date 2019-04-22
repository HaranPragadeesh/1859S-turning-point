#include "../include/main.h"
#include "v5setup.hpp"
#include "math.h"
bool firstGo = true;

float spaghettiCounter;

void regControl()
{
  spaghettiCounter = pros::millis();
  fly(0);
  setDriveBrakes(COAST);
	yawGyroT.reset();
	lift.set_brake_mode(HOLD);

	bool holding = false;
	int lastPress;
	bool firstPress = true;

	//pros::Vision aimbot (PORT_AIMBOT);

  bool hasBot = false;
  bool hasTop = false;
  bool preload = true;
  int preLastPress = 0;
  bool preFirstPress = false;
  float wheelDiam = 3.25; // how thicc the wheel is
  float wheelCirc = wheelDiam * PI; // wheels waist size

  float leftD;
  float rightD;

  int encoderRes = 360; // encoders IQ
  float angle = 0;
  float encoderDist = 4.2;
  float cpi = encoderRes / wheelCirc; // clickios per IMPERIAL UNIT
	while (true)
	{


    pros::lcd::set_text(4, std::to_string(leftRawEncoder.get_value()));
    pros::lcd::set_text(5, std::to_string(rightRawEncoder.get_value()));
    pros::lcd::set_text(6, std::to_string(angle));

    leftD = leftRawEncoder.get_value() / cpi;
    rightD = rightRawEncoder.get_value() / cpi;

    angle = (leftD - rightD) / encoderDist; // finds the angle (IN RADIANS)
    angle = TODEG(angle); // turn my angle into degrees

    if(angle < 0) {
         angle = angle + 360;
    }
   // angle = angle % 360;
   angle = fmod(angle, 360);

    std::cout << "left: " << leftRawEncoder.get_value() << std::endl << std::endl;
    std::cout << "right: " << leftRawEncoder.get_value() << std::endl << std::endl;


     //std::cout << "line:" << lineFollower.get_value() << std::endl;




		 if(master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT) && ( (pros::millis() > lastPress + 1000) || firstPress) )
		 {
			 lastPress = pros::millis();
			 firstPress = false;
			 holding = !holding;

			 if(holding == true)
			 {
				 setDriveBrakes(HOLD);
			 }
			 else
       {
				 setDriveBrakes(COAST);
			 }
			 firstPress = false;
		 }

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) )
    {
      std::cout << " clicking " << std::endl;
      std::cout << pros::millis() <<  " / " << preLastPress + 1000;
      if((pros::millis() > preLastPress + 1000) || preFirstPress )
      {
        preLastPress = pros::millis();
        preFirstPress = false;
        preload = !preload;
      }
    }

 		 //if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) )
 		 //{ setDriveBrakes(COAST); }

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


    if(firstGo)
    {
      if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) ||
        master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) ||
        master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
        {
          firstGo = false;
        }
    }

		// ----------------------------------------------------------------------FLYWHEEL-------------
    if(!firstGo)
    {


		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)
				&& !master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
		{
			// flip these 2 if flywheel spins backwards
			flyWheel1.move(FLYWHEEL_TOP_FLAG);
			flyWheel2.move(FLYWHEEL_TOP_FLAG);
			//intake.move(COMBINE_INTAKE_SPEED);
		}

		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
		{
				flyWheel1.move(FLYWHEEL_BOOST_SPEED);
				flyWheel2.move(FLYWHEEL_BOOST_SPEED);
				//intake.move(COMBINE_INTAKE_SPEED);
		}
		else if(!master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)
			&& !master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
		{
			flyWheel1.move(FLYWHEEL_IDLE);
			flyWheel2.move(FLYWHEEL_IDLE);
		}
  }

		// ---------------------------------------------------------------------COMBINE----------------
	/*	if(!master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)
				&& !master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)
					&& !master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
		{
				intake.move(0);
		}*/


    if(limitSwitch.get_value() == 1)
    {
      hasTop = true;
    }
    else{
      hasTop = false;
    }
    if(lineFollower.get_value() > 1000 && lineFollower.get_value() < 2800)
    {
      hasBot = true;
    }
    else{
      hasBot = false;
    }
    /*if(limitSwitchB.get_value() == 1)
    {
      hasBot = true;
    }
    else
    {
      hasBot = false;
    }
    */

    if(!hasTop && preload)
    {
        lift.move(127);
    }
		// -------------------------------------------------------------------LIFT---------------------
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
		{
			lift.move(LIFT_UP_SPEED);
		}
    if(preload && !hasBot && !master.get_digital(pros::E_CONTROLLER_DIGITAL_B))
    {
      intake.move(127);
    }
    if(preload && !hasTop && !master.get_digital(pros::E_CONTROLLER_DIGITAL_B))
    {
      lift.move(60);
    }
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
    {
      lift.move(LIFT_UP_SPEED);
      intake.move(127);
    }
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B))
		{
			lift.move(LIFT_CLR_SPEED);
      intake.move(LIFT_CLR_SPEED);
		}
    else if(!master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && !master.get_digital(pros::E_CONTROLLER_DIGITAL_B))
    {
      if(hasTop)
      {
        lift.move_velocity(0);
        lift.set_brake_mode(HOLD);
      }
      if(hasBot && hasTop)
      {
        intake.move_velocity(0);
        lift.set_brake_mode(HOLD);
      }
    }
    if(!master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && !master.get_digital(pros::E_CONTROLLER_DIGITAL_B) && !hasTop && preload){
      lift.move(60);
    }
    if(!hasTop && preload)
    {
      intake.move(127);
    }
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
		{
			//flyWheel1.move(FLYWHEEL_TOP_FLAG);
			//flyWheel2.move(FLYWHEEL_TOP_FLAG);
			intake.move(REVERSE_FLIP_SPEED);
		}
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B))
    {
      intake.move(-127);
      lift.move(LIFT_CLR_SPEED);
    }
    if(!preload && !master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && !master.get_digital(pros::E_CONTROLLER_DIGITAL_B))
    {
      lift.move(0);
      intake.move(0);
    }
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
      lift.move(127);
      intake.move(127);
    }

    if(spaghettiCounter > 30000)
    {
       // knees week arms are heavy
       SPAGHETTI 
    }
	// save brain cells
 	pros::delay(20);
	}
}
