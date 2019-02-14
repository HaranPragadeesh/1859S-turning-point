#include "../../include/main.h"
#include "../v5setup.hpp"

void skills12()
{
    forward(1250); // hit bottom flag

    reverse(1400); // reverse from bottom flag

    right(560); // turn back towards tilt cap with ball under


    fly(-35); // spin flywheel backwards in order to not get stuck

    intake.move(COMBINE_INTAKE_SPEED);
    lift.move(LIFT_UP_SPEED);

    forward(1200);   // drive to tilt cap



    REST(200);

   intake.move(-70);
   forward(300);
    ////////////////////////////////////////////////////////////////////////

    reverse(1500); // reverse to line with flags

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


        reverse(50);
        gyroClimb(127, 25, 50, 500);
        REST(200); // time inbetween climbs
        gyroClimb(127, 25, 50, 500);


}

void skills19()
{
    fly(-35); // spin flywheel backwards in order to not get stuck

    intake.move(COMBINE_INTAKE_SPEED);
    lift.move(LIFT_UP_SPEED);

    forward(1200);   // drive to tilt cap

    REST(300);

    ////////////////////////////////////////////////////////////////////////

    reverse(1200); // reverse to line with flags
    lift.move(LIFT_CLR_SPEED);
    REST(400);

    lift.move(0);
    ////////////////////////////////////////////////////////////////////////
    fly(115); // start flywheel at full speed

    left(560); // turn to line with flags

    forward(1250); // drive to red tile shoot pos

    lift.move(LIFT_UP_SPEED);
    REST(200); // lift just enough to shoot first ball
    lift.move(0);
    fly(FLYWHEEL_BOOST_SPEED);
    REST(400); // rest long enough to get to boost speed
    lift.move(LIFT_UP_SPEED);
    REST(500); // lift enouugh to shoot second ball
    lift.move(0);
    fly(0);

    REST(2000);// rest long enough to let flywheel coast slow


    forward(150); // forward enough to line with tilt cap

    right(560); // turn to tilt cap


    fly(-35); // spin flywheel backwards in order to not get stuck

    intake.move(COMBINE_INTAKE_SPEED);
    lift.move(LIFT_UP_SPEED);

    forward(1000);   // drive to tilt cap

    REST(300);

    ////////////////////////////////////////////////////////////////////////

    lift.move(0); // stop lift for wheel

    reverse(300); // reverse enough to line with gap

    left(280); // 45 degree left to clear gap

    forward(1000); // forward enough to go through gap

    left(280); // line with mid post bottom flag

    forward(600);

    reverse(400); // reverse from mid bottom flag

    left(280); // 45 degree left to reverse to mid mid flag shot spot


    fly(FLYWHEEL_IDLE);
    reverse(1000); // reverse to mid mid shot spot
    lift.move(LIFT_UP_SPEED);
    REST(500); // wait long enough for ball to clear
    lift.move(0);

    left(280); // left line with tilt cap

    lift.move(LIFT_UP_SPEED);
    forward(400);
    REST(300); // rest enough for ball to get in good spot consist
    lift.move(0);

    reverse(800); // reverse to line with shot spot

    right(560); // arb deg right shot spot deg

    reverse(1250); // reverse to back cap

    left(560); // left to tilt cap

    lift.move(LIFT_UP_SPEED);
    forward(1100); // drive to blue back tilt cap
    REST(300); // delay long enough to get good spot
    lift.move(0);

    fly(FLYWHEEL_TOP_FLAG);
    reverse(1100); // reverse to line with flags
    right(560); // line with top flag
    lift.move(LIFT_UP_SPEED);
    REST(300); // delay enough for shoot top
    lift.move(0);

    forward(400); // line with platform

    left(560);

    gyroClimb(127, 25, 50);
    REST(200); // rest inbetween climbs
    gyroClimb(127, 25, 50);





}
