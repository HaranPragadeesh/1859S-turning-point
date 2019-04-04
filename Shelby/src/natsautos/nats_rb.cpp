#include "../../include/main.h"
#include "../v5setup.hpp"
#include <iostream>


void nats_rb(){
  fly(-10);

  intake.move(COMBINE_INTAKE_SPEED);

  drive(1100, 110, 900, [=](){
    intake.move(COMBINE_INTAKE_SPEED);
    lift.move(127);
  }, false);
  REST(250);

  // REST(200);
  // lift.move(-80);
  // REST(400);
  // lift.move(0);

  curTime = 0;
  drive(-750, 110, 150, [=]()
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

    if(std::abs(LENCO) > 600)
    {
      fly(113);

    }
    //REST(200);
    //fly(127);
  }, false);




    ////////////////////////////////////////////////////////////////////////

    rotate(-710);




    //REST(1000);

    REST(750);
    shoot(750); // double shoot
    fly(109);
    //combineBack.stop();

    drive(-385);
    rotate(900);
    intake.move(0);
    drive(790, 80); // go to back cap

  //  REST(50); // 120

    intake.move(65); // tilt cap over
    //REST(100);

    drive(-120, 80, 65, [=](){
  //  intake.move(COMBINE_INTAKE_SPEED);
  intake.move(100);

    });
  //  REST(200);
    REST(100);
    drive(80, 70);

    drive(-100, 127);
    rotate(-800);
  //  shoot(300);
    lift.move(127);

/* // move to back
    drive(-640);
    rotate(-800);

    intake.move(-60);
    drive(1000, 127);

*/
    if(autoShouldPark)
    {
    //  lift.move(0);
      REST(600);
      lift.move(0);
      rotate(-320);
      setDriveBrakes(HOLD);
      drive(1600, 127);
    }
    else{
      REST(300);
      //drive(300, 50, 0, [](){}, false);


    }
}
