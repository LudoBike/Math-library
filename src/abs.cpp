/*
        Math library

  Absolute value function implementation 

*/


#include <libmath/math.h>
#include <cassert>
#include <type_traits>
#include <limits>


template<typename T>
std::enable_if_t<std::is_arithmetic<T>{}, T> 
    math::abs(T const x)
{
    assert((std::is_integral<T>::value) ? x > std::numeric_limits<T>::min() : true &&
	    "abs: pre-cond: out of range parameter a");
    return (x < 0) ? -x : x;
}
