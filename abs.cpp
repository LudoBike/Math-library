/*
        Math library

  Absolute value function inplementation 
  Overloading in order:
    -int
    -float
    -double

*/


#include "math.h"


int math::abs(int x)
{
    if (x == 0)
	return 0;
    else if (x > 0)
	return x;
    else
	return -x;
}

float math::abs(float x)
{
    if (x == 0)
	return 0;
    else if (x > 0)
	return x;
    else
	return -x;
}

double math::abs(double x)
{
    if (x == 0)
	return 0;
    else if (x > 0)
	return x;
    else
	return -x;
}
