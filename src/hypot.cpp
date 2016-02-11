/*
        Math library

  Hypothenuse with Pythagore function inplementation 
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
