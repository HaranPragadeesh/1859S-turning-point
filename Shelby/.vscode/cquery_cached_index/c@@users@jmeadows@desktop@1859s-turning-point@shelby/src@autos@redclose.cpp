#include "main.h"
#include "../v5setup.hpp"

void redclose()
{

    forward(1250); // hit bottom flag

    reverse(1330); // reverse from bottom flag

   // REST(300);
    right(345); // turn back towards tilt cap with ball under


    fly(-25); // spin flywheel backwards in order to not get stuck

    intake.move(70);
    lift.move(100);



    forward(1200);   // drive to tilt cap


    pros::Task::delay(200);
    //vex::Task::delay(200);
    //REST(750); // 750 // wait long enough to get ball up
    //combineFront.stop(); // stop front combine

    //combineBack.stop();
    //combineFront.stop();

    //REST(300);



    ////////////////////////////////////////////////////////////////////////

    reverse(1050); // reverse to line with flags
    lift.move(-70);

    pros::Task::delay(400);

    lift.move(0);
    ////////////////////////////////////////////////////////////////////////
        fly(100); // start flywheel at full speed

    left(350); // turn to line with flags

    reverse(800); //650 // *tune* reverse to line with platform to double shot

    lift.move(99);
   /* shoot flag */// startMotor(combineBack, 100);
   /* shoot flag */ flyWheel1.move(0);
   /* shoot flag */ flyWheel2.move(0);
   /* shoot flag */ //REST(200); // inbetween cutoff time and shooting
   /* shoot flag */ pros::Task::delay(700);
   /* shoot flag */// combineBack.stop();



    forward(500, 1.5);

    //left(350); // turn to climb plat

    //reverse(1650, .8);
    //combineBack.stop();
    intake.move(0);
}
