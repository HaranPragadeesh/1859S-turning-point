#include "main.h"
#include "v5setup.hpp"

void drive(int speed, int time)
{
    leftFront.move(speed);
    rightFront.move(speed);
    pros::Task::delay(time);
}
