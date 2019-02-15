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

    intake.move(-100);
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
    lift.move(LIFT_UP_SPEED - 30);

    forward(1100);   // drive to tilt cap

    REST(100);

    ////////////////////////////////////////////////////////////////////////

    lift.move(0); // stop lift for wheel

    reverse(650); // reverse enough to line with gap
    intake.move(-70);


    left(300); // 45 degree left to clear gap

    forward(890); // forward enough to go through gap

    left(315); // line with mid post bottom flag

    forward(650, 2);

    fly(FLYWHEEL_BOOST_SPEED);


    reverse(800); // reverse from mid bottom flag

    right(95, 5);

    lift.move(LIFT_UP_SPEED); // shoot mid mid
    REST(500); // wait long enough for ball to clear
    lift.move(0);

    forward(250, 3);
    left(530); // left to clear right side


    reverse(1750); // reverse to mid mid shot spot

    //right(100, 3);


    left(250); // left line with tilt cap

    intake.move(COMBINE_INTAKE_SPEED);

    lift.move(LIFT_UP_SPEED - 40);
    forward(700);
    //REST(100); // rest enough for ball to get in good spot consist
    lift.move(0);
    intake.move(-70);
    //reverse(200, 3);
    //forward(350, 3);
    fly(FLYWHEEL_IDLE);



    reverse(1100); // reverse to line with shot spot

    right(480); // arb deg right shot spot deg

    //left(80, 5);
    lift.move(LIFT_UP_SPEED); // shoot mid mid
    REST(500); // wait long enough for ball to clear
    lift.move(0);
    //right(80, 5);

    right(100, 5);

    reverse(1450); // reverse to back cap

    left(545); // left to tilt cap


    intake.move(COMBINE_INTAKE_SPEED);
    lift.move(LIFT_UP_SPEED - 40);
    forward(1100); // drive to blue back tilt cap
    REST(300); // delay long enough to get good spot
    lift.move(0);

    fly(FLYWHEEL_TOP_FLAG);

    fly(FLYWHEEL_TOP_FLAG);
    reverse(1100); // reverse to line with flags
    right(560); // line with top flag

    left(50, 5);
    lift.move(LIFT_UP_SPEED);
    REST(300); // delay enough for shoot top
    lift.move(0);
    right(50, 5);

    forward(750); // line with platform

    left(560);

    forward(1200);
    REST(300);
    forward(1000);





}
