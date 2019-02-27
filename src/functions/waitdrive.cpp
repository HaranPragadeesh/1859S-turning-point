#include "main.h"
#include "../v5setup.hpp"

void waitDrive(int dir, int speed, int waitTime)
{
  setDriveBrakes(COAST);

  rightFront.move(speed*dir);
  rightRear.move(speed*dir);
  leftFront.move(speed*dir);
  leftRear.move(speed*dir);

  pros::delay(waitTime);

  rightFront.move(0);
  rightRear.move(0);
  leftFront.move(0);
  leftRear.move(0);
}
