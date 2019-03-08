#include "main.h"
#include "../v5setup.hpp"

void shoot(int time, int liftSpeed)
{
    lift.move(liftSpeed);
    REST(time);
    lift.move(0);
}
