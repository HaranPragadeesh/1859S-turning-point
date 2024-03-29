#include <iostream>
#include "main.h"
#include "../v5setup.hpp"


void lineExt(int dir, int target, float factor)
{

    setDriveBrakes(BRAKE);
    float kP = .25;
    float kI = .0005;
    float kD = 1;

    float errorZone = target * 1;
    float error, errorTot, errorLast;
    float pTerm, iTerm, dTerm;
    float power;

    bool settled = false;
    int pTime = 0;
    int exitDelay = 350;
    float targetMax = target * 1.01;
    float targetMin = target * .99;
    int timeLast = 0;

    // zero motors fix if this is not correct method
    leftFront.tare_position();
    leftRear.tare_position();
    rightFront.tare_position();
    rightRear.tare_position();


    while(!settled)
    //while(std::abs(LENCO) < target) // left encoder  < target
    {
        error = target - std::abs(LENCO);
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

        leftFront.move(power);
        rightFront.move(power);
        leftRear.move(power);
        rightRear.move(power);


        //timeLast = pros::millis();

        if(pros::millis() > pTime + exitDelay)
        {
            // if not in zone reset timer
            if(std::abs(LENCO) < targetMin || std::abs(LENCO) > targetMax)
            {
                pTime = pros::millis();
            }
            else
            {
                settled = true;
            }
        }
        else
        {
            pTime = pros::millis();
        }



        // if(pros::millis() < pTime + exitDelay)
        // {
        //     if in zone set settled true
        //     if(std::abs(LENCO) > targetMin && std::abs(LENCO) < targetMax)
        //     {
        //         settled = true;
        //     }
        //     // if not in zone assert settled still false and reset pause time
        //     else
        //     {
        //         settled = false;
        //         pTime = pros::millis();
        //     }
        // }
        pros::Task::delay(20);

    }

    leftFront.move(0);
    leftRear.move(0);
    rightFront.move(0);
    rightRear.move(0);

    leftFront.tare_position();
    leftRear.tare_position();
    rightFront.tare_position();
    rightRear.tare_position();

}

void forwardExt(int target, float factor)
{
    line(FORWARD, target, factor);
}

void reverseExt(int target, float factor)
{
    line(REVERSE, target, factor);
}
