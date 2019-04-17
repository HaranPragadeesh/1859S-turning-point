
#include "../../include/main.h"
#include "../v5setup.hpp"
int now;


void worlds_rc(){

     fly(127);
     dualDrive(40, 2);
     REST(200);
     rotate(-930);
     singleShoot(150);
     rotate(-100);

     //  now = pros::millis();
     dualDrive(45, 14, 0, 127, 127, 10, [=](){
      lift.move(127);
      intake.move(127);
     });

     singleShoot(150);
     rotate(630);// rotate to cap

     intake.set_brake_mode(COAST);
     drive(405, 60);

     intake.move(60); // tilt cap over
     //REST(100);

     drive(-120, 80, 65, [=](){
     //  intake.move(COMBINE_INTAKE_SPEED);
     intake.move(100);

     });
     //  REST(200);
     REST(100);
     drive(80, 70);

     drive(-100, 127);
     singleShoot(150);
     fly(90);
     REST(200);
     //intake.move(-50);
     intake.move(-90);

     drive(500, 127, 300, [](){
      lift.move(127);
     });
     /*
     dualDrive(15, 30, 0, 100, 127, 0, [](){

      intake.move(-90);
     }, 20, [](){
      lift.move(127);
     });*/

     rotate(-550);
     drive(-1800, 127);
}
