#include "main.h"
#include "../v5setup.hpp"

void testauto()
{
     pros::ADIGyro yawGyro (PORT_GYRO_YAW);
     pros::ADIGyro rollGyro (PORT_GYRO_ROLL);



     line_test(1000, 40, 500, [=](int flywheel){
        fly(127);
        lift.move(50);

     });

}
