#include <iostream>
#include "main.h"
#include "../v5setup.hpp"


void g_turn(int dir, int target, float factor)
{

     yawGyro.reset();
     target = target * dir;

    setDriveBrakes(BRAKE);
    // float kP = .25;
    // float kI = .0005;
    // float kD = .1;

    float kP = .3;
    float kI = .0003;
    float kD = 1;




    float errorZone = target * .1;
    float error, errorTot, errorLast;
    float pTerm, iTerm, dTerm;
    float power;

    float targetMin = target - 15;
    float targetMax = target + 15;
    bool ft = true;
    bool ogPass = false;
    float pTime; // pause time
    int exitDelay = 500; // millis to check exit
    bool settled = false;

    // zero motors fix if this is not correct method



    while(true)
     //while(!settled)
    //while(yawGyro.get_value() < target) // gyro  < target
    {

         debug();

        error = target - yawGyro.get_value();

        if (error < errorZone) {
            errorTot += error;
        } else {
            errorTot = 0;
        }

        pTerm = error * kP;


        iTerm = kI * errorTot;
        dTerm = kD * (error - errorLast);
        errorLast = error;

        power = ((pTerm + iTerm + dTerm) * factor) * dir;

        LEFT_DRIVE(power * dir);
        RIGHT_DRIVE(power * -dir);

        // leftFront.move(-power);
        // leftRear.move(-power);
        //
        // rightFront.move(power);
        // rightRear.move(power);

        if(yawGyro.get_value() > targetMin && ft)
        {
            pTime = pros::millis();
            ft = false;
            ogPass = true;
        }
        if(pros::millis() > pTime + exitDelay && ogPass)
        {
            if(yawGyro.get_value() > targetMin && yawGyro.get_value() < targetMax)
            {
                settled = true;
            }
            else
            {
                pTime = pros::millis();
            }
        }

        pros::lcd::set_text(2, "GYRO::" + std::to_string(yawGyro.get_value()));
        pros::lcd::set_text(3, "target:" + std::to_string(target));
        pros::lcd::set_text(4, "error:" + std::to_string(error));
        pros::lcd::set_text(5, "ptime:" + std::to_string(pTime));
        pros::lcd::set_text(6, "timer:" + std::to_string(pros::millis()));

        pros::Task::delay(20);
    }

    RIGHT_DRIVE(0);
    LEFT_DRIVE(0);

    //leftFront.move(0);
    //leftRear.move(0);
    //rightFront.move(0);
    //rightRear.move(0);

	yawGyro.reset();

}

void g_left(int target, float factor)
{
  g_turn(LEFT, target, factor);
}

void g_right(int target, float factor)
{
  g_turn(RIGHT, target, factor);
}
