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


    rollGyro.reset();
    yawGyro.reset();
    //testauto2();
    new_redclose();
    //skills19();
   // testauto();

    switch(selectedAuto){
        case 1:
            // do auto 1 red close
            new_redclose();
            //redclose_gy();
        //  redclose();
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
