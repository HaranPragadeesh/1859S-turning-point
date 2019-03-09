#include "../../include/main.h"
#include "../v5setup.hpp"

void redfar_e()
{
    drive(1100, 110, 0, [=](){
        intake.move(COMBINE_INTAKE_SPEED);
        lift.move(50);
    }, true);
    liftCheck(250);
    //combineBack.stop();    // setup balls for double shot
    //REST(300);



    ////////////////////////////////////////////////////////////////////////




        drive(-650, 110, -450, [=](){
            //intake.move(COMBINE_INTAKE_SPEED);
            //lift.move(50);
            fly(115); // double shot speed

        }, true);


    ////////////////////////////////////////////////////////////////////////

    rotate(-715);



    lift.move(127);
    REST(800);
    lift.move(0);
    //combineBack.stop();

    if(autoShouldPark)
    {

    rotate(715);

    forward(430);
    rotate(-900);


    setDriveBrakes(HOLD);


    //gyroClimb(127, 25, 50, 0);

    drive(900, 110, 0, [=](){
        intake.move(COMBINE_INTAKE_SPEED);
        lift.move(50);
    }, true);

    //gyroClimb(127, 30, 50, 0);
    }

    LEFT_DRIVE_V(0);
    RIGHT_DRIVE_V(0);
    fly(0);
}
