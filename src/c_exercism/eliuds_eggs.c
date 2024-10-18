#include "c_exercism/eliuds_eggs.h"

size_t eliuds_eggs_egg_count(size_t decimal)
{
    size_t count = 0;

    while (decimal != 0)
    {
        if (decimal & 1)
        {
            count++;
        }

        decimal >>= 1;
    }

    return count;
}
