#include <iostream>
#include "main.h"
#include "../v5setup.hpp"
//#include <functional>


void drive( /*int dir,*/ int targetM, int maxPower, int callbackTicks, std::function<void()> callback)
{
    //int minPower = 15;

    int target = std::abs(targetM);
    int dir;
    if(targetM > 0)
    {
      dir = 1;
    }
    if(targetM < 0){
      dir = -1;
    }
    setDriveBrakes(COAST);

    // distance pid stuff
    float kP = .5; //.50;//.3; // .25
    float kI = .005;//.0005;
    float kD = 1;//1;

    float errorZone = 150; // target * .1;
    float error, errorTot, errorLast;
    float pTerm, iTerm, dTerm;
    float power;


    // line pid stuff
    float kPl = .75;
    float errorl;
    float pTerml;
    float masterPower;
    float slavePower;


    // target zone
    float targetMin = target - 20;
    float targetMax = target + 20;

    // first run stuff
    bool ft = true;
    bool ogPass = false;

    // timer stuff
    float pTime; // pause time
    int exitDelay = 400;
    //settle
    bool settled = false;

    // zero motors
    leftFront.tare_position();
    leftRear.tare_position();
    rightFront.tare_position();
    rightRear.tare_position();



    while(!settled)
    {
      if(std::abs(LENCO) > callbackTicks)
      {
        callback();
      }

         // find error from distance
        error = target - std::abs(LENCO);

        // find error in encoders
        errorl = std::abs(LENCO) - std::abs(RENCO);

        // find i val if in encoder range
        if (error < errorZone) {
            errorTot += error;
        } else {
            errorTot = 0;
        }

        // pid calc
        pTerm = error * kP; // distance from target * kp
        iTerm = kI * errorTot; // total error 'only when in zone' * kI
        dTerm = kD * (error - errorLast); // new error gap
        errorLast = error; // set last error after calcs

        // set power to pid out mult by dir in order to find direction
        power = (pTerm + iTerm + dTerm) * dir;

        // if power is above the max dont let it be
        if(dir == 1 && power > maxPower)
        {
          power = maxPower;

        }
        if(dir == -1 && power < -maxPower)
        {
          power = -maxPower;
        }


        // if(power < minPower && error > 0)
        // {
        //   power = minPower;
        // }
        // if(power > -minPower && error < 0)
        // {
        //   power = -minPower;
        // }



        // set pid stuff for keeping in line
        pTerml = errorl * (kPl * dir);

        // set master (left) power to normal power after maxing
        masterPower = power;
        //set slave power to the master power + the pid calc
        slavePower = masterPower + pTerml;

        // drive the motors
        LEFT_DRIVE(masterPower); // drive master
        RIGHT_DRIVE(slavePower); // drive slave



        // if its the first time its passed the target min the set the
        // first check timer disable the first try and pass OG
        if(std::abs(LENCO) > targetMin && ft)
        {
            pTime = pros::millis();
            ft = false;
            ogPass = true;
        }
        // check every 'exitDelay' if its in the alloted zone
        // if its in the zone then 'settle' otherwise reset timer
        if(pros::millis() > pTime + exitDelay && ogPass)
        {
            if(std::abs(LENCO) > targetMin && std::abs(LENCO) < targetMax)
            {
                settled = true;
            }
            else
            {
                pTime = pros::millis();
            }
        }

        // // debugging
        // pros::lcd::set_text(2, "LENCO:" + std::to_string(std::abs(LENCO))); // outputs left encoder
        // pros::lcd::set_text(3, "target:" + std::to_string(target)); // outputs target encoder clicks
        // pros::lcd::set_text(4, "error:" + std::to_string(error)); // outputs clicks to go
        // pros::lcd::set_text(5, "ptime:" + std::to_string(pTime)); // time pauses after reaching clicks
        // pros::lcd::set_text(6, "timer:" + std::to_string(pros::millis())); // total time since program start

     // master motor debug
     //    pros::lcd::set_text(1,
     //         "LENCO:" + std::to_string(std::abs(LENCO)) +
     //         " PowerL: " + std::to_string(masterPower)); // outputs master encoder
     //
     // // slave motor debug
     //    pros::lcd::set_text(2,
     //         "RENCO:" + std::to_string(std::abs(RENCO)) +
     //         " PowerR: " + std::to_string(slavePower)); // outputs slave encoder
     //
     //
     //    pros::lcd::set_text(3, "ERROR:" + std::to_string(std::abs(LENCO) - std::abs(RENCO))); // outputs master - slave
     //
     //    pros::lcd::set_text(5,
     //         "p: " + std::to_string(pTerm) +
     //         "i: " + std::to_string(iTerm) +
     //         "d: " + std::to_string(dTerm)
     //    );
     //
     //    pros::lcd::set_text(6,
     //         "line p: " + std::to_string(pTerml)
     //    );


        //save brain cells
        pros::Task::delay(20);
    }

    // set drive vel to 0 for brake mode to work if wanted
    LEFT_DRIVE_V(0);
    RIGHT_DRIVE_V(0);

    // reset encoders just in case
    leftFront.tare_position();
    leftRear.tare_position();
    rightFront.tare_position();
    rightRear.tare_position();

}

void newForward(int target, int maxPower, float factor){
  //line_test(FORWARD, target, maxPower);
  line(FORWARD, target, factor);
}
void newReverse(int target, int maxPower, float factor){
  //line_test(REVERSE, target, maxPower);
  line(REVERSE, target, factor);
}
