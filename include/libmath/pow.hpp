/*
        Math library

  Power function implementation 

*/


#ifndef __POW_HPP__
#define __POW_HPP__


#include <cassert>
#include <type_traits>

namespace math
{
    template<typename T>
    std::enable_if_t<std::is_arithmetic<T>{}, T>
        abs(T const x);
    
    template<typename T>
    std::enable_if_t<std::is_arithmetic<T>{}, T>
        fmod(T numer, T denom);

    template<typename T>
    std::enable_if_t<std::is_floating_point<T>{}, T>
        exp(T const x);

    template<typename T>
    std::enable_if_t<std::is_floating_point<T>{}, T>
        ln(T const x);
}

#include "abs.hpp"
#include "fmod.hpp"
#include "exp.hpp"
#include "ln.hpp"


namespace math
{

    
    template<typename T>
    std::enable_if_t<std::is_integral<T>{}, T>
        pow(T const base, T const exp)
    {
        assert((base == 0) ? exp >= 0 : true &&
               "pow: zero can't be raised by negative value");

        if (exp == 0)
            return 1;
        else if (exp < 0)
            return 1/math::pow<T>(base, math::abs<T>(exp));
        else // Use exponentiation by squaring
            return (math::fmod<T>(exp, 2) == 0) ?
                math::pow<T>(base*base, base/2) : base*math::pow<T>(base*base, (exp - 1)/2);
    }

    template<typename T>
    std::enable_if_t<std::is_floating_point<T>{}, T>
        pow(T const base, T const exp)
    {
        assert((base == 0) ? exp >= 0 : true &&
               "pow: zero can't be raised by negative value");

        T const decimal_of_exp = math::fmod<T>(exp, 1);
    
        if (exp == 0)
            return 1;
        else if (decimal_of_exp != 0)
            return math::pow<T>(base, exp - decimal_of_exp) * math::exp<T>(math::ln<T>(base)*decimal_of_exp);
        else if (exp < 0)
            return 1/math::pow<T>(base, math::abs<T>(exp));
        else // Use exponentiation by squaring
            return (math::fmod<T>(exp, 2) == 0) ?
                math::pow<T>(base*base, base/2) : base*math::pow<T>(base*base, (exp - 1)/2);
    }

}


#endif // __POW_HPP__
