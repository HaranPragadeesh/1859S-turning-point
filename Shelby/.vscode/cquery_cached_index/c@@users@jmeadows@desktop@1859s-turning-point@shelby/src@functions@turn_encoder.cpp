#include <iostream>
#include "main.h"
#include "../v5setup.hpp"


void turn(int dir, int target, float factor)
{
    //setDriveBrakes(BRAKE);
    float kP = .5;// .35;
    float kI = .005;// .0005;
    float kD = 1;// .5;

    float errorZone = target * .1;
    float error, errorTot, errorLast;
    float pTerm, iTerm, dTerm;
    float power;

    float targetMin = target - 15;
    float targetMax = target + 15;
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
    //while((std::abs(LENCO) + std::abs(RENCO) / 2) < target * .98) // left encoder  < target
    {
        int avg = (std::abs(LENCO) + std::abs(RENCO) / 2);

        error = target - avg;//(std::abs(LENCO) + std::abs(RENCO) / 2);
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

        power = ((pTerm + iTerm + dTerm) * factor) * -dir;

        leftFront.move(-power);
        leftRear.move(-power);

        rightFront.move(power);
        rightRear.move(power);

        //if((std::abs(LENCO) + std::abs(RENCO)) / 2 > targetMin && ft)
        if(avg > targetMin && ft)
        {
            pTime = pros::millis();
            ft = false;
            ogPass = true;
        }
        if(pros::millis() > pTime + exitDelay && ogPass)
        {
            if(avg > targetMin && avg < targetMax)
            {
                settled = true;
            }
            else
            {
                pTime = pros::millis();
            }
        }
        pros::lcd::set_text(2, "average:" + std::to_string(avg));
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

    leftFront.tare_position();
    leftRear.tare_position();
    rightFront.tare_position();
    rightRear.tare_position();

}

void left(int target, float factor)
{
  turn(LEFT, target, factor);
}

void right(int target, float factor)
{
  turn(RIGHT, target, factor);
}
