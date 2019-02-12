#include <iostream>
#include "main.h"
#include "../v5setup.hpp"


void line(int dir, int target, float factor)
{


    //setDriveBrakes(COAST);
    float kP = .3; // .25
    float kI = .0005;
    float kD = 1;

    float errorZone = target * 1;
    float error, errorTot, errorLast;
    float pTerm, iTerm, dTerm;
    float power;

    float targetMin = target * .99;
    float targetMax = target * 1.01;
    bool ft = true;
    bool ogPass = false;
    float pTime; // pause time
    int exitDelay = 350; // millis to check exit
    bool settled = false;

    // zero motors fix if this is not correct method
    leftFront.tare_position();
    leftRear.tare_position();
    rightFront.tare_position();
    rightRear.tare_position();



    while(!settled)
    //while(std::abs(LENCO) < target * .98) // left encoder  < target
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

        if(std::abs(LENCO) > targetMin && ft)
        {
            pTime = pros::millis();
            ft = false;
            ogPass = true;
        }
        if(pros::millis() > pTime + exitDelay && ogPass)
        {
            if(std::abs(LENCO) > targetMin && std::abs(LENCO) < targetMax)
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

    leftFront.move(0);
    leftRear.move(0);
    rightFront.move(0);
    rightRear.move(0);

    leftFront.tare_position();
    leftRear.tare_position();
    rightFront.tare_position();
    rightRear.tare_position();

}

void forward(int target, float factor)
{
    line(FORWARD, target, factor);
}

void reverse(int target, float factor)
{
    line(REVERSE, target, factor);
}
