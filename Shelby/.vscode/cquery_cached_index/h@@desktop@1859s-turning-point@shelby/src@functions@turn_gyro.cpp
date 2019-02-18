#include <iostream>
#include "main.h"
#include "../v5setup.hpp"


void g_turn(int dir, int target, float factor)
{



     yawGyro.reset();

    //setDriveBrakes(BRAKE);

    float kP = .5;
    float kI = .005;
    float kD = 1;

    float errorZone = (target - 700);
    float error, errorTot, errorLast;
    float pTerm, iTerm, dTerm;
    float power;


    target = target * dir;
    float targetMin = target - 12;
    float targetMax = target + 12;
    bool ft = true;
    bool ogPass = false;
    float pTime; // pause time
    int exitDelay = 500; // millis to check exit
    int emergancyExit = 55555; // millis to emergancyExit
    bool settled = false;
    float firstPause;

    // zero motors fix if this is not correct method




     while(!settled)
    //while(yawGyro.get_value() < target) // gyro  < target
    {

        // debug();

        error = target - yawGyro.get_value();
        pros::lcd::clear_line(5);

        if(dir == 1)
        {
             if (error < errorZone) {
                errorTot += error;
                pros::lcd::set_text(5, "in zone");
            } else {
                errorTot = 0;
            }
        }
        else if(dir == -1)
        {
             if (error > -errorZone) {
                errorTot += error;
                pros::lcd::set_text(5, "in zone");
            } else {
                errorTot = 0;

            }
        }


        pTerm = error * kP;


        iTerm = kI * errorTot;
        dTerm = kD * (error - errorLast);
        errorLast = error;


        power = ((pTerm + iTerm + dTerm) * factor);


        LEFT_DRIVE(power);
        RIGHT_DRIVE(-power);

        // leftFront.move(-power);
        // leftRear.move(-power);
        //
        // rightFront.move(power);
        // rightRear.move(power);

        if(yawGyro.get_value() > targetMin && ft)
        {
            pTime = pros::millis();
            firstPause = pros::millis();
            ft = false;
            ogPass = true;
        }
        if(pros::millis() > pTime + exitDelay && ogPass)
        {
            if((yawGyro.get_value() > targetMin && yawGyro.get_value() < targetMax) or pros::millis() > firstPause + emergancyExit)
            {
                settled = true;
            }
            else
            {
                pTime = pros::millis();
            }
        }

        pros::lcd::set_text(1, " LEFT: " + std::to_string(-power) + "RIGHT: " + std::to_string(power));
        pros::lcd::set_text(3, std::to_string(yawGyro.get_value()) + " - " + std::to_string(target) + " = " + std::to_string(error));
      //  pros::lcd::set_text(2, "GYRO: " + std::to_string(yawGyro.get_value()));
      //  pros::lcd::set_text(3, "target: " + std::to_string(target));
        pros::lcd::set_text(6, "error: " + std::to_string(error));
       // pros::lcd::set_text(5, "ptime: " + std::to_string(pTime));
       // pros::lcd::set_text(6, "timer: " + std::to_string(pros::millis()));

        pros::Task::delay(20);
    }

    RIGHT_DRIVE(0);
    LEFT_DRIVE(0);

    //leftFront.move(0);
    //leftRear.move(0);
    //rightFront.move(0);
    //rightRear.move(0);

	yawGyro.reset();

}

void g_left(int target, float factor)
{
  g_turn(LEFT, target, factor);
}

void g_right(int target, float factor)
{
  g_turn(RIGHT, target, factor);
}
