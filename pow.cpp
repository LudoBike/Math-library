/*
        Math library

  Power function inplementation 
  Overloading in order:
    -float
    -double

*/


#include "math.h"


float math::pow(float base, int exponent)
{
    if (exponent == 0)
	return 1;
    else if (exponent < 0)
	return 1/math::pow(base, abs(exponent));
    else
	return base*math::pow(base, --exponent);
}

double math::pow(double base, int exponent)
{
    if (exponent == 0)
	return 1;
    else if (exponent < 0)
	return 1/math::pow(base, abs(exponent));
    else
	return base*math::pow(base, --exponent);
}