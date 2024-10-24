#include "c_exercism/phone_number.h"
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char *phone_number_clean(const char *input)
{
    char *result = malloc(11);
    size_t count = 0;

    for (size_t i = 0; input[i] != '\0'; i++)
    {
        if (isdigit(input[i]))
        {
            if (count < 11)
            {
                result[count++] = input[i];
            }
        }
    }
    
    if (count == 11 && result[0] == '1')
    {
        memmove(result, result + 1, 10);
        result[10] = '\0';
        count = 10;
    }

    if (count != 10)
    {
        strcpy(result, "0000000000");
        return result;
    }

    if (result[0] == '0' || result[0] == '1')
    {
        strcpy(result, "0000000000");
        return result;
    }

    if (result[3] == '0' || result[3] == '1')
    {
        strcpy(result, "0000000000");
        return result;
    }

    result[10] = '\0';
    return result;
}
