#include "c_exercism/rna_transcription.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

static char rna_nucleoid_equivalent(char);

char *rna_transcription_to_rna(const char *adn)
{
    size_t len = strlen(adn);

    char *buffer = malloc(len + 1);

    if (buffer == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < len; i++)
    {
        buffer[i] = rna_nucleoid_equivalent(adn[i]);
    }
    
    buffer[len] = '\0';

    return buffer;
}

static char rna_nucleoid_equivalent(char adn_nucleoid)
{
    char adn_n_upper = (char) toupper(adn_nucleoid);

    switch (adn_n_upper)
    {
    case 'G':
        return 'C';
    case 'C':
        return 'G';
    case 'T':
        return 'A';
    case 'A':
        return 'U';
    default:
        return '\0';
    }
}
