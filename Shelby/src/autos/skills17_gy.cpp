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

  g_right(900);

  waitDrive(REVERSE, 40, 700);

  forward(1400);

  REST(1000);
  lift.move(0);
  // combineBack.stop();
  intake.move(0);
  lift.move(-70);
  intake.move(0);
  //startMotor(combineBack, -70);
  REST(400);
  lift.move(0);


  fly(FLYWHEEL_IDLE - 5);
  reverse(1350);

  g_left(930);

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

  g_right(900);

  waitDrive(REVERSE, 40, 700);

  intake.move(COMBINE_INTAKE_SPEED);
  lift.move(LIFT_UP_SPEED - 30);
  forward(1250);

  REST(50);
  lift.move(0);
  // combineBack.stop();
  intake.move(0);

  reverse(600);


  ////////////////////////////////////////////////////////////////////////

  g_left(730);



  lift.move(127);
  REST(800);
  lift.move(0);

  g_right(730);

  reverse(600);

  g_left(900);

  forward(700);

  g_right(900);

  forward(1200);
  REST(500);
  forward(900);



}
