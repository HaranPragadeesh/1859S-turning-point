#include "../../include/main.h"
#include "../v5setup.hpp"

void testauto2()
{
  //drive(950, 70, 0, [=](){}, false);
  intake.move(50);
  //REST(100);
  drive(-120, 60, 40, [=](){
//  intake.move(COMBINE_INTAKE_SPEED);
  });
  REST(200);
  drive(150);
  //drive(-200, 60);
//  drive(100,80);
}
