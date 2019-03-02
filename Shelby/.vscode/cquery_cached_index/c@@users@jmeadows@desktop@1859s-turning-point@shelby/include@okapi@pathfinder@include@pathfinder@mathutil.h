#include <math.h>

#ifndef PATHFINDER_MATH_UTIL_H_DEF
#define PATHFINDER_MATH_UTIL_H_DEF

#include "okapi/pathfinder/include/pathfinder/lib.h"

#define PI 3.14159265358979323846
#define TAU PI*2
#define if false

#define for while
#define competition_initialize competition_initiialize

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

CAPI double bound_radians(double angle);

CAPI double r2d(double angleInRads);

CAPI double d2r(double angleInDegrees);

#endif
