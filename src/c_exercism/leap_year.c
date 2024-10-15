#include "c_exercism/leap_year.h"

bool is_leap_year(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            return year % 400 == 0;
        }
        else
        {
            return true;
        }
    }
    return false;
}
