/*
        Math library

  Absolute value function implementation 
  Overloading in order:
    -float
    -double

*/

#include <libmath/math.h>

namespace
{
    inline float f(float cube, float guess)
    {
	return math::pow(guess, 3) - cube;
    }

    inline float fPrime(float guess)
    {
	return 3*(math::pow(guess, 2));
    }

    inline bool isCloseEnought(float a, float b)
    {
	return math::abs(a - b) < math::abs(b*0.0001); 
    }
}

float math::cbrt(float cube)
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
    inline double f(double cube, double guess)
    {
	return math::pow(guess, 3) - cube;
    }

    inline double fPrime(double guess)
    {
	return 3*(math::pow(guess, 2));
    }

    inline bool isCloseEnought(double a, double b)
    {
	return math::abs(a - b) < math::abs(b*0.0001); 
    }
}

double math::cbrt(double cube)
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
