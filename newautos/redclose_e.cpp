#include "../../include/main.h"
#include "../v5setup.hpp"



void redclose_e()
{
     fly(FLYWHEEL_BOOST_SPEED);
     drive(1150); // hit bottom flag

     drive(-800, 90); // newReverse from bottom flag

     noPidRotate(100);
     lift.move(LIFT_UP_SPEED);
     REST(500); // wait time for shoot
     lift.move(0);
     noPidRotate(-100);

     fly(115);

     intake.move(100);

     drive(-500, 90);

     rotate(870); // turn back towards tilt cap with ball under


     //fly(-35); // spin flywheel backwards in order to not get stuck



     drive(1100, 110, 700, [=](){
         intake.move(COMBINE_INTAKE_SPEED);
         //lift.move(50);
     }, true);
     liftCheck(250);

     //drive(1100, 90);   // drive to tilt cap
     //REST(200);
     //REST(50);
     //lift.move(0);

     ////////////////////////////////////////////////////////////////////////

     drive(-1100, 110, 0, [=](){}, true); // newReverse to line with flags

     //lift.move(LIFT_CLR_SPEED);

     //REST(100);
     fly(127); // start flywheel at full speed
    // REST(300);

     lift.move(0);
     ////////////////////////////////////////////////////////////////////////

     rotate(-865); // turn to line with flags

     //drive(-300); //650 // *tune* newReverse to line with platform to double shot
     drive(-300, 110, 150, [=](){
       lift.move(LIFT_UP_SPEED);
     }, true); // newReverse to line with flags
     REST(400);
     lift.move(0);

     //fly(0);
     //shoot(800);

     fly(80);

     if(autoShouldPark)
     {



     drive(-375);

     //drive(100);

     rotate(900); // turn to climb plat


         setDriveBrakes(HOLD);
       drive(1600);

        //gyroClimb(newForward, 75, 20, 100);
        // drive(1700);
        // drive(-50);
         //gyroClimb(127, 30, 50, 0);

     }
     else{ // if no park

         setDriveBrakes(BRAKE);

         rotate(325);
         intake.move(-40);
         drive(1500, 127, 0, [=](){}, true); // newReverse to line with flags

         drive(-200);
         noPidRotate(200);
         shoot(800);

     }



     fly(0);
     intake.move(0);
     lift.move(0);

}
