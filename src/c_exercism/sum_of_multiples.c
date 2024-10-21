#include "c_exercism/sum_of_multiples.h"
#include <stdlib.h>
#include <stdbool.h>

static int is_present(unsigned int *array, size_t size, unsigned int value)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            return true;
        }
    }
    return false;
}

unsigned int sum_of_multiples(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit)
{
    size_t final_size = 0;
    size_t max_size = 0;

    for (size_t i = 0; i < number_of_factors; i++)
    {
        if (factors[i] == 0) continue;
        max_size += (limit - 1) / factors[i];
    }
    
    unsigned int *all_multiples = (unsigned int*)malloc(max_size * sizeof(unsigned int));

    for (size_t i = 0; i < number_of_factors; i++)
    {
        if (factors[i] == 0) continue;
        for (size_t j = factors[i]; j < limit; j+=factors[i])
        {
            if (!is_present(all_multiples, final_size, j))
            {
                all_multiples[final_size++] = j;
            }
        }
    }
    
    all_multiples = (unsigned int*)realloc(all_multiples, final_size * sizeof(unsigned int));

    unsigned int sum = 0;
    for (size_t i = 0; i < final_size; i++)
    {
        sum += all_multiples[i];
    }
    
    free(all_multiples);

    return sum;
}