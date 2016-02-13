/*
        Math library

  Fraction class member implementation

*/


#include "fract.h"
#include <stdexcept>

math::Fract::Fract(int const numerator, int const denominator = 1)
    :
    d_numerator(numerator)
{
    if (!denominator)
	throw domain_error("The denominator can't be setting as a null value");
    else
	d_denominator = denominator;

    manageSign();
    reduce();
}


math::Fract::Fract(float numerator, float denominator = 1)
{
    auto is_integer = [](auto x) -> bool { return math::extract_decimal(x) == 0; };
    
    while (!is_integer(numerator) or !is_integer(denominator))
    {
	numerator *= 10;
	denominator *= 10;
    }

    d_numerator   = static_cast<int>(numerator);
    d_denominator = static_cast<int>(denominator);

    manageSign();
    reduce();
}


void math::Fract::manageSign()
{
    if (d_denominator < 0 and d_numerator < 0)
    {
	d_denominator = math::abs(d_denominator);
	d_numerator   = math::abs(d_numerator);
    }
    else if (denominator < 0)
    {
	d_denominator = math::abs(d_denominator);
	d_numerator   = -d_numerator;
    }

}


void math::Fract::reduce()
{
    pgcd = math::pgcd(d_numerator, d_denominator);
    d_numerator /= pgcd;
    d_denominator /= pgcd;
}
