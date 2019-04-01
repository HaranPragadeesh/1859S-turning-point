#include "main.h"
#include "../v5setup.hpp"

void singleOutDouble()
{
    while(limitSwitch.get_value() == 1)
    {
        lift.move(127);
    }
    REST(150);
    lift.move(0);
    lift.set_brake_mode(BRAKE);
}
