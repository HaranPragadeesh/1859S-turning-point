#include "../include/main.h"
#include "v5setup.hpp"
//#include "autos/autos.hpp"
//#include "newautos/newautos.hpp"
#include "natsautos/natsautos.hpp"

void autonomous()
{
    pros::ADIEncoder leftRawEncoder (PORT_LEFT_TOP, PORT_LEFT_BOT, true);
    pros::ADIEncoder rightRawEncoder (PORT_RIGHT_TOP, PORT_RIGHT_BOT, false);
  //  pros::ADIGyro yawGyroT (PORT_GYRO_TOP); /* tune variable for accurate 360 turn */ // for turning
  //  pros::ADIGyro yawGyroB (PORT_GYRO_BOT); /* tune variable for accurate 360 turn */ // for turning

  //  rollGyro.reset();
  //  yawGyroT.reset();
  //  yawGyroB.reset();

    leftRawEncoder.reset();
    rightRawEncoder.reset();

/*
    turnTo(-90);
    turnTo(0);
    turnTo(90);
    turnTo(0);
    turnTo(180);
    turnTo(0);
*/


    fly(127);
    dualDrive(39, 3, 100, 110);
    REST(200);
    turnTo(-90);
    dualDrive(-2, 15, 100, 115, 115, -1, [=](){
      lift.move(127);
      intake.move(0);
      fly(0);
    });
    singleShoot(150);

    turnTo(-100);


    drive(900, 127);
    REST(50);
    drive(-1000);

    turnTo(-50);

    dualDrive(20, 45, 0, 80, 127, 0, [](){
      intake.move(-80);
    }, 0, [](){
      intake.move(-80);

    });
    drive(-200);
    turnTo(90);
    drive(1400);



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
