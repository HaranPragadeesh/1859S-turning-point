#include "main.h"
#include "../v5setup.hpp"

void testauto()
{
     pros::ADIGyro yawGyro (PORT_GYRO_YAW);
     pros::ADIGyro rollGyro (PORT_GYRO_ROLL);
     REST(1500);



     g_left(450);
     REST(500);
     g_right(450);


}
