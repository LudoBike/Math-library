#ifndef __MATH_HPP__
#define __MATH_HPP__


//templates function
namespace math
{
    template<typename T>
    std::enable_if_t<std::is_arithmetic<T>{}, T> 
        abs(T const x);

    template<typename T>
    std::enable_if_t<std::is_arithmetic<T>{}, T>
        fmod(T numer, T denom);

    template<typename T>
    std::enable_if_t<std::is_integral<T>{}, T>
        pgcd(T const x, T const y);

    template<typename T>
    std::enable_if_t<std::is_integral<T>{}, T>
        pow(T const base, T const exp);

    template<typename T>
    std::enable_if_t<std::is_floating_point<T>{}, T>
        pow(T const base, T const exp);

    template<typename T>
    std::enable_if_t<std::is_floating_point<T>{}, T>
        sqrt(T const square);

    template<typename T>
    std::enable_if_t<std::is_floating_point<T>{}, T>
        cbrt(T const cube);

    template<typename T>
    std::enable_if_t<std::is_floating_point<T>{}, T>
        hypot(T const x, T const y);

    template<typename T>
    std::enable_if_t<std::is_floating_point<T>{}, T>
        exp(T const x);

    template<typename T>
    std::enable_if_t<std::is_floating_point<T>{}, T>
        ln(T const x);
}

#include "abs.hpp"
#include "fmod.hpp"
#include "pgcd.hpp"
#include "pow.hpp"
#include "sqrt.hpp"
#include "cbrt.hpp"
#include "hypot.hpp"
#include "exp.hpp"
#include "ln.hpp"


#endif // __MATH_HPP__
