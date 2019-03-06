#include "main.h"
#include "../v5setup.hpp"

void testauto()
{
     pros::ADIGyro yawGyroT (PORT_GYRO_TOP);
     pros::ADIGyro rollGyro (PORT_GYRO_BOT);



     drive(1000, 40, 500, [=](){
        fly(127);
        lift.move(50);
     });

}
