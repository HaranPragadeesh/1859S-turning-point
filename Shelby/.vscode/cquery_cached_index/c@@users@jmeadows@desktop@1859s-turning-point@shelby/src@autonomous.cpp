#include "../include/main.h"
#include "v5setup.hpp"
//#include "autos/autos.hpp"
//#include "newautos/newautos.hpp"
#include "natsautos/natsautos.hpp"

void autonomous()
{
     pros::ADIEncoder leftRawEncoder (PORT_LEFT_TOP, PORT_LEFT_BOT, true);
   pros::ADIEncoder rightRawEncoder (PORT_RIGHT_TOP, PORT_RIGHT_BOT, false);
    pros::ADIGyro yawGyroT (PORT_GYRO_TOP); /* tune variable for accurate 360 turn */ // for turning
    pros::ADIGyro yawGyroB (PORT_GYRO_BOT); /* tune variable for accurate 360 turn */ // for turning

    rollGyro.reset();
    yawGyroT.reset();
    yawGyroB.reset();

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
    dualDrive(40, 2, 100);
    REST(200);
    turnTo(-90);
    REST(200);
    lift.move(127);
    intake.move(127);
    REST(100);
    //flyWheel1.move_velocity(300);
    //flyWheel2.move_velocity(300);
    REST(300);
    lift.move(0);
    lift.move(0);
    turnTo(-100);
    dualDrive(48, 13, 100);
    REST(200);
    turnTo(-35);
    shoot(150);
    intake.move(0);

    drive(410, 70);

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
    intake.move(-80);
    drive(450, 60);
    turnTo(-90);
    drive(-400);



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
