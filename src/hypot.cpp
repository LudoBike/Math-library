/*
        Math library

  Hypothenuse with Pythagoras' theorem function implementation 
  Overloading in order:
    -float
    -double

*/

#include <libmath/math.h>

float math::hypot(float x, float y)
{
    return math::sqrt(x*x + y*y);
}

double math::hypot(double x, double y)
{
    return math::sqrt(x*x + y*y);
}
