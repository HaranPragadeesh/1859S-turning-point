#include "../../include/main.h"
#include "../v5setup.hpp"

void bluefar_e_2cap()
{
    drive(1250, 110, 0, [=](){
        intake.move(COMBINE_INTAKE_SPEED);
        lift.move(127);
    }, true);
    liftCheck(700);
    //combineBack.stop();    // setup balls for double shot
    //REST(300);



    ////////////////////////////////////////////////////////////////////////




        drive(-750, 110, -450, [=](){
            //intake.move(COMBINE_INTAKE_SPEED);
            //lift.move(50);
            lift.move(127);

        }, true);

        lift.move(-70);
        REST(350);
        lift.move(0);

        REST(200);

        fly(115); // double shot speed



    ////////////////////////////////////////////////////////////////////////

    rotate(700);







    REST(1000);
    shoot(800); // double shoot
    //combineBack.stop();

    drive(-600);
    rotate(-725);

    intake.move(-70);
    drive(900, 95);


    if(autoShouldPark)
    {

        drive(-380);
        rotate(860);

        drive(1450, 110, 0, [=](){
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
