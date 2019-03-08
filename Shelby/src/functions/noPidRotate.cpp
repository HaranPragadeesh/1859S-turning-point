#include <iostream>
#include "main.h"
#include "../v5setup.hpp"



void noPidRotate(int targetE, int speed)
{
    leftFront.tare_position();
    leftRear.tare_position();
    rightFront.tare_position();
    rightRear.tare_position();

    float rotateFactor = 2.45;


    int target = targetE / rotateFactor;


    int dir = target / std::abs(target);
    while(LENCO < std::abs(target) - 15)
    {
        LEFT_DRIVE(speed * dir);
        RIGHT_DRIVE(-speed * dir);
    }
    setDriveBrakes(BRAKE);
    LEFT_DRIVE(0);
    RIGHT_DRIVE(0);
}
