/*
        Math library

  Square root function implementation 
  Overloading in order:
    -float
    -double

*/


#include <libmath/math.h>
#include <stdexcept>


namespace
{
    inline float f(float const square, float const guess)
    {
        return math::pow(guess, 2) - square;
    }

    inline float fPrime(float const guess)
    {
	return 2*guess;
    }

    inline bool isCloseEnough(float const a, float const b)
    {
        return math::abs(a - b) < math::abs(b*0.0001);
    }
}

float math::sqrt(float const square)
{
    if (!square)
	return square;
    else if (square < 0)
	throw std::domain_error("Root of negative number doesn't exist");
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


namespace
{
    inline double f(double const square, double const guess)
    {
        return math::pow(guess, 2) - square;
    }

    inline double fPrime(double const guess)
    {
	return 2*guess;
    }

    inline bool isCloseEnough(double const a, double const b)
    {
        return math::abs(a - b) < math::abs(b*0.0001);
    }
}

double math::sqrt(double const square)
{
    if (!square)
	return square;
    else if (square < 0)
	throw std::domain_error("Root of negative number doesn't exist");
    else
    {
	double guess = 1;
	double new_guess = guess - f(square, guess)/fPrime(guess);
	while (not isCloseEnough(new_guess, guess))
	{
	    guess = new_guess;
	    new_guess = guess - f(square, guess)/fPrime(guess);
	}
	return new_guess;
    }
}
