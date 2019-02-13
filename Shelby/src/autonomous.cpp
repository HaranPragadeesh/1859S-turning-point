#include "main.h"
#include "v5setup.hpp"
#include "autos/autos.hpp"

// index-
// 1- red close
// 2- red far
// 3- blue close
// 4- blue far
// 5- skills

void autonomous()
{
    //left(560);
    //redfar();
    //testauto();
    switch(selectedAuto){


/////////////////////////////////////////////////////////////////////////////////// BLUE CLOSE
        case 1:
            // do auto 1 red close
            redclose();
            // if(autoShouldPark){
            //     redclose();
            // }
            // else {
            //     redcloseNP();
            // }
            break;
/////////////////////////////////////////////////////////////////////////////////// BLUE CLOSE

/////////////////////////////////////////////////////////////////////////////////// BLUE FAR
        case 2:
            // do auto 2 red far
            redfar();
            // if(autoShouldPark){
            //     redfar();
            // }
            // else {
            //     redfarNP();
            // }
            break;
/////////////////////////////////////////////////////////////////////////////////// BLUE FAR

/////////////////////////////////////////////////////////////////////////////////// RED CLOSE
        case 3:
            // do auto 3 blue close
            blueclose();
            // if(autoShouldPark){
            //     blueclose();
            // }
            // else {
            //     bluecloseNP();
            // }
            break;
/////////////////////////////////////////////////////////////////////////////////// RED CLOSE

/////////////////////////////////////////////////////////////////////////////////// RED FAR
        case 4:
            // do auto 4 blue far
            bluefar();
            // if(autoShouldPark){
            //     bluefar();
            // }
            // else {
            //     bluefarNP();
            // }
            break;
/////////////////////////////////////////////////////////////////////////////////// RED FAR

/////////////////////////////////////////////////////////////////////////////////// SKILLS
        case 5:
            // do auto 5  skills
            skills();
            break;
/////////////////////////////////////////////////////////////////////////////////// SKILLS

        default:
            //testauto();
            break;

    }
}
