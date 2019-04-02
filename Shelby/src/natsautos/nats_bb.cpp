#include "../../include/main.h"
#include "../v5setup.hpp"

void nats_bb()
{
  intake.move(COMBINE_INTAKE_SPEED);

  drive(1100, 110, 900, [=](){
    intake.move(COMBINE_INTAKE_SPEED);
    lift.move(127);
  }, false);
  REST(500);

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

    if(std::abs(LENCO) > 700)
    {
      fly(110);

    }
    //REST(200);
    //fly(127);
  }, false);




    ////////////////////////////////////////////////////////////////////////

    rotate(710); // 750 shoots right




    //REST(1000);

    REST(1000);
    shoot(850); // double shoot
    //combineBack.stop();

    drive(-640);
    rotate(-800);

    intake.move(-60);
    drive(1000, 127);


    if(autoShouldPark)
    {

        drive(-380);
        rotate(900);

        drive(1450, 110, 0, [=](){
            intake.move(COMBINE_INTAKE_SPEED);
            lift.move(50);
        }, true);


    setDriveBrakes(HOLD);



    }
    else{


    }

    LEFT_DRIVE_V(0);
    RIGHT_DRIVE_V(0);
    fly(0);
}
