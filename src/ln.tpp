/*
  Math library

  Natural logarithm function implementation

*/


#include <type_traits>
#include <functional>


template<typename T>
std::enable_if_t<std::is_floating_point<T>{}, T>
    math::ln(T const x)
{
    T const e = 2.718281; // Euler's number
    T n = 0;

    while (math::pow(e, 100*n) < x)
        n++;    

    while (math::pow(e, 10*n++) < x)
        n++;    

    while (math::pow(e, n++) < x)
        n++;

    return n;
}

