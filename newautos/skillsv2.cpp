#include "../../include/main.h"
#include "../v5setup.hpp"

void skillsv2()
{
    setDriveBrakes(COAST);

    intake.move(-50);
    lift.move(50);

    //intake.move(-100);
    drive(1350, 80, 1050, [=](){

        intake.move(70);
        lift.move(50);
    }, true);
    liftCheck(1500);


    fly(93);
    //line with mid double shot
    drive(-300, 70);
    rotate(-815, 70);


// shoot middle post
    REST(600);
    shoot(250, 80);
    fly(115);
    REST(1000);
    shoot(500, 127);
    shoot(250, -80);
    shoot(500, 127);
    fly(0);


    // go to back 2 ball cap
    rotate(815, 90);
    drive(-1100, 90);
    rotate(450);
    drive(830, 90);
    rotate(-450);
    intake.move(0);
    intake.set_brake_mode(BRAKE);
    REST(100);
    intake.set_brake_mode(COAST);
    drive(340, 40);

    REST(500);

    intake.move(65);
    //REST(100);
    drive(-120, 60, 40, [=](){
  //  intake.move(COMBINE_INTAKE_SPEED);
    });
    REST(200);
    drive(70, 70);
    drive(-400, 80);
    rotate(-400);

}
