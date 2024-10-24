#ifndef C_EXERCISM_PYTHAGOREAN_TRIPLET_H
#define C_EXERCISM_PYTHAGOREAN_TRIPLET_H

#include <stddef.h>

typedef struct _triplet
{
    int a;
    int b;
    int c;
} triplet_t;

typedef struct _triplets
{
    triplet_t *triplets;
    size_t count;
} triplets_t;

triplets_t *triplets_with_sum(int);

void free_triplets(triplets_t *);

#endif