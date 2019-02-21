#include "main.h"
#include "v5setup.hpp"
#include "autos/autos.hpp"

// index-
// 1- red close
// 2- red far
// 3- blue close
// 4- blue far
// 5- skills 12
// 6- skills 19

void autonomous()
{


    rollGyro.reset();
    yawGyro.reset();

   // testauto();

    switch(selectedAuto){
        case 1:
            // do auto 1 red close
            redclose_gy();
        //  redclose();
            break;
        case 2:
            // do auto 2 red far
            redfar();
            break;
        case 3:
            // do auto 3 blue close
            blueclose();
            break;
        case 4:
            // do auto 4 blue far
            bluefar();
            break;
        case 5:
            // do auto 5 12 point skills
            skills12();
            break;
        case 6:
            // do 6 auto 19 point skills
            skills19();
            break;
        default:
            //testauto();
            break;
    }
}
