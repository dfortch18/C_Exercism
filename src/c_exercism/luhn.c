#include "c_exercism/luhn.h"
#include <ctype.h>
#include <string.h>

bool luhn(const char *num)
{
    size_t num_length = strlen(num);
    int sum = 0;
    bool is_second = false;
    int digit_count = 0;

    for (int i = num_length - 1; i >= 0; i--)
    {
        if (isdigit(num[i]))
        {
            int digit = num[i] - '0';
            digit_count++;

            if (is_second)
            {
                digit *= 2;
                if (digit > 9)
                {
                    digit -= 9;
                }
            }

            sum += digit;
            is_second = !is_second;
        }
        else if (num[i] != ' ')
        {
            return false;
        }
    }

    if (digit_count <= 1)
    {
        return false;
    }

    return (sum % 10 == 0);
}
