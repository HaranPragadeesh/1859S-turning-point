#include "../../include/main.h"
#include "../v5setup.hpp"

void skills19()
{
    fly(-35); // spin flywheel backwards in order to not get stuck

    intake.move(COMBINE_INTAKE_SPEED);
    lift.move(LIFT_UP_SPEED);

    forward(1200);   // drive to tilt cap

    REST(300);

    ////////////////////////////////////////////////////////////////////////

    reverse(1250); // reverse to line with flags
    lift.move(LIFT_CLR_SPEED);
    REST(400);

    lift.move(0);
    ////////////////////////////////////////////////////////////////////////
    fly(80); // start flywheel at full speed

    left(590); // turn to line with flags

    forward(1250); // drive to red tile shoot pos

    lift.move(LIFT_UP_SPEED);
    REST(200); // lift just enough to shoot first ball
    lift.move(0);
    fly(FLYWHEEL_BOOST_SPEED);
    REST(2000); // rest long enough to get to boost speed
    lift.move(LIFT_UP_SPEED);
    REST(500); // lift enouugh to shoot second ball
    lift.move(0);
    fly(0);

    REST(2000);// rest long enough to let flywheel coast slow


    forward(100); // forward enough to line with tilt cap


    right(550); // turn to tilt cap
    fly(-35); // spin flywheel backwards in order to not get stuck



    intake.move(COMBINE_INTAKE_SPEED);
    lift.move(LIFT_UP_SPEED);

    forward(1100);   // drive to tilt cap

    REST(300);

    ////////////////////////////////////////////////////////////////////////

    lift.move(0); // stop lift for wheel

    reverse(650); // reverse enough to line with gap

    left(300); // 45 degree left to clear gap

    forward(870); // forward enough to go through gap

    left(345); // line with mid post bottom flag

    forward(700);

    fly(FLYWHEEL_BOOST_SPEED);


    reverse(800); // reverse from mid bottom flag

    right(70, 5);

    lift.move(LIFT_UP_SPEED); // shoot mid mid
    REST(500); // wait long enough for ball to clear
    lift.move(0);

    forward(200, 3);
    left(500); // left to clear right side


    reverse(1400); // reverse to mid mid shot spot

    //right(100, 3);







    left(350); // left line with tilt cap

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
