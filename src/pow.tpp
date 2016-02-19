/*
        Math library

  Power function implementation 

*/


#include <cassert>
#include <type_traits>


template<typename T>
std::enable_if_t<std::is_arithmetic<T>{}, T>
    pow(T const base, T const exponent)
{
    assert((base == 0) ? exponent >= 0 : true &&
           "pow: zero can't be raised by negative value");
    
    T const decimal_of_exp = math::fmod(exponent, 1);

    if (exponent == 0)
        return 1;
    else if (decimal_of_exp != 0)
        return math::pow(base, exponent - decimal_of_exp) * math::exp(math::ln(base)*decimal_of_exp);
    else if (exponent < 0)
        return 1/math::pow(base, math::abs(exponent));
    else
        return base * math::pow(base, exponent - 1);
}
