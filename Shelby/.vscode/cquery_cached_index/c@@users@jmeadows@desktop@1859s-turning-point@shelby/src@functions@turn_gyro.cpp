#include <iostream>
#include "main.h"
#include "../v5setup.hpp"


void g_turn(int dir, int target, float factor)
{
    setDriveBrakes(BRAKE);
    float kP = .15;
    float kI = .0005;
    float kD = .5;

    float errorZone = target * .1;
    float error, errorTot, errorLast;
    float pTerm, iTerm, dTerm;
    float power;

    // zero motors fix if this is not correct method
	rollGyro.reset();



    while(rollGyro.get_value() < target) // left encoder  < target
    {
        error = target - rollGyro.get_value();
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

	rollGyro.reset();

}

void g_left(int target, float factor)
{
  turn(LEFT, target, factor);
}

void g_right(int target, float factor)
{
  turn(RIGHT, target, factor);
}
