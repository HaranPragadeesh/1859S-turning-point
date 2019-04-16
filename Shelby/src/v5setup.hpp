#include "../include/main.h"
#include <functional>
//#include <iostream>

#define PI 3.14159265358979323846
#define TODEG(rad) (rad * (180 / PI))
#define TORAD(deg) (deg * (PI / 180))

#define REST(x) pros::Task::delay(x)

extern int curTime;

extern void regControl();
extern void testControl();

void dualDrive(float targetA, float targetB = 0, int delay = 0, int maxSpeedA = 127, int maxSpeedB = 127, int cb1Ticks = 0, std::function<void()> callback1 = [](){}, int cb2Ticks = 0, std::function<void()> callback2 = [](){});

void rotate(int targetE, int maxSpeed = 110, int callbackTicks = 0, std::function<void()> callback = [](){});
//extern void rotate(int target, int maxSpeed = 110);
extern void noPidDrive(int target, int speed = 110);
extern void noPidRotate(int targetE, int speed = 110);


extern void liftCheck(int exitTime = 1000);
extern void singleOutDouble();
extern void fly(int voltage);

extern void debug();

extern void gyroClimb(int dir, int speed, int ang, int delay, int calibrateDelay = 1);


extern void swing(int side, int target, int speed = 127);

//extern void line_test(int dir, int target, int maxPower);
extern void drive(int targetM, int maxPower = 110, int callbackTicks = 0, std::function<void()> callback = [](){}, bool check = true);
//extern void newForward(int dir, int target, int maxPower, int callbackTicks, std::function<void(int)> callback = [](int){});

void newForward(int target,  float factor = 0);
void newReverse(int target,  float factor = 0);

//extern void newForward(int target, int maxPower = 110);
//extern void newReverse(int target, int maxPower = 110);

// extern void line(int dir, int target, float factor);
// extern void forward(int target, float factor = 1);
// extern void reverse(int target, float factor = 1);

extern void taskTest(void* param);


//experimental
extern void lineExt(int dir, int target, float factor);
extern void forwardExt(int target, float factor = 1);
extern void reverseExt(int target, float factor = 1);


extern int botAngle;

//gyro turn
extern void g_turn(int dir, int target, int maxSpeed);
extern void g_left(int target, int maxSpeed = 110);
extern void g_right(int target, int maxSpeed = 110);

extern void g_turn_t(int dir, int target, float factor);
extern void g_left_t(int target, float factor = 1);
extern void g_right_t(int target, float factor = 1);

//extern void testauto();

// linear pid
extern void line(int dir, int target, float factor);
extern void forward(int target, float factor = 1);
extern void reverse(int target, float factor = 1);

//double gyro turn
void turn_g2(int target, int maxSpeed = 110);


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
extern bool secretSettings;
extern bool autoShouldPark;


//controller
extern pros::Controller master;


//gyros
extern pros::ADIGyro yawGyroT;
extern pros::ADIGyro yawGyroB;
extern pros::ADIGyro rollGyro;
extern pros::ADIDigitalIn limitSwitch;
extern pros::ADIDigitalIn limitSwitchB;

extern pros::Motor led;
#define PORT_LED 16

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

extern pros::ADIEncoder leftRawEncoder;
extern pros::ADIEncoder rightRawEncoder;
#define PORT_LEFT_TOP 7
#define PORT_LEFT_BOT 8
#define PORT_RIGHT_TOP 6
#define PORT_RIGHT_BOT 5

extern pros::ADIAnalogIn lineFollower;

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
#define FLYWHEEL_TOP_FLAG 102
#define FLYWHEEL_BOOST_SPEED 127
#define FLYWHEEL_IDLE 87 // idling speed

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

#define PORT_LINEFOLLOW 1

/* setup intake */
#define PORT_INTAKE 10
#define PORT_LIFT 6

/* vision sensor port */
#define PORT_AIMBOT 17

/* setup gyros  |- 1 through 8 -| */
#define PORT_GYRO_TOP 4 // D // turn
#define PORT_GYRO_BOT 3 // C

#define PORT_GYRO_ROLL 8 // H // climb
#define PORT_LIMIT_LIFT 2 // B
#define PORT_LIMIT_LIFT_B 5


extern void shoot(int time, int liftSpeed = LIFT_UP_SPEED);
extern void doubleShoot(int time, int liftSpeed = 127);
extern void singleShoot(int time, int liftSpeed = 127);
