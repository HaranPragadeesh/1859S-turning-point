#include "../../include/main.h"
#include "../v5setup.hpp"

void skills12()
{
     fly(FLYWHEEL_BOOST_SPEED);
     forward(1250); // hit bottom flag

     reverse(850); // reverse from bottom flag

     right(70, 5);
     lift.move(LIFT_UP_SPEED);
     REST(300); // wait time for shoot
     lift.move(0);
     left(75, 5);

     fly(115);

     reverse(650);

     right(570); // turn back towards tilt cap with ball under


     //fly(-35); // spin flywheel backwards in order to not get stuck

     intake.move(COMBINE_INTAKE_SPEED);
     lift.move(LIFT_UP_SPEED - 30);

     forward(1200, 2);   // drive to tilt cap


     //REST(50);
     lift.move(0);
     //forward(150, 2);
     intake.move(-COMBINE_INTAKE_SPEED - 20);
     ///forward(200, 2);


     ////////////////////////////////////////////////////////////////////////

     reverse(1250); // reverse to line with flags

     //lift.move(LIFT_CLR_SPEED);

     //REST(100);
     fly(127); // start flywheel at full speed
    // REST(300);

     lift.move(0);
     ////////////////////////////////////////////////////////////////////////

     left(570); // turn to line with flags

     reverse(400); //650 // *tune* reverse to line with platform to double shot

     //fly(0);
     lift.move(LIFT_UP_SPEED);
     REST(500); // wait time for shoot
     lift.move(0);

     reverse(400);

     //forward(100);

     right(560); // turn to climb plat

     setDriveBrakes(HOLD);
     forward(1300);
     REST(300);
     forward(1000);
    // reverse(50);
     //gyroClimb(127, 30, 50, 0);



}

void skills19()
{

}
