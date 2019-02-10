#include "main.h"
#include "../v5setup.hpp"

void gyroClimb(int speed, int ang, int delay, int calibrateDelay = 0)
{

  // set motors to coast in case was left on brake or hold last
    rightRear.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    rightFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    leftRear.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    leftFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

    // initialize neede variables
    bool climbed = false;
    bool overcame = false;
    float overcomeAng = 10;
    float zeroAng = 5;

    // calibrate - add -
    pros::delay(calibrateDelay);


    // do until finished climbing
    while(!climbed)
    {
      // while hasent gotten over initial angle
        if(!overcame)
        {
          // while less than inital angle
            while(std::abs(rollGyro.get_value()) < ang)
            {
              leftFront.move(GYRO_CLIMB_SPEED);
              leftRear.move(GYRO_CLIMB_SPEED);
              rightFront.move(GYRO_CLIMB_SPEED);
              rightRear.move(GYRO_CLIMB_SPEED);

            }
            // got over initial so it 'overcame'
            overcame = true;
            // while above 'zeroangle'
            while(std::abs(rollGyro.get_value()) > zeroAng)
            {
              leftFront.move(GYRO_CLIMB_SPEED);
              leftRear.move(GYRO_CLIMB_SPEED);
              rightFront.move(GYRO_CLIMB_SPEED);
              rightRear.move(GYRO_CLIMB_SPEED);
            }

            // dropped below 'zero angle' so its finished climbing

            // delay in order to stop near the center of the platform
            pros::delay(delay);

            climbed = true;


            // stop motors and set to hold
            rightRear.move(0);
            leftRear.move(0);
            rightRear.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            leftRear.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

            rightFront.move(0);
            leftFront.move(0);
            rightFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            leftRear.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        }
    }
}
