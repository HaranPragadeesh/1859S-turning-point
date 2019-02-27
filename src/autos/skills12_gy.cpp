#include "../../include/main.h"
#include "../v5setup.hpp"

// 90 deg turn ~ 560

void skills12_gy()
{
    fly(FLYWHEEL_BOOST_SPEED);
     forward(1250); // hit bottom flag

     reverse(850); // reverse from bottom flag


     lift.move(LIFT_UP_SPEED);
     REST(500); // wait time for shoot
     lift.move(0);
     fly(115);

     reverse(650);

     g_right(900); // turn back towards tilt cap with ball under


     //fly(-35); // spin flywheel backwards in order to not get stuck

     intake.move(COMBINE_INTAKE_SPEED);
     lift.move(LIFT_UP_SPEED - 30);

     forward(1200);   // drive to tilt cap

     //REST(50);
     lift.move(0);

     ////////////////////////////////////////////////////////////////////////

     reverse(1200); // reverse to line with flags

     //lift.move(LIFT_CLR_SPEED);

     //REST(100);
     fly(127); // start flywheel at full speed
    // REST(300);

     lift.move(0);
     ////////////////////////////////////////////////////////////////////////

     g_left(900); // turn to line with flags

     reverse(300); //650 // *tune* reverse to line with platform to double shot

     //fly(0);
     lift.move(LIFT_UP_SPEED);
     REST(500); // wait time for shoot
     lift.move(0);

     reverse(500);

     //forward(100);

     g_right(900); // turn to climb plat

     if(autoShouldPark)
     {
       forward(1450);
       REST(500);
       forward(750);
     }

}
