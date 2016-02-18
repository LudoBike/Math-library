#ifndef __MATH_H__
# define __MATH_H__

#include <type_traits>

namespace math
{
    // Classes
    class Fract;

    // Functions
    float  pow(float  const base,  int const exponent);
    double pow(double const base,  int const exponent);
    
    float  sqrt(float  const square);
    double sqrt(double const square);

    float  cbrt(float  const cube);
    double cbrt(double const cube);
    
    float  hypot(float  const x, float  const y);
    double hypot(double const x, double const y);
    
    template<typename T>
    std::enable_if_t<std::is_arithmetic<T>{}, T>
	abs(T const x);
    
    template<typename T>
    std::enable_if_t<std::is_integral<T>{}, T>
	pgcd(T const x, T const y);

    float  extract_decimal(float  const x);
    double extract_decimal(double const x);

    template<typename T>
    std::enable_if_t<std::is_floating_point<T>{}, T>
	fmod(T numer, T denom);
}

#include "../../src/abs.tpp"
#include "../../src/pgcd.tpp"
#include "../../src/fmod.tpp"

#endif
