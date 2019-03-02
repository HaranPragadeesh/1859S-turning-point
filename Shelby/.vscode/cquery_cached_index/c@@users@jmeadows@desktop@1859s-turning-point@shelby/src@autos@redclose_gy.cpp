#include "../../include/main.h"
#include "../v5setup.hpp"

void redclose_gy()
{
     fly(FLYWHEEL_BOOST_SPEED);
     drive(1250); // hit bottom flag

     drive(-850); // newReverse from bottom flag


     lift.move(LIFT_UP_SPEED);
     REST(500); // wait time for shoot
     lift.move(0);
     fly(115);

     drive(-650);

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

     drive(-500);

     //drive(100);

     g_right(900); // turn to climb plat

     if(autoShouldPark)
     {
       drive(1600);

        //gyroClimb(newForward, 75, 20, 100);
        // drive(1700);
        // drive(-50);
         //gyroClimb(127, 30, 50, 0);

     }

}



// void redclose_gy()
// {
//     fly(FLYWHEEL_BOOST_SPEED);
//      drive(1250); // hit bottom flag
//
//      drive(-850); // newReverse from bottom flag
//
//
//      lift.move(LIFT_UP_SPEED);
//      REST(500); // wait time for shoot
//      lift.move(0);
//      fly(115);
//
//      drive(-650);
//
//      g_right(900); // turn back towards tilt cap with ball under
//
//
//      //fly(-35); // spin flywheel backwards in order to not get stuck
//
//      intake.move(COMBINE_INTAKE_SPEED);
//      lift.move(LIFT_UP_SPEED - 30);
//
//      drive(1200);   // drive to tilt cap
//
//      //REST(50);
//      lift.move(0);
//
//      ////////////////////////////////////////////////////////////////////////
//
//      drive(-1200); // newReverse to line with flags
//
//      //lift.move(LIFT_CLR_SPEED);
//
//      //REST(100);
//      fly(127); // start flywheel at full speed
//     // REST(300);
//
//      lift.move(0);
//      ////////////////////////////////////////////////////////////////////////
//
//      g_left(900); // turn to line with flags
//
//      drive(-300); //650 // *tune* newReverse to line with platform to double shot
//
//      //fly(0);
//      lift.move(LIFT_UP_SPEED);
//      REST(500); // wait time for shoot
//      lift.move(0);
//
//      drive(-500);
//
//      //drive(100);
//
//      g_right(900); // turn to climb plat
//
//      if(autoShouldPark)
//      {
//        drive(1600);
//
//         //gyroClimb(newForward, 75, 20, 100);
//         // drive(1700);
//         // drive(-50);
//          //gyroClimb(127, 30, 50, 0);
//
//      }
//
// }
