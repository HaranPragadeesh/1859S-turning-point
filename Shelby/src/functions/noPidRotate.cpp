#include <iostream>
#include "main.h"
#include "../v5setup.hpp"



void noPidRotate(int targetE, int speed)
{
    int dir = targetE / std::abs(targetE);
    float rotateFactor = 2.40;


    leftFront.tare_position();
    leftRear.tare_position();
    rightFront.tare_position();
    rightRear.tare_position();



    int target = targetE / rotateFactor;


    while(std::abs(LENCO) < std::abs(target) - 15)
    {
        LEFT_DRIVE(speed * dir);
        RIGHT_DRIVE(-speed * dir);
    }
    setDriveBrakes(BRAKE);
    LEFT_DRIVE(0);
    RIGHT_DRIVE(0);
}
