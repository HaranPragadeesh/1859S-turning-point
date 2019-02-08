#include <iostream>
#include "main.h"
#include "v5setup.hpp"

void setDriveBrakes(pros::motor_brake_mode_e_t mode)
{
    leftFront.set_brake_mode(mode);
    leftRear.set_brake_mode(mode);
    rightFront.set_brake_mode(mode);
    rightRear.set_brake_mode(mode);
}
