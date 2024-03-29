#include "../../include/main.h"
#include "../v5setup.hpp"

// 90 deg turn ~ 560

void skills17_gy()
{
  setDriveBrakes(COAST);
  LEFT_DRIVE_V(0);
  RIGHT_DRIVE_V(0);
  REST(300);


  forward(1250);
  reverse(1400);

  fly(-25);
  intake.move(COMBINE_INTAKE_SPEED);
  lift.move(LIFT_UP_SPEED);

  rotate(900);

  waitDrive(REVERSE, 40, 700);

  forward(1450);

  REST(2000);
  lift.move(0);
  // combineBack.stop();
  intake.move(0);
  lift.move(-70);
  intake.move(0);
  //startMotor(combineBack, -70);
  REST(400);
  lift.move(0);


  fly(FLYWHEEL_IDLE - 5);
  reverse(1400);

  rotate(-930);

  reverse(150, 2);

  lift.move(LIFT_UP_SPEED);
  REST(200);
  lift.move(-30);
  REST(100);


  fly(FLYWHEEL_BOOST_SPEED);
  REST(2000);


  lift.move(LIFT_UP_SPEED);
  REST(1000);
  lift.move(0);
  REST(150);
  fly(FLYWHEEL_TOP_FLAG);

  reverse(1250); // back

  rotate(900);

  //waitDrive(REVERSE, 40, 700);

  intake.move(COMBINE_INTAKE_SPEED);
  lift.move(LIFT_UP_SPEED - 30);
  forward(1200);

  REST(50);
  lift.move(0);
  // combineBack.stop();
  intake.move(0);

  reverse(650);


  ////////////////////////////////////////////////////////////////////////

  rotate(-750);



  lift.move(127);
  REST(800);
  lift.move(0);

  rotate(750);

  reverse(600);

  rotate(-900);

  forward(715);

  rotate(900);

  forward(1200);
  REST(500);
  forward(900);



}
