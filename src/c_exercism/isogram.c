#include "c_exercism/isogram.h"
#include <stddef.h>
#include <string.h>
#include <ctype.h>

#define ENGLISH_ALPHABET_LENGTH 26

bool is_isogram(const char *phrase)
{
    if (phrase == NULL)
    {
        return false;
    }

    char letters[ENGLISH_ALPHABET_LENGTH];
    size_t times[ENGLISH_ALPHABET_LENGTH];
    size_t phrase_length = strlen(phrase);

    int letters_temp_i = 0;
    for (char letter = 'a'; letter <= 'z'; letter++)
    {
        letters[letters_temp_i] = letter;
        letters_temp_i++;
    }
    
    for (size_t i = 0; i < ENGLISH_ALPHABET_LENGTH; i++)
    {
        char letter = letters[i];

        size_t count = 0;
        for (size_t j = 0; j < phrase_length; j++)
        {
            if (isalpha(phrase[j]))
            {
                char lower = tolower(phrase[j]);
                if (letter == lower)
                {
                    count++;
                }
                
            }
        }
        times[i] = count;
    }

    for (size_t i = 0; i < ENGLISH_ALPHABET_LENGTH; i++)
    {
        if (times[i] > 1)
        {
            return false;
        }
    }
    return true;
}
