#include "../../include/main.h"
#include "../v5setup.hpp"

void blueclose()
{
    forward(1250); // hit bottom flag

    reverse(1450); // reverse from bottom flag

    left(580); // turn back towards tilt cap with ball under


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

    right(530); // turn to line with flags

    reverse(750); //650 // *tune* reverse to line with platform to double shot

    fly(0);
    REST(0); // delay inbetween cutoff and feed
    lift.move(LIFT_UP_SPEED);
    REST(700); // wait time for shoot
    lift.move(0);


    forward(100);

    right(560); // turn to climb plat

    if(autoShouldPark)
    {
        gyroClimb(127, 28, 50, 0);

    }

}
