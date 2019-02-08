#include <iostream>
 #include"../include/main.h"
 #include"../include/v5setup.hpp"
 #include"../autos/autos.hpp"

// index-
// 1- blue close
// 2- blue far
// 3- red close
// 4- red far
// 5- skills



void autonomous()
{
    switch(selectedAuto){


/////////////////////////////////////////////////////////////////////////////////// BLUE CLOSE
        case 1:
            // do auto 1
            if(autoShouldPark){
                // #include"../autos/blue/blue_close.cpp"
            }
            else {
                // #include"../autos/blue/blue_close_np.shelby"
            }
            break;
/////////////////////////////////////////////////////////////////////////////////// BLUE CLOSE

/////////////////////////////////////////////////////////////////////////////////// BLUE FAR
        case 2:
            // do auto 1
            if(autoShouldPark){
                // #include"../autos/blue/blue_far.shelby"
            }
            else {
                // #include"../autos/blue/blue_far_np.shelby"
            }
            break;
/////////////////////////////////////////////////////////////////////////////////// BLUE FAR

/////////////////////////////////////////////////////////////////////////////////// RED CLOSE
        case 3:
            // do auto 1
            if(autoShouldPark){
                // #include"../autos/red/red_close.shelby"
            }
            else {
                // #include"../autos/red/red_close_np.shelby"
            }
            break;
/////////////////////////////////////////////////////////////////////////////////// RED CLOSE

/////////////////////////////////////////////////////////////////////////////////// RED FAR
        case 4:
            // do auto 1
            if(autoShouldPark){
                // #include"../autos/red/red_far.shelby"
            }
            else {
                // #include"../autos/red/red_far_np.shelby"
            }
            break;
/////////////////////////////////////////////////////////////////////////////////// RED FAR

/////////////////////////////////////////////////////////////////////////////////// SKILLS
        case 5:
            // do auto 1
            // #include"../autos/skills/skills.shelby"
            break;
/////////////////////////////////////////////////////////////////////////////////// SKILLS

        default:
            // NO AUTO IS SELECTED
            // #include"../autos/test/testauto.shelby"
            testauto();
            //line(2000);
            break;

    }
}
