#include "main.h"
#include "../v5setup.hpp"

void bluefar()
{


    fly(-25);

    intake.move(COMBINE_INTAKE_SPEED);
    lift.move(LIFT_UP_SPEED);
    // startMotor(combineFront, 70);
    // startMotor(combineBack, 50);

    forward(1150);


    REST(1000); // 750
    intake.move(0);
    // combineFront.stop();
    lift.move(0);
    // combineBack.stop();
    lift.move(-70);
    //startMotor(combineBack, -70);
    REST(400);
    lift.move(0);
    //combineBack.stop();    // setup balls for double shot
    REST(300);



    ////////////////////////////////////////////////////////////////////////


        fly(115);

    reverse(700);


    ////////////////////////////////////////////////////////////////////////

    right(470);



    //startMotor(combineBack, 100);
    lift.move(127);
    //combineBack.spin(FORWARD, 100, PCT);
    //REST(100);
    //flyWheel1.move(0);
    //flyWheel2.move(0);
    //flyWheel.stop();
    //flyWheel2.stop();
    //REST(100); // inbetween cutoff time and shooting
    REST(800);
    lift.move(0);
    //combineBack.stop();


    left(650);
    reverse(520, 1.25);
    right(560);

    setDriveBrakes(BRAKE);


    //gyroClimb(127, 25, 50, 0);
    //reverse(1200);
    gyroClimb(100, 25, 100, 0);
}



void bluefarNP()
{


    fly(-25);

    intake.move(COMBINE_INTAKE_SPEED);
    lift.move(LIFT_UP_SPEED);
    // startMotor(combineFront, 70);
    // startMotor(combineBack, 50);

    forward(1150);


    REST(1000); // 750
    intake.move(0);
    // combineFront.stop();
    lift.move(0);
    // combineBack.stop();
    lift.move(-70);
    //startMotor(combineBack, -70);
    REST(400);
    lift.move(0);
    //combineBack.stop();    // setup balls for double shot
    REST(300);



    ////////////////////////////////////////////////////////////////////////


        fly(115);

    reverse(700);


    ////////////////////////////////////////////////////////////////////////

    right(470);



    //startMotor(combineBack, 100);
    lift.move(127);
    //combineBack.spin(FORWARD, 100, PCT);
    //REST(100);
    //flyWheel1.move(0);
    //flyWheel2.move(0);
    //flyWheel.stop();
    //flyWheel2.stop();
    //REST(100); // inbetween cutoff time and shooting
    REST(800);
    lift.move(0);
    //combineBack.stop();


    //left(650);
    //reverse(520, 1.25);
    //right(560);

    //setDriveBrakes(BRAKE);


    //gyroClimb(127, 25, 50, 0);
    //reverse(1200);
    //gyroClimb(100, 25, 100, 0);
}
