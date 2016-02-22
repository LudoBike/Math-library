/*
        Math library

  Hypothenuse with Pythagoras' theorem function implementation

*/


#ifndef __HYPOT_HPP__
#define __HYPOT_HPP__


#include <type_traits>


namespace math
{
    template<typename T>
    std::enable_if_t<std::is_floating_point<T>{}, T>
        sqrt(T const square);
}

#include "sqrt.hpp"


namespace math
{

    template<typename T>
    std::enable_if_t<std::is_floating_point<T>{}, T>
        hypot(T const x, T const y)
    {
        return math::sqrt<T>(x*x, y*y);
    }
    
}


#endif // __HYPOT_HPP__
