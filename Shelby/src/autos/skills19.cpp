#include "../../include/main.h"
#include "../v5setup.hpp"

void skills19()
{
    setDriveBrakes(COAST);
    REST(500);
    fly(-35); // spin flywheel backwards in order to not get stuck

    intake.move(90);
    lift.move(LIFT_UP_SPEED);

    newForward(1300, 80);   // drive to tilt cap

    REST(300);

    ////////////////////////////////////////////////////////////////////////

    lift.move(LIFT_CLR_SPEED);
    REST(400);

    lift.move(0);

    newReverse(1300, 80); // reverse to line with flags

    ////////////////////////////////////////////////////////////////////////
    fly(80); // start flywheel at full speed

    g_left(900); // turn to line with flags

    newForward(1250); // drive to red tile shoot pos

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


    newForward(100); // forward enough to line with tilt cap


    g_right(900); // turn to tilt cap
    fly(-35); // spin flywheel backwards in order to not get stuck



    intake.move(COMBINE_INTAKE_SPEED);
    lift.move(LIFT_UP_SPEED - 30);

    newForward(1200);   // drive to tilt cap

    REST(100);

    ////////////////////////////////////////////////////////////////////////

    lift.move(0); // stop lift for wheel

    newReverse(650); // reverse enough to line with gap
    intake.move(-70);


    g_left(450); // 45 degree left to clear gap

    newForward(800); // forward enough to go through gap

    g_left(450); // line with mid post bottom flag

    newForward(700);

    fly(FLYWHEEL_BOOST_SPEED);


    newReverse(400); // reverse from mid bottom flag

    g_right(70);

    lift.move(LIFT_UP_SPEED); // shoot mid mid
    REST(500); // wait long enough for ball to clear
    lift.move(0);

    g_left(70);

    // mid mid




    g_left(425); // 520 /f/ left to clear right side


    newReverse(1700); // reverse to mid mid shot spot // lineright

    //g_right(100, 3);


    g_left(250); // left line with tilt cap

    intake.move(COMBINE_INTAKE_SPEED);

    lift.move(LIFT_UP_SPEED - 30);
    newForward(750);
    REST(100); // rest enough for ball to get in good spot consist
    lift.move(0);

    //newReverse(200, 3);
    //newForward(350, 3);
    fly(FLYWHEEL_IDLE - 10);



    newReverse(1150); // reverse to line with shot spot

    intake.move(-70);

    g_right(480); // arb deg right shot spot deg

    //g_left(80, 5);
    lift.move(LIFT_UP_SPEED); // shoot mid mid
    REST(600); // wait long enough for ball to clear
    lift.move(0);
    //g_right(80, 5);

    g_right(100, 5);

    newReverse(1400); // reverse to back cap

    g_left(570); // left to tilt cap


    intake.move(COMBINE_INTAKE_SPEED);
    lift.move(LIFT_UP_SPEED - 40);
    newForward(1150); // drive to blue back tilt cap
    REST(300); // delay long enough to get good spot
    lift.move(0);

    fly(FLYWHEEL_TOP_FLAG - 5);

    newReverse(1100); // reverse to line with flags
    g_right(530); // line with top flag

    //g_left(50, 5);
    lift.move(LIFT_UP_SPEED);
    REST(600); // delay enough for shoot top
    lift.move(0);
    g_right(50, 5);

    newForward(750); // line with platform

    g_left(590);

    newForward(1200);
    REST(300);
    newForward(800);





}
