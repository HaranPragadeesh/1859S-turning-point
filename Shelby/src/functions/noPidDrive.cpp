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
    while(std::abs(LENCO) < std::abs(target))
    {
        LEFT_DRIVE(speed * dir);
        RIGHT_DRIVE(speed * dir);
    }
    LEFT_DRIVE(0);
    RIGHT_DRIVE(0);
}
