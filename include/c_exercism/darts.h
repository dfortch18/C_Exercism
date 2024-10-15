#ifndef C_EXERCISM_DARTS_H
#define C_EXERCISM_DARTS_H

#include <stdint.h>

typedef struct
{
    float x;
    float y;
} darts_target_coordinates_t;

uint8_t darts_score(darts_target_coordinates_t);

#endif