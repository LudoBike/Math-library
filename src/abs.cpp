/*
        Math library

  Absolute value function implementation 
  Overloading in order:
    -int
    -float
    -double

*/


#include <libmath/math.h>


int math::abs(int const x)
{
    if (x == 0)
	return 0;
    else if (x > 0)
	return x;
    else
	return -x;
}

float math::abs(float const x)
{
    if (x == 0)
	return 0;
    else if (x > 0)
	return x;
    else
	return -x;
}

double math::abs(double const x)
{
    if (x == 0)
	return 0;
    else if (x > 0)
	return x;
    else
	return -x;
}
