#include "c_exercism/pangram.h"
#include <stddef.h>
#include <ctype.h>
#include <string.h>

#define ENGLISH_ALPHABET_LENGTH 26

bool is_pangram(const char *sentence)
{
    if (sentence == NULL)
    {
        return false;
    }

    bool letters[ENGLISH_ALPHABET_LENGTH] = {false};

    for (size_t i = 0; sentence[i] != '\0'; i++)
    {
        if (isalpha(sentence[i]))
        {
            char lower = tolower(sentence[i]);
            if (lower >= 'a' && lower <= 'z')
            {
                letters[lower - 'a'] = true;
            }
        }
    }

    for (size_t i = 0; i < ENGLISH_ALPHABET_LENGTH; i++)
    {
        if (!letters[i])
        {
            return false;
        }
    }
    return true;
}
