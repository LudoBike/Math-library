#ifndef __MATH_H__
# define __MATH_H__


namespace math
{
    float  pow(float  const base,  int const exponent);
    double pow(double const base,  int const exponent);
    
    float  sqrt(float  const square);
    double sqrt(double const square);

    float  cbrt(float  const cube);
    double cbrt(double const cube);
    
    float  hypot(float  const x, float  const y);
    double hypot(double const x, double const y);
    
    int    abs(int    const x);
    float  abs(float  const x);
    double abs(double const x);
    
    int pgcd(int x, int y);

    float  extract_decimal(float  const x);
    double extract_decimal(double const x);
}


#endif
