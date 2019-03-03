#include "../../include/main.h"
#include "../v5setup.hpp"

void testauto2()
{
  pros::ADIGyro yawGyro (PORT_GYRO_YAW);
  pros::ADIGyro rollGyro (PORT_GYRO_ROLL);

  REST(1500);

  g_right(900);
  g_left(900);


  // drive(-1350, 100, 500, [=](){
  //    lift.move(127);
  // });

}
