#include "c_exercism/raindrops.h"
#include <stdio.h>
#include <string.h>

void raindrops_convert(char *result, int drops)
{
    if (drops % 3 == 0 || drops % 5 == 0 || drops % 7 == 0)
    {
        if (drops % 3 == 0)
        {
            strcat(result, "Pling");
        }
        if (drops % 5 == 0)
        {
            strcat(result, "Plang");
        }
        if (drops % 7 == 0)
        {
            strcat(result, "Plong");
        }
    }
    else
    {
        sprintf(result, "%d", drops);
    }
}
