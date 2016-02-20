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

    while (math::pow<T>(e, 100*n) < x)
        n++;    

    while (math::pow<T>(e, 10*n++) < x)
        n++;    

    while (math::pow<T>(e, n++) < x)
        n++;

    return n;
}

