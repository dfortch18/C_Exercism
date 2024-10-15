#include "c_exercism/collatz_conjecture.h"

int collatz_conjecture_steps(int start)
{
    if (start <= 0)
    {
        return -1;
    }

    int stepts = 0;

    while (start != 1)
    {
        if (start % 2 == 0)
        {
            start /= 2;
        }
        else
        {
            start = 3 * start + 1;
        }
        stepts++;
    }

    return stepts;
}