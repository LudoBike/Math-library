/*
  Math library

  Exponential function implementation

*/

#ifndef __EXP_HPP__
#define __EXP_HPP__


#include <type_traits>


namespace math
{

    
    template<typename T>
    std::enable_if_t<std::is_floating_point<T>{}, T>
        exp(T const x)
    {
        T k;
        T x_pow_k = 1, fact_k = 1;
        T to_return = 0;

        for (k = 0; k < 10; ++k, x_pow_k *= x, fact_k *= k)
        {
            to_return += x_pow_k/fact_k;
        }

        return to_return;
    }


}


#endif // __EXP_HPP__
