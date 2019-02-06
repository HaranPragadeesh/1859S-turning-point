#include "main.h"
#include "v5setup.hpp"
#include "v5setup.cpp"

void fly(int voltage)
{
  flyWheel1.move(voltage);
  flyWheel2.move(voltage);
}
