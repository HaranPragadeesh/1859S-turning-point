#include "main.h"
#include "../v5setup.hpp"

void testauto()
{
     pros::ADIGyro yawGyro (PORT_GYRO_YAW);
     pros::ADIGyro rollGyro (PORT_GYRO_ROLL);


     //        dir      tar   max
     line_test(FORWARD, 1000, 100);




}
