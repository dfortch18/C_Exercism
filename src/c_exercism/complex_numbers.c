#include "c_exercism/complex_numbers.h"
#include <math.h>

complex_t complex_add(complex_t a, complex_t b)
{
    complex_t result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

complex_t complex_sub(complex_t a, complex_t b)
{
    complex_t result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

complex_t complex_mul(complex_t a, complex_t b)
{
    complex_t result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.imag * b.real + a.real * b.imag;
    return result;
}

complex_t complex_div(complex_t a, complex_t b)
{
    complex_t result;
    double denom = b.real * b.real + b.imag * b.imag;
    result.real = (a.real * b.real + a.imag * b.imag) / denom;
    result.imag = (a.imag * b.real - a.real * b.imag) / denom;
    return result;
}

double complex_abs(complex_t x)
{
    return sqrt(x.real * x.real + x.imag * x.imag);
}

complex_t complex_conjugate(complex_t x)
{
    complex_t result;
    result.real = x.real;
    result.imag = -x.imag;
    return result;
}

double complex_real(complex_t x)
{
    return x.real;
}

double complex_imag(complex_t x)
{
    return x.imag;
}

complex_t complex_exp(complex_t x)
{
    complex_t result;
    double exp_real = exp(x.real);
    result.real = exp_real * cos(x.imag);
    result.imag = exp_real * sin(x.imag);
    return result;
}
