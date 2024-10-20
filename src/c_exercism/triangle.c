#include "c_exercism/triangle.h"

static bool triangle_is_valid(triangle_t);

bool triangle_is_equilateral(triangle_t triangle)
{
    if(!triangle_is_valid(triangle)) return false;
    return triangle.a == triangle.b && triangle.b == triangle.c;
}

bool triangle_is_isosceles(triangle_t triangle)
{
    if (!triangle_is_valid(triangle)) return false;
    if (triangle_is_equilateral(triangle)) return true;
    return (triangle.a == triangle.b && triangle.a != triangle.c) ||
        (triangle.a == triangle.c && triangle.a != triangle.b) ||
        (triangle.b == triangle.c && triangle.a != triangle.c);
}

bool triangle_is_scalene(triangle_t triangle)
{
    if (!triangle_is_valid(triangle)) return false;
    return triangle.a != triangle.b && triangle.a != triangle.c && triangle.b != triangle.c;
}

static bool triangle_is_valid(triangle_t triangle)
{
    return (triangle.a + triangle.b > triangle.c) &&
        (triangle.a + triangle.c > triangle.b) &&
        (triangle.b + triangle.c > triangle.a);
}
