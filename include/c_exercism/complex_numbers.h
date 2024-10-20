#ifndef C_EXERCISM_COMPLEX_NUMBERS_H
#define C_EXERCISM_COMPLEX_NUMBERS_H

typedef struct _complex_number
{
    double real;
    double imag;
} complex_t;

complex_t complex_add(complex_t, complex_t);

complex_t complex_sub(complex_t, complex_t);

complex_t complex_mul(complex_t, complex_t);

complex_t complex_div(complex_t, complex_t);

double complex_abs(complex_t);

complex_t complex_conjugate(complex_t);

double complex_real(complex_t);

double complex_imag(complex_t);

complex_t complex_exp(complex_t);

#endif