#include "main.h"

#define REST(x) pros::Task::delay(x)

extern void fly(int voltage);

extern void debug();

extern void gyroClimb(int dir, int speed, int ang, int delay, int calibrateDelay = 1);

extern void line_test(int dir, int target, int maxPower, float factor = 0);

extern int findSpeed(int encoderMaster, int encoderSlave, int power);

//experimental
extern void lineExt(int dir, int target, float factor);
extern void forwardExt(int target, float factor = 1);
extern void reverseExt(int target, float factor = 1);



//gyro turn
extern void g_turn(int dir, int target, float factor);
extern void g_left(int target, float factor = 1);
extern void g_right(int target, float factor = 1);

//extern void testauto();

// linear pid
extern void line(int dir, int target, float factor);
extern void forward(int target, float factor = 1);
extern void reverse(int target, float factor = 1);

// encoder turn
extern void turn(int dir, int target, float factor);
extern void left(int target, float factor = 1);
extern void right(int target, float factor = 1);


extern void setDriveBrakes(pros::motor_brake_mode_e_t mode);
extern int dzCorrect(int joy, int dz);

extern void waitDrive(int dir, int speed, int waitTime);

//global variables
extern std::string nameList[];
extern int selectedAuto;
extern bool autoShouldPark;


//controller
extern pros::Controller master;


//gyros
extern pros::ADIGyro yawGyro;
extern pros::ADIGyro rollGyro;

//drive motors
extern pros::Motor leftFront;
extern pros::Motor leftRear;
extern pros::Motor rightFront;
extern pros::Motor rightRear;

//flywheel motors
extern pros::Motor flyWheel1;
extern pros::Motor flyWheel2;

//ball manipulator motors
extern pros::Motor intake;
extern pros::Motor lift;



//drive move
#define RIGHT_DRIVE(speed) rightRear.move(speed); rightFront.move(speed)
#define LEFT_DRIVE(speed) leftRear.move(speed); leftFront.move(speed)

#define RIGHT_DRIVE_V(speed) rightRear.move_velocity(speed); rightFront.move_velocity(speed)
#define LEFT_DRIVE_V(speed) leftRear.move_velocity(speed); leftFront.move_velocity(speed)

//motor max
#define MAX_SPEED 127

//joystick deadzone
#define JOYSTICK_DEADZONE 15
//preset GYRO CLIMB speeds
#define GYRO_CLIMB_SPEED 127

//preset fly wheel speeds
#define FLYWHEEL_TOP_FLAG 105
#define FLYWHEEL_BOOST_SPEED 127
#define FLYWHEEL_IDLE 90 // idling speed

//intake speeds
#define COMBINE_INTAKE_SPEED  80
#define REVERSE_FLIP_SPEED -60

// preset lift speeds
#define LIFT_UP_SPEED 127
#define LIFT_CLR_SPEED -70

//macros for int -> direction
#define LEFT -1
#define RIGHT 1
#define FORWARD 1
#define REVERSE -1


// brake defintions
#define COAST pros::E_MOTOR_BRAKE_COAST
#define HOLD pros::E_MOTOR_BRAKE_HOLD
#define BRAKE pros::E_MOTOR_BRAKE_BRAKE

/* encoders macros */
#define LENCO leftRear.get_position()
#define RENCO rightRear.get_position()

/* misc macros */


//drive ports
#define PORT_DRIVE_LEFT_FRONT 11
#define PORT_DRIVE_LEFT_REAR 1
#define PORT_DRIVE_RIGHT_FRONT 20
#define PORT_DRIVE_RIGHT_REAR 14


/* setup flywheel */
#define PORT_FLYWHEEL1 15
#define PORT_FLYWHEEL2 4


/* setup intake */
#define PORT_INTAKE 10
#define PORT_LIFT 6

/* vision sensor port */
#define PORT_AIMBOT 17

/* setup gyros  |- 1 through 8 -| */
#define PORT_GYRO_YAW 1 // A // turn
#define PORT_GYRO_ROLL 8 // H // climb
