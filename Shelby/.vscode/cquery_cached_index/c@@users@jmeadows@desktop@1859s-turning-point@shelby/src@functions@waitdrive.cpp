#include "main.h"
#include "../v5setup.hpp"

void waitDrive(int dir, int speed, int waitTime)
{
  setDriveBrakes(COAST);

  rightFront.move(speed);
  rightRear.move(speed);
  leftFront.move(speed);
  leftRear.move(speed);

  pros::delay(waitTime);

  rightFront.move(0);
  rightRear.move(0);
  leftFront.move(0);
  leftRear.move(0);
}