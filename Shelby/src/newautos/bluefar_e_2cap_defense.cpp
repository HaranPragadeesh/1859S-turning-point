#include "../../include/main.h"
#include "../v5setup.hpp"

void bluefar_e_2cap_defense()
{
    fly(-25);
    drive(1250, 110, 700, [=](){
        intake.move(COMBINE_INTAKE_SPEED);
        //lift.move(50);
    }, true);
    liftCheck(250);


        drive(-750, 110, -450, [=](){
            //intake.move(COMBINE_INTAKE_SPEED);
            //lift.move(50);
            lift.move(100);

        }, true);



        REST(200);




    ////////////////////////////////////////////////////////////////////////

    rotate(520);

    liftCheck(1000);
    lift.move(-70);
    REST(350);
    lift.move(0);

    REST(500);

    fly(113); // double shot speed
    REST(3500);
    shoot(800); // double shoot
    //combineBack.stop();

    if(autoShouldPark)
    {

        rotate(-520);

        drive(350);

        rotate(900);

        drive(950, 110, 0, [=](){
            intake.move(COMBINE_INTAKE_SPEED);
            lift.move(50);
        }, true);


    setDriveBrakes(HOLD);



    }
    else{


    }

    LEFT_DRIVE_V(0);
    RIGHT_DRIVE_V(0);
    fly(0);
}
