#include "../../include/main.h"
#include "../v5setup.hpp"

void redclose_gy()
{
     fly(FLYWHEEL_BOOST_SPEED);
     drive(1150); // hit bottom flag

     drive(-750, 90); // newReverse from bottom flag

     lift.move(LIFT_UP_SPEED);
     REST(500); // wait time for shoot
     lift.move(0);
     fly(115);

     drive(-500);

     g_right(910); // turn back towards tilt cap with ball under


     //fly(-35); // spin flywheel backwards in order to not get stuck

     intake.move(COMBINE_INTAKE_SPEED);
     lift.move(50);

     drive(1100, 90);   // drive to tilt cap
     REST(200);
     //REST(50);
     lift.move(0);

     ////////////////////////////////////////////////////////////////////////

     drive(-1100); // newReverse to line with flags

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
     REST(800); // wait time for shoot
     lift.move(0);

     drive(-375);

     //drive(100);

     g_right(910); // turn to climb plat

     if(autoShouldPark)
     {
       drive(1600);

        //gyroClimb(newForward, 75, 20, 100);
        // drive(1700);
        // drive(-50);
         //gyroClimb(127, 30, 50, 0);

     }

}
