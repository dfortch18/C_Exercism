#include "c_exercism/armstrong_numbers.h"
#include <stddef.h>
#include <math.h>

bool is_armstrong_number(int candidate)
{
    int digits[10];
    int digit_count = 0;
    int original_candidate = candidate;

    while (candidate > 0)
    {
        digits[digit_count] = candidate % 10;
        candidate /= 10;
        digit_count++;
    }

    int sum = 0;

    for (size_t i = digit_count; i-- > 0;)
    {
        sum += pow(digits[i], digit_count);
    }

    return sum == original_candidate;
}
