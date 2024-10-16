#include "c_exercism/space_age.h"

static const float MERCURY_ORBIT_IN_EARTH_YEARS = 0.2408467F;
static const float VENUS_ORBIT_IN_EARTH_YEARS = 0.61519726F;
static const float EARTH_ORBIT_IN_EARTH_YEARS = 1.0F;
static const float MARS_ORBIT_IN_EARTH_YEARS = 1.8808158F;
static const float JUPITER_ORBIT_IN_EARTH_YEARS = 11.862615F;
static const float SATURN_ORBIT_IN_EARTH_YEARS = 29.447498F;
static const float URANUS_ORBIT_IN_EARTH_YEARS = 84.016846F;
static const float NEPTUNE_ORBIT_IN_EARTH_YEARS = 164.79132F;

static const int EARTH_SECONDS_IN_A_YEAR = 31557600;

float space_age(space_age_planet_t planet, int64_t seconds)
{
    float earth_years = (float)seconds / EARTH_SECONDS_IN_A_YEAR;

    float planet_orbit_in_earth_years;
    switch (planet)
    {
    case SPACE_AGE_PLANET_MERCURY:
        planet_orbit_in_earth_years = MERCURY_ORBIT_IN_EARTH_YEARS;
        break;
    case SPACE_AGE_PLANET_VENUS:
        planet_orbit_in_earth_years = VENUS_ORBIT_IN_EARTH_YEARS;
        break;
    case SPACE_AGE_PLANET_EARTH:
        planet_orbit_in_earth_years = EARTH_ORBIT_IN_EARTH_YEARS;
        break;
    case SPACE_AGE_PLANET_MARS:
        planet_orbit_in_earth_years = MARS_ORBIT_IN_EARTH_YEARS;
        break;
    case SPACE_AGE_PLANET_JUPITER:
        planet_orbit_in_earth_years = JUPITER_ORBIT_IN_EARTH_YEARS;
        break;
    case SPACE_AGE_PLANET_SATURN:
        planet_orbit_in_earth_years = SATURN_ORBIT_IN_EARTH_YEARS;
        break;
    case SPACE_AGE_PLANET_URANUS:
        planet_orbit_in_earth_years = URANUS_ORBIT_IN_EARTH_YEARS;
        break;
    case SPACE_AGE_PLANET_NEPTUNE:
        planet_orbit_in_earth_years = NEPTUNE_ORBIT_IN_EARTH_YEARS;
        break;
    default:
        return -1.0F;
    }

    float age_in_planet_years = earth_years / planet_orbit_in_earth_years;

    return age_in_planet_years;
}

const char *space_age_planet_name(space_age_planet_t planet)
{
    switch (planet)
    {
    case SPACE_AGE_PLANET_MERCURY:
        return "MERCURY";
    case SPACE_AGE_PLANET_VENUS:
        return "VENUS";
    case SPACE_AGE_PLANET_EARTH:
        return "EARTH";
    case SPACE_AGE_PLANET_MARS:
        return "MARS";
    case SPACE_AGE_PLANET_JUPITER:
        return "JUPITER";
    case SPACE_AGE_PLANET_SATURN:
        return "SATURN";
    case SPACE_AGE_PLANET_URANUS:
        return "URANUS";
    case SPACE_AGE_PLANET_NEPTUNE:
        return "NEPTUNE";
    default:
        return "UNKNOWN";
    }
}
