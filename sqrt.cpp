/*
        Math library

  Sqare root function inplementation 
  Overloading in order:
    -float
    -double

*/


#include "math.h"


namespace
{
    double f(double square, double guess)
    {
        return math::pow(guess, 2) - square;
    }

    double fPrime(double guess)
    {
	return 2*guess;
    }

    bool isCloseEnough(double a, double b)
    {
        return math::abs(a - b) > math::abs(b*0.0001);
    }
}

float math::sqrt(float square)
{
    float guess = 1;
    float new_guess = guess - f(square, guess)/fPrime(guess);
    while (isCloseEnough(new_guess, guess))
    {
	guess = new_guess;
	new_guess = guess - f(square, guess)/fPrime(guess);
    }

    return new_guess;
}

double math::sqrt(double square)
{
    double guess = 1;
    double new_guess = guess - f(square, guess)/fPrime(guess);
    while (isCloseEnough(new_guess, guess))
    {
	guess = new_guess;
	new_guess = guess - f(square, guess)/fPrime(guess);
    }

    return new_guess;
}
