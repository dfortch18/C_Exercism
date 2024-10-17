#include "c_exercism/binary.h"
#include <string.h>
#include <math.h>

int binary_convert(const char *binary_str)
{
    int decimal_value = 0;
    size_t length = strlen(binary_str);

    for (size_t i = 0; i < length; i++)
    {
        if (binary_str[i] != '1' && binary_str[i] != '0')
        {
            return -1;
        }

        if (binary_str[i] == '1')
        {
            decimal_value += pow(2, length - 1 - i);
        }
    }

    return decimal_value;
}