/*
        Math library

  Hypothenuse with Pythagoras' theorem function implementation
  Overloading in order:
    -float
    -double

*/

#include <libmath/math.hpp>

float math::hypot(float const x, float const y)
{
    return math::sqrt(x*x + y*y);
}

double math::hypot(double const x, double const y)
{
    return math::sqrt(x*x + y*y);
}
