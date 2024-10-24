#include "c_exercism/pythagorean_triplet.h"
#include <stdlib.h>

triplets_t *triplets_with_sum(int sum)
{
    triplets_t *result = (triplets_t *)malloc(sizeof(triplets_t));

    if (result == NULL)
    {
        return NULL;
    }

    result->count = 0;
    result->triplets = NULL;

    for (int a = 1; a < sum / 3; a++)
    {
        for (int b = a + 1; b < sum / 2; b++)
        {
            int c = sum - a - b;

            if (a * a + b * b == c * c)
            {
                result->count++;

                result->triplets = realloc(result->triplets, result->count * sizeof(triplet_t));

                if (result->triplets == NULL)
                {
                    free(result);
                    return NULL;
                }

                result->triplets[result->count - 1].a = a;
                result->triplets[result->count - 1].b = b;
                result->triplets[result->count - 1].c = c;
            }
        }
        
    }
    
    return result;
}

void free_triplets(triplets_t *triplets)
{
    if (triplets != NULL)
    {
        free(triplets->triplets);
        free(triplets);
    }
}
