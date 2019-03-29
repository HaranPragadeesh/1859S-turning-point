#include "../include/main.h"
#include "v5setup.hpp"
#include "autos/autos.hpp"
#include "newautos/newautos.hpp"

// index-
// 1- red close
// 2- red far
// 3- blue close
// 4- blue far
// 5- skills 12
// 6- skills 19

void autonomous()
{

    pros::ADIGyro yawGyroT (PORT_GYRO_TOP); /* tune variable for accurate 360 turn */ // for turning
    pros::ADIGyro yawGyroB (PORT_GYRO_BOT); /* tune variable for accurate 360 turn */ // for turning

    rollGyro.reset();
    yawGyroT.reset();
    yawGyroB.reset();

    //skillsv2();
    switch(selectedAuto){
        case 1:
            // do auto 1 red close
            //new_redclose();
            //redclose_gy();
            //  redclose();
            redclose_e();
            break;
        case 2:
            // do auto 2 red far
            //redfar();
            //redfar_gy();
            //redfar_e();
            redfar_e_2cap();
            break;
        case 3:
            // do auto 3 blue close
            //blueclose();
            //blueclose_gy();
            redfar_e_2cap_defense();
            break;
        case 4:
            blueclose_e();
            break;
        case 5:
            bluefar_e_2cap();
            break;
        case 6:
            bluefar_e_2cap_defense();
            break;
        case 7:
            skills19_e();
            break;
        default:
            //testauto();
            break;
    }
}
