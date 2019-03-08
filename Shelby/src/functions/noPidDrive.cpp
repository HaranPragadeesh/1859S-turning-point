#include <iostream>
#include "main.h"
#include "../v5setup.hpp"


void noPidDrive(int target, int speed)
{

    leftFront.tare_position();
    leftRear.tare_position();
    rightFront.tare_position();
    rightRear.tare_position();

    int dir = target / std::abs(target);
    while(LENCO < std::abs(target))
    {
        LEFT_DRIVE(speed);
        RIGHT_DRIVE(speed);
    }
    setDriveBrakes(BRAKE);
    LEFT_DRIVE(0);
    RIGHT_DRIVE(0);
}
