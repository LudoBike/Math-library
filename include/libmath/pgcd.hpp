/*
        Math library

  PGCD function implementation with Euclid algorithm

*/


#ifndef __PGCD_HPP__
#define __PGCD_HPP__


#include <type_traits>


namespace math
{
    

    template<typename T>
    std::enable_if_t<std::is_integral<T>{}, T>
        pgcd(T const x, T const y)
    {
        if (x < y)
            return math::pgcd<T>(y, x);
        else
            return (y == 0) ? x : math::pgcd<T>(y, x%y);
    }


}


#endif // __PGCD_HPP__
