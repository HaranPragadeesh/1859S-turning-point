#include "../../include/main.h"
#include "../v5setup.hpp"

void testauto2()
{
  drive(950, 70, 0, [=](){}, false);
  intake.move(50);
  drive(-300, 60, 100, [=](){
    intake.move(COMBINE_INTAKE_SPEED);
  });
  drive(200, 80);

}
