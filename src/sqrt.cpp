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
    inline float f(float square, float guess)
    {
        return math::pow(guess, 2) - square;
    }

    inline float fPrime(float guess)
    {
	return 2*guess;
    }

    inline bool isCloseEnough(float a, float b)
    {
        return math::abs(a - b) < math::abs(b*0.0001);
    }
}

float math::sqrt(float square)
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
    inline double f(double square, double guess)
    {
        return math::pow(guess, 2) - square;
    }

    inline double fPrime(double guess)
    {
	return 2*guess;
    }

    inline bool isCloseEnough(double a, double b)
    {
        return math::abs(a - b) < math::abs(b*0.0001);
    }
}

double math::sqrt(double square)
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
