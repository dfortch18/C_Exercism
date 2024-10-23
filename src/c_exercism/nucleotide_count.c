#include "c_exercism/nucleotide_count.h"
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *nucleotide_count(const char *dna_strand)
{
    unsigned int nucleotides_count[4] = {0};

    size_t length = strlen(dna_strand);

    for (size_t i = 0; i < length; i++)
    {
        char nucleotide = toupper(dna_strand[i]);
        switch (nucleotide)
        {
        case 'A':
            nucleotides_count[0]++;
            break;
        case 'C':
            nucleotides_count[1]++;
            break;
        case 'G':
            nucleotides_count[2]++;
            break;
        case 'T':
            nucleotides_count[3]++;
            break;
        default:
        {
            char *error_result = (char *)malloc(1);
            if (error_result != NULL)
            {
                error_result[0] = '\0';
            }
            return error_result;
        }
        }
    }

    char *result = (char *)malloc(20 * sizeof(char));

    if (result == NULL)
    {
        return result;
    }

    sprintf(result, "A:%u C:%u G:%u T:%u", nucleotides_count[0], nucleotides_count[1], nucleotides_count[2], nucleotides_count[3]);

    return result;
}
