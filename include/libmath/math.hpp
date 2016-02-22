#ifndef __MATH_HPP__
#define __MATH_HPP__

//templates function
#include "abs.hpp"
#include "exp.hpp"
#include "fmod.hpp"
#include "pow.hpp"
#include "sqrt.hpp"
#include "cbrt.hpp"
#include "pgcd.hpp"
#include "ln.hpp"


namespace math
{

    float  hypot(float  const x, float  const y);
    double hypot(double const x, double const y);

    float  extract_decimal(float  const x);
    double extract_decimal(double const x);
    
}


#endif // __MATH_HPP__
