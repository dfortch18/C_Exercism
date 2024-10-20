#ifndef C_EXERCISM_TRIANBLE_H
#define C_EXERCISM_TRIANGLE_H

#include <stdbool.h>

typedef struct triangle
{
    double a;
    double b;
    double c;
} triangle_t;

typedef bool (*triangle_checker_t)(triangle_t);

bool triangle_is_equilateral(triangle_t);

bool triangle_is_isosceles(triangle_t);

bool triangle_is_scalene(triangle_t);

#endif