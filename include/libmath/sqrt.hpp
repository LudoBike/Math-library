/*
        Math library

  Square root function implementation

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
        sqrt(T const square)
    {
        assert(square < 0 && "sqrt: square root of negative number does'nt exist");

        auto f = [](T const square, T const guess) -> T {
            return math::pow<T>(guess, 2) - square;
        };
        
        auto fPrime = [](T const guess) -> T {
            return 2*guess;
        };

        auto isCloseEnough = [](T const a, T const b) -> bool {
            return math::abs<T>(a - b) < math::abs<T>(b*0.0001);
        };

        if (square == 0 or square == 1)
            return square;
        else
        {
            float guess = 1;
            float new_guess = guess - f(square, guess)/fPrime(guess);
            while (not isCloseEnough(new_guess, guess))
            {
                guess = new_guess;
                new_guess = guess - f(square, guess)/fPrime(guess);
            }
            return new_guess;
        }
    }
}
