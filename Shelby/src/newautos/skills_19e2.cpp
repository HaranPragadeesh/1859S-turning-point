#include "../../include/main.h"
#include "../v5setup.hpp"

void skills19_e()
{
    setDriveBrakes(COAST);

    intake.move(-50);
    lift.move(50);

    //intake.move(-100);
    drive(1350, 80, 1050, [=](){

        intake.move(70);
        lift.move(50);
    });
    liftCheck();
    lift.move(0);
    //drive(1250, 80);   // drive to tilt cap

    REST(100);

    ////////////////////////////////////////////////////////////////////////

    //lift.move(LIFT_CLR_SPEED);
    //REST(400);

    //lift.move(0);

    fly(FLYWHEEL_IDLE); // start flywheel at full speed

    drive(-1425); // reverse to line with flags

    waitDrive(REVERSE, 60, 400);

    ////////////////////////////////////////////////////////////////////////

    REST(250);

    drive(150, 60);

    rotate(-900); // turn to line with flags

    singleOutDouble();

    fly(FLYWHEEL_BOOST_SPEED);

    drive(1250); // drive to red tile shoot pos

    intake.move(-60);


    //fly(FLYWHEEL_BOOST_SPEED);
    //REST(2000);
    lift.move(127);
    REST(400);
    lift.move(0);

    // lift.move(LIFT_UP_SPEED);
    // REST(800); // lift just enough to shoot first ball
    // lift.move(0);
    // fly(FLYWHEEL_BOOST_SPEED);
    // REST(2000); // rest long enough to get to boost speed
    // lift.move(LIFT_UP_SPEED);
    // REST(500); // lift enouugh to shoot second ball
    // lift.move(0);
    // //fly(0);
    //
    // //REST(2000);// rest long enough to let flywheel coast slow


    drive(100); // forward enough to line with tilt cap


    rotate(935); // turn to tilt cap

    intake.move(-50);
    lift.move(50);

    //intake.move(-100);
    drive(1250, 80, 1050, [=](){

        intake.move(70);
        lift.move(50);
    });
    liftCheck();
    lift.move(0);

    // intake.move(70);
    // lift.move(70);
    // drive(1250);
    // liftCheck();
    // lift.move(0);


    REST(100);

    ////////////////////////////////////////////////////////////////////////


    drive(-850); // reverse enough to line with gap


    rotate(-450); // 45 degree left to clear gap

    drive(900); // forward enough to go through gap

    rotate(-450); // line with mid post bottom flag

    drive(750);

    fly(FLYWHEEL_BOOST_SPEED);


    drive(-750); // reverse from mid bottom flag

    rotate(120);

    lift.move(LIFT_UP_SPEED); // shoot mid mid
    REST(500); // wait long enough for ball to clear
    lift.move(0);

    drive(200);

    rotate(-1100);


    drive(-450); // reverse to mid mid shot spot // lineright

    //rotate(100, 3);


    rotate(450); // left line with tilt cap

    drive(-1200);

    rotate(-450);

    //drive(-500);
    //waitDrive(REVERSE, 40, 900);

    // intake.move(COMBINE_INTAKE_SPEED);
    //
    // lift.move(LIFT_UP_SPEED - 30);
    // drive(1350, 80);

    intake.move(-100);
    drive(600, 80, 500, [=](){


        intake.move(50);
        lift.move(LIFT_UP_SPEED - 20);
    });


    liftCheck();
    lift.move(0);

    //drive(-200, 3);
    //drive(350, 3);
    fly(FLYWHEEL_IDLE - 10);



    drive(-950); // reverse to line with shot spot

    intake.move(-70);

    rotate(800); // arb deg right shot spot deg

    //rotate(-80, 5);
    lift.move(LIFT_UP_SPEED); // shoot mid mid
    REST(600); // wait long enough for ball to clear
    lift.move(0);
    //rotate(80, 5);

    rotate(100);

    drive(-650); // reverse to back cap

    rotate(900); // left to tilt cap

    setDriveBrakes(HOLD);
    drive(-950, 127);
    REST(500);
    drive(-800, 127);

}
