#include "../../include/main.h"
#include "../v5setup.hpp"
#include <iostream>
void nats_rc()
{
  int curLift;

  drive(1250, 110, 0, [=](){
      intake.move(COMBINE_INTAKE_SPEED);
      lift.move(127);
  }, false);

  curLift = lift.get_position();

  drive(-1300, 110, -900, [=](){

    lift.move(-55);
    //lift.move_absolute(curLift - 100, 127);
    if(std::abs(LENCO) > 1000)
    {
      lift.move(0);
    }
    if(std::abs(LENCO) > 1050)
    {
      fly(127);
    }
    //REST(200);
    //fly(127);
  });

  rotate(-900);

  lift.move(0);
  drive(-400);
  //shoot(200);
  singleOutDouble();


  drive(1000, 110, 680, [=](){
    lift.move(127);
  }, false);
  REST(100);
  lift.move(0);

  rotate(-145);
  drive(700);

  drive(-400);

  rotate(1400);

  intake.move(-50);

  drive(800);


}
