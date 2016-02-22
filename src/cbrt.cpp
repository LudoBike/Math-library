/*
  Math library

  Absolute value function implementation 
  Overloading in order:
  -float
  -double

*/


#include <libmath/math.hpp>

namespace
{
    inline float f(float const cube, float const guess) 
    {
        return math::pow(guess, 3.0f) - cube;
    }

    inline float fPrime(float const guess)
    {
        return 3*(math::pow(guess, 2.0f));
    }

    inline bool isCloseEnought(float const a, float const b)
    {
        return math::abs(a - b) < math::abs(b*0.0001); 
    }
}

float math::cbrt(float const cube)
{
    if (!cube || math::abs(cube) == 1)
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


namespace
{
    inline double f(double const cube, double const guess)
    {
        return math::pow(guess, 3.0) - cube;
    }

    inline double fPrime(double const guess)
    {
        return 3*(math::pow(guess, 2.0));
    }

    inline bool isCloseEnought(double const a, double const b)
    {
        return math::abs(a - b) < math::abs(b*0.0001);
    }
}

double math::cbrt(double const cube)
{
    if (!cube || math::abs(cube) == 1)
        return cube;
    else
    {
        double guess = 1.5;
        double new_guess = guess - f(cube, guess)/fPrime(guess);
        while (not isCloseEnought(new_guess, guess))
        {
            guess = new_guess;
            new_guess = guess - f(cube, guess)/fPrime(guess);
        }
        return new_guess;
    }
}
