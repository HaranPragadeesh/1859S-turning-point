#include "main.h"
#include "../v5setup.hpp"


void debug()
{

  int lefto = (leftRear.get_actual_velocity() + leftFront.get_actual_velocity()) / 2;
  int righto = (rightRear.get_actual_velocity() + rightFront.get_actual_velocity()) / 2;

     pros::lcd::set_text(1, "LEFT " + std::to_string(lefto));
     pros::lcd::set_text(2, "RIGHT  " + std::to_string(righto));


     pros::lcd::set_text(4, "GYRO: " + std::to_string(yawGyro.get_value()));



/*

     pros::lcd::set_text(4,
          "RIGHTR R" + std::to_string(rightRear.get_actual_velocity()) + "    " +
          "RIGHTF R" + std::to_string(rightFront.get_actual_velocity()));
     pros::lcd::set_text(5,
          "RIGHTR V" + std::to_string(rightRear.get_voltage()) + "    " +
          "RIGHTF V" + std::to_string(rightFront.get_voltage()));
     pros::lcd::set_text(6,
          "RIGHTR T" + std::to_string(leftFront.get_torque()) + "    " +
          "RIGHTF T" + std::to_string(rightFront.get_torque()));




     pros::lcd::set_text(4,
           "L: " + std::to_string(round(std::abs(LENCO))) +
           "R: " + std::to_string(round(std::abs(RENCO))) +
           "A: " + std::to_string(round((std::abs(LENCO) + std::abs(RENCO)) / 2))
      );

     pros::lcd::set_text(5, "ClimbGy: " + std::to_string(round(rollGyro.get_value())));
     pros::lcd::set_text(6, "TurnGy: " + std::to_string(round(yawGyro.get_value())));
     pros::lcd::set_text(7,
           "RPM: " + std::to_string(round(flyWheel1.get_actual_velocity() * 15)) +
           "True RPM: " + std::to_string(round(flyWheel1.get_actual_velocity()))
      );
     */
     /*
     for(int i = 7; i <= 7; i++)
     {
          pros::lcd::clear_line(i);
     }


     pros::lcd::set_text(1,
           "L: " + std::to_string(round(std::abs(LENCO))) +
           "R: " + std::to_string(round(std::abs(RENCO))) +
           "A: " + std::to_string(round((std::abs(LENCO) + std::abs(RENCO)) / 2))
      );

     //pros::lcd::set_text(2, "ClimbGy: " + std::to_string(round(rollGyro.get_value())));
     pros::lcd::set_text(2, "TurnGy: " + std::to_string(round(yawGyro.get_value())));
     */
}
