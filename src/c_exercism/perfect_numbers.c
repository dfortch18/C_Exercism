#include <c_exercism/perfect_numbers.h>

perfect_numbers_kind_t perfect_numbers_classify_number(size_t number)
{
    if (number <= 0)
    {
        return PN_ERROR;
    }

    size_t sum = 0;

    for (size_t x = 1; x < number; x++)
    {
        if (number % x == 0)
        {
            sum += x;
        }
    }

    if (sum == number)
    {
        return PN_PERFECT_NUMBER;
    }
    else if (sum > number)
    {
        return PN_ABUNDANT_NUMBER;
    }
    else
    {
        return PN_DEFICIENT_NUMBER;
    }
}

const char *perfect_numbers_kind_name(perfect_numbers_kind_t kind)
{
    switch (kind)
    {
    case PN_PERFECT_NUMBER:
        return "PERFECT_NUMBER";
    case PN_ABUNDANT_NUMBER:
        return "ABUNDANT_NUMBER";
    case PN_DEFICIENT_NUMBER:
        return "DEFICIENT_NUMBER";
    case PN_ERROR:
        return "ERROR";
    default:
        return "UNKNOWN";
    }
}
