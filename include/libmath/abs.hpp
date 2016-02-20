/*
  Math library

  Absolute value function implementation 

*/

#ifndef __ABS_HPP__
#define __ABS_HPP__


#include <cassert>
#include <type_traits>
#include <limits>


namespace math
{
    
    template<typename T>
    std::enable_if_t<std::is_arithmetic<T>{}, T> 
        abs(T const x)
    {
        assert((std::is_integral<T>::value) ? x > std::numeric_limits<T>::min() : true &&
               "abs: pre-cond: out of range parameter a");
        return (x < 0) ? -x : x;
    }

}


#endif // __ABS_HPP__
