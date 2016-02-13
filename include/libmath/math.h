#ifndef __MATH_H__
# define __MATH_H__


namespace math
{
    float  pow(float  base,  int exponent);
    double pow(double base,  int exponent);
    
    float  sqrt(float  square);
    double sqrt(double square);

    float  cbrt(float  cube);
    double cbrt(double cube);
    
    float  hypot(float  x, float  y);
    double hypot(double x, double y);
    
    int    abs(int    const x);
    float  abs(float  const x);
    double abs(double const x);
    
    int pgcd(int x, int y);

    float  extract_decimal(float  const x);
    double extract_decimal(double const x);
}


#endif
