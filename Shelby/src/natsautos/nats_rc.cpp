#include "../../include/main.h"
#include "../v5setup.hpp"
#include <iostream>
void nats_rc()
{
    intake.move(COMBINE_INTAKE_SPEED);

  drive(1250, 110, 900, [=](){
    intake.move(COMBINE_INTAKE_SPEED);
    lift.move(127);
  }, false);

  // REST(200);
  // lift.move(-80);
  // REST(400);
  // lift.move(0);


  drive(-1300, 110, 500, [=]()
  {
    lift.move(-50);
    if(std::abs(LENCO) > 600);
    if(limitSwitch.get_value() == 1)
    {
      lift.move(-50);
    }
    else{
      lift.move(0);
    }


    if(std::abs(LENCO) > 1000)
    {
      fly(127);

    }
    //REST(200);
    //fly(127);
  }, false);

  rotate(-900);

  lift.move(0);
  drive(-400, 110, 0, [=](){}, false);
  //shoot(260);
  singleOutDouble();

  fly(80);
  //shoot(100, -100);


  drive(1000, 110, 600, [=](){
    lift.move(127);
  }, false);
  REST(100);
  lift.move(0);

  rotate(-145);
  drive(700);

  if(autoShouldPark)
  {
    drive(-400);

    rotate(1300);

    intake.move(-80);

    drive(970, 120);

    rotate(-1100);

    drive(-1400, 127, 700, [=](){
      lift.move(127);
    });
  }
}
