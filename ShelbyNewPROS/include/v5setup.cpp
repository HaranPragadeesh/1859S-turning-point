#include "main.h"
#include "v5setup.hpp"

pros::Controller master(pros::E_CONTROLLER_MASTER);

//gyro
pros::ADIGyro yawGyro (PORT_GYRO_YAW, 0); /* tune variable for accurate 360 turn */ // for turning
pros::ADIGyro rollGyro (PORT_GYRO_PITCH); // for climbing

//double check gear cartriges
//double check gear cartriges
//double check gear cartriges
//double check gear cartriges
pros::Motor leftFront (PORT_DRIVE_LEFT_FRONT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftRear (PORT_DRIVE_LEFT_REAR, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rightFront (PORT_DRIVE_RIGHT_FRONT, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // reverse
pros::Motor rightRear (PORT_DRIVE_RIGHT_REAR, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // reverse

pros::Motor flyWheel1(PORT_FLYWHEEL1, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); // reverse
pros::Motor flyWheel2(PORT_FLYWHEEL2, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor intake(PORT_INTAKE, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor combines(PORT_LIFT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
