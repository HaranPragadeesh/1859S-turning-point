#include "../include/main.h"
#include "v5setup.hpp"
//#include "autos/autos.hpp"
//#include "newautos/newautos.hpp"
#include "natsautos/natsautos.hpp"

void autonomous()
{
  int now;

    pros::ADIGyro yawGyroT (PORT_GYRO_TOP); /* tune variable for accurate 360 turn */ // for turning
    pros::ADIGyro yawGyroB (PORT_GYRO_BOT); /* tune variable for accurate 360 turn */ // for turning

    rollGyro.reset();
    yawGyroT.reset();
    yawGyroB.reset();

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
    drive(410, 80);

    intake.move(90); // tilt cap over
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
    REST(100);
    //intake.move(-50);
    intake.move(-90);

    lift.move(127);
    dualDrive(15, 30, 0, 100, 127, 0, [](){
      intake.move(-90);
    });
    rotate(-550);
    drive(-1800, 127);




    switch(selectedAuto){
        case 1:
            // do auto 1 red close
            //new_redclose();
            //redclose_gy();
            //  redclose();
            //redclose_e();
            nats_rc();
            break;
        case 2:
            // do auto 2 red far
            //redfar();
            //redfar_gy();
            //redfar_e();
            //redfar_e_2cap();
            nats_rb();
            break;
        case 3:
            // do auto 3 blue close
            //blueclose();
            //blueclose_gy();
            //redfar_e_2cap_defense();
            nats_rb_s();
            break;
        case 4:
            nats_bc();
          //  blueclose_e();
            break;
        case 5:
          nats_bb();
          //  bluefar_e_2cap();
            break;
        case 6:
          //  bluefar_e_2cap_defense();
          nats_bb_s();
            break;
        case 7:
          //  skills19_e();
            break;
        default:
            //testauto();
            break;
    }
}
