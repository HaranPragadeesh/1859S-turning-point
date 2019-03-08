#include "main.h"
#include "../v5setup.hpp"



void liftCheck(int exitTime)
{
    bool hasBall = false;
    int freezeTime = pros::millis();


    while(!hasBall && pros::millis() < (freezeTime + exitTime))
    {
        //REST(2);
        if(limitSwitch.get_value() == 1){
            hasBall = true;
        }
        else{
            lift.move(60);
        }
    }
    lift.set_brake_mode(BRAKE);
    lift.move_velocity(0);

}
