#include "main.h"
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

    //g_right(900);

    //REST(1200);

    //skills19();
    //new_redclose();

    // rotate(900);
    // rotate(-900);

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
            break;
        case 3:
            // do auto 3 blue close
            //blueclose();
            //blueclose_gy();
            break;
        case 4:
            // do auto 4 blue far
            //bluefar();
            //bluefar_gy();
            break;
        case 5:
            // do auto 5 12 point skills
            //skills12();
            //skills12_gy();
            break;
        case 6:
            // do 6 auto 19 point skills
            //skills17_gy();
            break;
        default:
            //testauto();
            break;
    }
}
