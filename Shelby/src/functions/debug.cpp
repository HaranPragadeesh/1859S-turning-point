#include "main.h"
#include "../v5setup.hpp"


void debug()
{
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
}
