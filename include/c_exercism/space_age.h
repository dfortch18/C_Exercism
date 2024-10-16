#ifndef C_EXERCISM_SPACE_AGE
#define C_EXERCISM_SPACE_AGE

#include <stdint.h>

typedef enum space_age_planet
{
    SPACE_AGE_PLANET_MERCURY,
    SPACE_AGE_PLANET_VENUS,
    SPACE_AGE_PLANET_EARTH,
    SPACE_AGE_PLANET_MARS,
    SPACE_AGE_PLANET_JUPITER,
    SPACE_AGE_PLANET_SATURN,
    SPACE_AGE_PLANET_URANUS,
    SPACE_AGE_PLANET_NEPTUNE,
} space_age_planet_t;

float space_age(space_age_planet_t planet, int64_t seconds);

const char *space_age_planet_name(space_age_planet_t);

#endif