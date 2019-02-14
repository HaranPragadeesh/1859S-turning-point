#include "../../include/main.h"
#include "../v5setup.hpp"

// 90 deg turn ~ 560

void redclose()
{

     forward(1250); // hit bottom flag

     reverse(1400); // reverse from bottom flag

     right(560); // turn back towards tilt cap with ball under


     fly(-35); // spin flywheel backwards in order to not get stuck

     intake.move(COMBINE_INTAKE_SPEED);
     lift.move(LIFT_UP_SPEED);

     forward(1200);   // drive to tilt cap



     REST(200);


     ////////////////////////////////////////////////////////////////////////

     reverse(1200); // reverse to line with flags

     lift.move(LIFT_CLR_SPEED);

     REST(400);

     lift.move(0);
     ////////////////////////////////////////////////////////////////////////
     fly(115); // start flywheel at full speed

     left(570); // turn to line with flags

     reverse(800); //650 // *tune* reverse to line with platform to double shot

     fly(0);
     REST(0); // delay inbetween cutoff and feed
     lift.move(LIFT_UP_SPEED);
     REST(700); // wait time for shoot
     lift.move(0);


     forward(100);

     left(560); // turn to climb plat

     if(autoShouldPark)
     {
         reverse(50);
         gyroClimb(127, 30, 50, 500);

     }

}
