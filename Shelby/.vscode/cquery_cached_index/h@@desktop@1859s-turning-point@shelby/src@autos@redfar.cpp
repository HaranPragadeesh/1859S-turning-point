#include "../../include/main.h"
#include "../v5setup.hpp"

void redfar()
{


    fly(-25);

    intake.move(COMBINE_INTAKE_SPEED);
    lift.move(LIFT_UP_SPEED);
    // startMotor(combineFront, 70);
    // startMotor(combineBack, 50);

    forward(1050);


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


        fly(110); // double shot speed

    reverse(600);


    ////////////////////////////////////////////////////////////////////////

    left(480);



    lift.move(127);
    REST(800);
    lift.move(0);
    //combineBack.stop();

    if(autoShouldPark)
    {

    right(435);
    //left(650);
    forward(430);
    left(560);

    setDriveBrakes(HOLD);


    //gyroClimb(127, 25, 50, 0);
    forward(1000);

    //gyroClimb(127, 30, 50, 0);
    }

    fly(0);
}
