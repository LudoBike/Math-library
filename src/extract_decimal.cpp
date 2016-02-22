/*
        Math library

  Implementation of function wich extract the decimal part of a real number
  Overloading in order:
    -float
    -double

*/


#include <libmath/math.hpp>


float math::extract_decimal(float const x)
{
    int const integer_part = static_cast<int>(x);
    return x - integer_part;
}

double math::extract_decimal(double const x)
{
    int const integer_part = static_cast<int>(x);
    return x - integer_part;
}
