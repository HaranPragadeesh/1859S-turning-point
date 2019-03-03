#include "../../include/main.h"
#include "../v5setup.hpp"

void new_redclose()
{
  fly(FLYWHEEL_BOOST_SPEED);
  drive(1200, 100);
  drive(-1350, 100, 450, [=](){
     lift.move(127);
  });

  lift.move(0);

       g_right(900); // turn back towards tilt cap with ball under


       //fly(-35); // spin flywheel backwards in order to not get stuck

       intake.move(COMBINE_INTAKE_SPEED);
       lift.move(LIFT_UP_SPEED - 30);

       drive(1200);   // drive to tilt cap

       //REST(50);
       lift.move(0);

       ////////////////////////////////////////////////////////////////////////

       drive(-1200); // newReverse to line with flags

       //lift.move(LIFT_CLR_SPEED);

       //REST(100);
       fly(127); // start flywheel at full speed
      // REST(300);

       lift.move(0);
       ////////////////////////////////////////////////////////////////////////

       g_left(900); // turn to line with flags

       drive(-300); //650 // *tune* newReverse to line with platform to double shot

       //fly(0);
       lift.move(LIFT_UP_SPEED);
       REST(500); // wait time for shoot
       lift.move(0);

       drive(-350);

       //drive(100);

       g_right(900); // turn to climb plat

       if(autoShouldPark)
       {
         drive(1700);

       }

}
