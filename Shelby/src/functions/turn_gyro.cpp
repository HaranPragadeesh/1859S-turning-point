#include <iostream>
#include "main.h"
#include "../v5setup.hpp"


void g_turn(int dir, int target, float factor)
{
    setDriveBrakes(BRAKE);
    float kP = .05;
    float kI = .0005;
    float kD = .5;

    float errorZone = target * .1;
    float error, errorTot, errorLast;
    float pTerm, iTerm, dTerm;
    float power;

    float targetMin = target - 15;
    float targetMax = target + 15;
    bool ft = true;
    bool ogPass = false;
    float pTime; // pause time
    int exitDelay = 700; // millis to check exit
    bool settled = false;

    // zero motors fix if this is not correct method
	rollGyro.reset();
    REST(1500);

    target = target * dir;
     while(!settled)
    //while(rollGyro.get_value() < target) // left encoder  < target
    {
        error = target - yawGyro.get_value();
        // errorTot += error;

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

        leftFront.move(-power);
        leftRear.move(-power);

        rightFront.move(power);
        rightRear.move(power);

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

    leftFront.move(0);
    leftRear.move(0);
    rightFront.move(0);
    rightRear.move(0);

	rollGyro.reset();

}

void g_left(int target, float factor)
{
  g_turn(LEFT, target, factor);
}

void g_right(int target, float factor)
{
  g_turn(RIGHT, target, factor);
}
