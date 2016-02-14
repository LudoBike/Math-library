/*
        Math library

  Fraction class member implementation

*/


#include "fract.h"
#include <stdexcept>
#include <functional>
#include <utility>

math::Fract::Fract(int const numerator, int const denominator)
    :
    d_numerator(numerator)
{
    if (!denominator)
	throw std::domain_error("The denominator can't be setting as a null value");
    else
	d_denominator = denominator;

    manageSign();
    reduce();
}


math::Fract::Fract(float numerator, float denominator)
{
    if (!denominator)
	throw std::domain_error("The denominator can't be setting as a null value");
    
    std::function<bool(float)> is_integer = [](float x) -> bool {
	return math::extract_decimal(x) == 0; };
    
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


math::Fract::Fract(double numerator, double denominator)
{
    if (!denominator)
	throw std::domain_error("The denominator can't be setting as a null value");
    
    std::function<bool(double)> is_integer = [](double x) -> bool {
	return math::extract_decimal(x) == 0; };
    
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


math::Fract::Fract(Fract const &&tmp)
    :
    d_numerator(std::move(tmp.d_numerator)),
    d_denominator(std::move(tmp.d_denominator))
{}


math::Fract &math::Fract::operator=(Fract const &&tmp)
{
    d_numerator   = std::move(tmp.d_numerator);
    d_denominator = std::move(tmp.d_denominator);
    return *this;
}


void math::Fract::swap(Fract &other)
{
    std::swap(d_numerator,   other.d_numerator);
    std::swap(d_denominator, other.d_denominator);
}


void math::Fract::swap(Fract &&tmp)
{
    std::swap(d_numerator,   tmp.d_numerator);
    std::swap(d_denominator, tmp.d_denominator);
}


void math::Fract::manageSign()
{
    if (d_denominator < 0 and d_numerator < 0)
    {
	d_denominator = math::abs(d_denominator);
	d_numerator   = math::abs(d_numerator);
    }
    else if (d_denominator < 0)
    {
	d_denominator = math::abs(d_denominator);
	d_numerator   = -d_numerator;
    }

}


void math::Fract::reduce()
{
    int divisor = math::pgcd(d_numerator, d_denominator);
    d_numerator /= divisor;
    d_denominator /= divisor;
}
