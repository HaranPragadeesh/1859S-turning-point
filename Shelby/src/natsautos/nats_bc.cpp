#include "../../include/main.h"
#include "../v5setup.hpp"
#include <iostream>


void nats_bc()
{
  fly(-20);
    intake.move(COMBINE_INTAKE_SPEED);

  drive(1250, 110, 900, [=](){
    intake.move(COMBINE_INTAKE_SPEED);
    lift.move(127);
  }, false);

  // REST(200);
  // lift.move(-80);
  // REST(400);
  // lift.move(0);

  curTime = 0;
  drive(-1200, 110, 300, [=]()
  {
      if(curTime == 0){
        curTime = pros::millis();
      }
      if(pros::millis() < curTime + 350)
      {
        lift.move(-100);
      }
      else
      {
        lift.move(0);
      }

    if(std::abs(LENCO) > 800)
    {
      fly(127);

    }
    //REST(200);
    //fly(127);
  }, false);

  rotate(930);

  lift.move(0);
  drive(-300, 110, 0, [=](){}, false);
  shoot(200);
  shoot(100, -100);
  fly(80);

  intake.move(COMBINE_INTAKE_SPEED);

  //singleOutDouble();

//  fly(80);
  //shoot(100, -100);


  drive(900, 110, 200, [=](){
    lift.move(127);
  }, false);

//  REST(100);
  lift.move(0);
  fly(90);

  rotate(145);
  drive(700);


  if(autoShouldPark)
  {
    drive(-500, 110);

    rotate(-1300);

    intake.move(-80);

    drive(955, 120, 0);

    rotate(1200, 110, 700, [=](){
      lift.move(127);
    });

    drive(-1400, 127);
  }
  else{

    drive(-700);
    intake.move(-80);
    rotate(-1050);
    drive(900);
    drive(-200);
    rotate(545);
    shoot(250);
    drive(1000, 127);
  }
}
