#include "main.h"
#include "../v5setup.hpp"

void shoot(int time, int liftSpeed)
{
    lift.move(liftSpeed);
    REST(time);
    lift.move_velocity(0);
}
void singleShoot(int time, int liftSpeed)
{
    lift.move(liftSpeed);
    REST(time);
    lift.move_velocity(0);
}

void doubleShoot(int time, int liftSpeed)
{
  lift.move(liftSpeed);
  intake.move(liftSpeed);
  REST(time);
  lift.move_velocity(0);
  lift.move_velocity(0);
}
