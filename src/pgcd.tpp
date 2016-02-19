/*
        Math library

  PGCD function implementation with Euclid algorithm

*/


#include <type_traits>


template<typename T>
std::enable_if_t<std::is_integral<T>{}, T>
    math::pgcd(T const x, T const y)
{
    if (x < y)
        return math::pgcd(y, x);
    else
        return (y == 0) ? x : math::pgcd(y, x%y);
}
