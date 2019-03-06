#include <iostream>
#include "main.h"
#include "../v5setup.hpp"

#define TRUEGYRO yawGyroT.get_value() + yawGyroB.get_value()

void turn(int target, int maxSpeed)
{
    int dir;
    if(target > 0)
    { dir = 1; }
    if(target < 0)
    { dir = -1; }


    yawGyroT.reset();
    yawGyroB.reset();

    //setDriveBrakes(BRAKE);

    float kP = .45; // .55
    float kI = .005; // .005
    float kD = 1; // 1

    float errorZone = 150;
    float error, errorTot, errorLast;
    float pTerm, iTerm, dTerm;
    float power;


   // target = target * dir;
    float targetMin = target - 15;
    float targetMax = target + 15;
    bool ft = true;
    bool ogPass = false;
    float pTime; // pause time
    int exitDelay = 500; // millis to check exit
    int emergancyExit = 5000000; // millis to emergancyExit
    bool settled = false;
    float firstPause;

    // zero motors fix if this is not correct method

     while(!settled)
    //while(yawGyro.get_value() < target) // gyro  < target
    {

        // debug();

        error = target - TRUEGYRO;

        if (error < errorZone) {
           errorTot += error;
           pros::lcd::set_text(5, "in zone");
       } else {
           errorTot = 0;
           pros::lcd::clear_line(5);

       }


        pTerm = error * kP;


        iTerm = kI * errorTot;
        dTerm = kD * (error - errorLast);
        errorLast = error;


        power = (pTerm + iTerm + dTerm);

        if(power > maxSpeed)
        {
          power = maxSpeed;
        }


        LEFT_DRIVE(power * dir);
        RIGHT_DRIVE(-power * dir);

        if(TRUEGYRO > targetMin && ft)
        {
            pTime = pros::millis();
            firstPause = pros::millis();
            ft = false;
            ogPass = true;
        }
        if(pros::millis() > pTime + exitDelay && ogPass)
        {
            if((TRUEGYRO > targetMin && TRUEGYRO < targetMax) || pros::millis() > firstPause + emergancyExit)
            {
                settled = true;
            }
            else
            {
                pTime = pros::millis();
            }
        }

        pros::lcd::set_text(3, "gyroT: " + std::to_string(yawGyroT.get_value()));
        pros::lcd::set_text(4, "gyroB: " + std::to_string(yawGyroB.get_value()));

        pros::lcd::set_text(6, "GYRO TRUE: " + std::to_string(TRUEGYRO));

        pros::Task::delay(20);
    }

    RIGHT_DRIVE(0);
    LEFT_DRIVE(0);


	yawGyroT.reset();
    yawGyroB.reset();
}
