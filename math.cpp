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

int math::abs(int x)
{
    if (x == 0)
	return 0;
    else if (x > 0)
	return x;
    else
	return -x;
}

float abs(float x)
{
    if (x == 0)
	return 0;
    else if (x > 0)
	return x;
    else
	return -x;
}

double abs(double x)
{
    if (x == 0)
	return 0;
    else if (x > 0)
	return x;
    else
	return -x;
}
