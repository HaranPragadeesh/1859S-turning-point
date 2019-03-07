#include "../../include/main.h"
#include "../v5setup.hpp"

void skills19()
{
    setDriveBrakes(COAST);


    fly(FLYWHEEL_TOP_FLAG + 5);
    REST(2000);
    lift.move(LIFT_UP_SPEED);
    REST(500); // lift just enough to shoot first ball

    lift.move(0);

    //drive(-100);
    g_right(920);

    //waitDrive(REVERSE, 40, 700);

    // //REST(500);
    // //fly(-45); // spin flywheel backwards in order to not get stuck

    // // intake.move(50);
    // // lift.move(LIFT_UP_SPEED);

    intake.move(-100);
    drive(1350, 80, 1050, [=](){

        intake.move(50);
        lift.move(LIFT_UP_SPEED - 20);
    });
    lift.move(0);
    //drive(1250, 80);   // drive to tilt cap

    REST(100);

    ////////////////////////////////////////////////////////////////////////

    //lift.move(LIFT_CLR_SPEED);
    //REST(400);

    //lift.move(0);

    drive(-1350, 80); // reverse to line with flags

    waitDrive(REVERSE, 60, 1000);

    ////////////////////////////////////////////////////////////////////////
    fly(80); // start flywheel at full speed

    REST(250);

    drive(100, 60);

    g_left(900); // turn to line with flags

    drive(1250); // drive to red tile shoot pos

    intake.move(-60);
    lift.move(LIFT_UP_SPEED);
    REST(800); // lift just enough to shoot first ball
    lift.move(0);
    // fly(FLYWHEEL_BOOST_SPEED);
    // REST(2000); // rest long enough to get to boost speed
    // lift.move(LIFT_UP_SPEED);
    // REST(500); // lift enouugh to shoot second ball
    // lift.move(0);
    // //fly(0);
    //
    // //REST(2000);// rest long enough to let flywheel coast slow


    drive(100); // forward enough to line with tilt cap


    g_right(900); // turn to tilt cap
    //fly(-35); // spin flywheel backwards in order to not get stuck

    intake.move(-70);

    drive(1200, 90, 1050, [=](){
        intake.move(50);
        lift.move(LIFT_UP_SPEED - 40);
    });

    //intake.move(COMBINE_INTAKE_SPEED);
    //___int_size_t_hlift.move(LIFT_UP_SPEED - 30);

    //drive(1200, 80);   // drive to tilt cap

    REST(100);

    ////////////////////////////////////////////////////////////////////////

    lift.move(0); // stop lift for wheel

    drive(-750); // reverse enough to line with gap
    intake.move(-70);


    g_left(450); // 45 degree left to clear gap

    drive(950); // forward enough to go through gap

    g_left(450); // line with mid post bottom flag

    drive(750);

    fly(FLYWHEEL_BOOST_SPEED);


    drive(-750); // reverse from mid bottom flag

    g_right(120);

    lift.move(LIFT_UP_SPEED); // shoot mid mid
    REST(500); // wait long enough for ball to clear
    lift.move(0);

    drive(200);

    g_left(1050);


    drive(-450); // reverse to mid mid shot spot // lineright

    //g_right(100, 3);


    g_right(450); // left line with tilt cap

    drive(-1200);

    g_left(450);

    drive(-500);
    waitDrive(REVERSE, 40, 900);

    // intake.move(COMBINE_INTAKE_SPEED);
    //
    // lift.move(LIFT_UP_SPEED - 30);
    // drive(1350, 80);

    intake.move(-100);
    drive(1350, 80, 1050, [=](){

        intake.move(50);
        lift.move(LIFT_UP_SPEED - 20);
    });

    REST(100); // rest enough for ball to get in good spot consist
    lift.move(0);

    //drive(-200, 3);
    //drive(350, 3);
    fly(FLYWHEEL_IDLE - 10);



    drive(-950); // reverse to line with shot spot

    intake.move(-70);

    g_right(800); // arb deg right shot spot deg

    //g_left(80, 5);
    lift.move(LIFT_UP_SPEED); // shoot mid mid
    REST(600); // wait long enough for ball to clear
    lift.move(0);
    //g_right(80, 5);

    g_right(100);

    drive(-600); // reverse to back cap

    g_right(900); // left to tilt cap

    drive(-900);
    REST(500);
    drive(-900);

}
