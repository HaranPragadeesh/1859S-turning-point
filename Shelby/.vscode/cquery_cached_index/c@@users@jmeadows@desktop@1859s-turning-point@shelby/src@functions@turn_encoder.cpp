#include <iostream>
#include "main.h"
#include "../v5setup.hpp"


void turn(int dir, int target, float factor)
{
    setDriveBrakes(BRAKE);
    float kP = .4;
    float kI = .0005;
    float kD = .5;

    float errorZone = target * .1;
    float error, errorTot, errorLast;
    float pTerm, iTerm, dTerm;
    float power;

    // zero motors fix if this is not correct method
    leftFront.tare_position();
    leftRear.tare_position();
    rightFront.tare_position();
    rightRear.tare_position();



    while((std::abs(LENCO) + std::abs(RENCO) / 2) < target) // left encoder  < target
    {
        error = target - (std::abs(LENCO) + std::abs(RENCO) / 2);
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

void left(int target, float factor = 1)
{
  turn(LEFT, target, factor);
}

void right(int target, float factor = 1)
{
  turn(RIGHT, target, factor);
}
