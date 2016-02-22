/*
  Math library

  Absolute value function implementation

*/


#include <type_traits>
#include <functional>


namespace math
{
    template<typename T>
    std::enable_if_t<std::is_arithmetic<T>{}, T>
        abs(T const x);

    template<typename T>
    std::enable_if_t<std::is_floating_point<T>{}, T>
        pow(T const base, T const exp);
}

#include "abs.hpp"
#include "pow.hpp"

namespace math
{
    template<typename T>
    std::enable_if_t<std::is_floating_point<T>{}, T>
        cbrt(T const cube)
    {
        auto f = [](T const cube, T const guess) -> T {
            return math::pow<T>(guess, 3) - cube;
        };
        
        auto fPrime = [](T const guess) -> T {
            return 3*math::pow<T>(guess, 2);
        };
        
        auto isCloseEnought = [](T const a, T const b) -> T {
            return math::abs<T>(a - b) < math::abs<T>(b*0.0001);
        };

        if (cube == 0 || math::abs(cube) == 1)
            return cube;
        else
        {
            float guess = 1.5;
            float new_guess = guess - f(cube, guess)/fPrime(guess);
            while (not isCloseEnought(new_guess, guess))
            {
                guess = new_guess;
                new_guess = guess - f(cube, guess)/fPrime(guess);
            }
            return new_guess;
        }
    }
}
