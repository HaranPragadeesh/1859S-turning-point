#include "../include/main.h"
#include "v5setup.hpp"


pros::Controller master(pros::E_CONTROLLER_MASTER);

 pros::ADIGyro yawGyroB (PORT_GYRO_BOT, .58);
 pros::ADIGyro yawGyroT (PORT_GYRO_TOP); /* tune variable for accurate 360 turn */ // for turning
 pros::ADIGyro rollGyro (PORT_GYRO_ROLL); // for climbing

 pros::ADIButton limitSwitch(PORT_LIMIT_LIFT);

// drive motors
 pros::Motor leftFront (PORT_DRIVE_LEFT_FRONT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
 pros::Motor leftRear (PORT_DRIVE_LEFT_REAR, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
 pros::Motor rightFront (PORT_DRIVE_RIGHT_FRONT, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // reverse
 pros::Motor rightRear (PORT_DRIVE_RIGHT_REAR, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // reverse

 pros::ADIEncoder leftRawEncoder (PORT_LENCO_T, PORT_LENCO_B, false);
 pros::ADIEncoder rightRawEncoder (PORT_RENCO_T, PORT_RENCO_B, false);


// flywheel motors
 pros::Motor flyWheel1(PORT_FLYWHEEL1, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // reverse
 pros::Motor flyWheel2(PORT_FLYWHEEL2, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

//ball manipulator motors
 pros::Motor intake(PORT_INTAKE, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
 pros::Motor lift(PORT_LIFT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);


bool autoShouldPark = true;
int selectedAuto = 0;
bool secretSettings = false;
std::string nameList[13] = {
    "NOTHING SELECTED", // 0
    "Red Close", // 1
    "Red Far", // 2
    "Red Far (exo)", // 3
    "Blue Close", // 4
    "Blue Far", // 5
    "Blue Far (exo)", // 6
    "Skills",
    "",
    "",
    "",
    "",
    "Secret Settings"
 };

void updateAutoText()
{
     pros::lcd::set_text(2, nameList[selectedAuto]);


     if(autoShouldPark){
         pros::lcd::set_text(4, "park");
     }
     else if(!autoShouldPark){
         pros::lcd::set_text(4, "dont park");
     }
     else if(selectedAuto > 4)
     {
         pros::lcd::clear_line(4);
     }
     if(selectedAuto == 12)
     {
          secretSettings = true;
     }
     else
     {
          secretSettings = false;
     }
}

void on_center_button()
{
     autoShouldPark = !autoShouldPark;
     updateAutoText();
}

void on_left_button()
{
     if(selectedAuto > 0)
     {
       selectedAuto--;
     }
     updateAutoText();
}

void on_right_button()
{
    if(selectedAuto < 14)
    {
        selectedAuto++;
    }
     updateAutoText();
}




/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "- Shelby Pros -");
     pros::lcd::set_text(2, "   - 1859s -   ");


	pros::lcd::register_btn0_cb(on_left_button);
	pros::lcd::register_btn1_cb(on_center_button);
	pros::lcd::register_btn2_cb(on_right_button);

    pros::ADIGyro yawGyroT (PORT_GYRO_TOP);
    pros::ADIGyro yawGyroB (PORT_GYRO_BOT);
    pros::ADIGyro rollGyro (PORT_GYRO_ROLL);
    pros::ADIDigitalIn limitSwitch (PORT_LIMIT_LIFT);
    pros::Vision aimbot (PORT_AIMBOT, pros::E_VISION_ZERO_CENTER);





}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  //  setDriveBrakes(HOLD);
//    LEFT_DRIVE_V(0);
  //  RIGHT_DRIVE_V(0);
  //  setDriveBrakes(COAST);
    // hi micha
    // put spaces between your comments you dolt
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {

     while(std::abs(yawGyroB.get_value()) > 5)
    {
         pros::ADIGyro yawGyro (PORT_GYRO_BOT);
         while(std::abs(yawGyro.get_value()) > 5)
         {
              REST(2);
         }
    }
    while(std::abs(rollGyro.get_value()) > 5)
   {
        pros::ADIGyro rollGyro (PORT_GYRO_BOT);
        while(std::abs(rollGyro.get_value()) > 5)
        {
            REST(2);
        }
   }

    /*pros::lcd::set_text(4,
         "L: " + std::to_string(round(std::abs(LENCO))) +
         "R: " + std::to_string(round(std::abs(RENCO))) +
         "A: " + std::to_string(round((std::abs(LENCO) + std::abs(RENCO)) / 2))
     );

    pros::lcd::set_text(5, "ClimbGy: " + std::to_string(round(rollGyro.get_value())));
    pros::lcd::set_text(6, "TurnGy: " + std::to_string(round(yawGyro.get_value())));
    pros::lcd::set_text(7,
         "RPM: " + std::to_string(round(flyWheel1.get_actual_velocity() * 15)) +
         "True RPM: " + std::to_string(round(flyWheel1.get_actual_velocity()))
     );*/
}
