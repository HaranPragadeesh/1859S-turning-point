#include "../../include/main.h"
#include "../v5setup.hpp"

void testauto2()
{
  pros::ADIGyro yawGyroT (PORT_GYRO_TOP);
  pros::ADIGyro yawGyroB (PORT_GYRO_BOT);
  pros::ADIGyro rollGyro (PORT_GYRO_ROLL);

  REST(1500);

  turn_g2(900);
  //turn(-900);


  // drive(dist, maxP, tickCheck, [=](){
  //  //  stuff
  // });

}
