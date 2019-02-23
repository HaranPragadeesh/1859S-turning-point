#include <iostream>
#include "main.h"
#include "../v5setup.hpp"


void g_turn_t(int dir, int target, float factor)
{
     int aTarget = target - botAngle;

     yawGyro.reset();

    float kP = .55; // .5
    float kI = .005; // .005
    float kD = 1; // 1

    float errorZone = 150;
    float error, errorTot, errorLast;
    float pTerm, iTerm, dTerm;
    float power;


    float targetMin = aTarget - 15;
    float targetMax = aTarget + 15;
    bool ft = true;
    bool ogPass = false;
    float pTime; // pause time
    int exitDelay = 500; // millis to check exit
    int emergancyExit = 5000000; // millis to emergancyExit
    bool settled = false;
    float firstPause;


     while(!settled)
    {
        error = target - std::abs(yawGyro.get_value());

        if (error < errorZone) {
           errorTot += error;
       } else {
           errorTot = 0;
       }

        pTerm = error * kP;

        iTerm = kI * errorTot;
        dTerm = kD * (error - errorLast);
        errorLast = error;

        power = ((pTerm + iTerm + dTerm) * factor);

        LEFT_DRIVE(power * dir);
        RIGHT_DRIVE(-power * dir);

        if(std::abs(yawGyro.get_value()) > targetMin && ft)
        {
            pTime = pros::millis();
            firstPause = pros::millis();
            ft = false;
            ogPass = true;
        }
        if(pros::millis() > pTime + exitDelay && ogPass)
        {
            if((std::abs(yawGyro.get_value()) > targetMin && std::abs(yawGyro.get_value()) < targetMax) or pros::millis() > firstPause + emergancyExit)
            {
                settled = true;
            }
            else
            {
                pTime = pros::millis();
            }
        }

        pros::Task::delay(20);
    }

    RIGHT_DRIVE(0);
    LEFT_DRIVE(0);

	yawGyro.reset();

}

void g_left_t(int target, float factor)
{
  g_turn(LEFT, target, factor);
}

void g_right_t(int target, float factor)
{
  g_turn(RIGHT, target, factor);
}
