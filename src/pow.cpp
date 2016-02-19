/*
        Math library

  Power function implementation 
  Overloading in order:
    -float
    -double

*/


#include <libmath/math.h>


float math::pow(float const base, int const exponent)
{
    if (exponent == 0)
        return 1;
    else if (exponent < 0)
        return 1/math::pow(base, abs(exponent));
    else
        return base*math::pow(base, (exponent - 1));
}

double math::pow(double const base, int const exponent)
{
    if (exponent == 0)
        return 1;
    else if (exponent < 0)
        return 1/math::pow(base, abs(exponent));
    else
        return base*math::pow(base, (exponent - 1));
}
