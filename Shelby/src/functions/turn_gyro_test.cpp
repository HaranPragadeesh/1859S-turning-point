#include <iostream>
#include "main.h"
#include "../v5setup.hpp"


#define YAW_VALUE yawGyro.get_value() * -1 // turning left should increase the value not decrease

void g_turn_t(int target)
{
     int aTarget = target - botAngle;

     yawGyro.reset();

    float error, errorTot, errorLast;
    float pTerm, iTerm, dTerm;

    float kP = .55; // .5
    float kI = .005; // .005
    float kD = 1; // 1

    float targetMin = aTarget - 15;
    float targetMax = aTarget + 15;

    float errorZone = 150; // figure out system to work both dir

    float power;

    // exit
    bool ft = true;
    bool ogPass = false;
    bool settled = false;
    // --
    float pTime; // pause time
    float firstPause;
    int exitDelay = 500; // millis to check exit
    int emergancyExit = 5000000; // millis to emergancyExit


    while(!settled)
    {
        error = aTarget - YAW_VALUE;

       // // figure out system for both directions
       //  if (error < errorZone) {
       //     errorTot += error;
       // } else {
       //     errorTot = 0;
       // }

        pTerm = error * kP;
        iTerm = kI * errorTot;
        dTerm = kD * (error - errorLast);

        errorLast = error;

        power = (pTerm + iTerm + dTerm);

        LEFT_DRIVE(-power);
        RIGHT_DRIVE(power);

        if(YAW_VALUE > targetMin && ft)
        {
            pTime = pros::millis();
            firstPause = pros::millis();
            ft = false;
            ogPass = true;
        }
        if(pros::millis() > pTime + exitDelay && ogPass)
        {
            if((YAW_VALUE > targetMin && YAW_VALUE < targetMax) || pros::millis() > firstPause + emergancyExit)
            { settled = true; }
            else
            { pTime = pros::millis();}
        }
        pros::Task::delay(20);
    }

    botAngle = botAngle + YAW_VALUE;
    RIGHT_DRIVE(0);
    LEFT_DRIVE(0);

	yawGyro.reset();

}
