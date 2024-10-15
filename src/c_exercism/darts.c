#include "c_exercism/darts.h"
#include <math.h>

static const float INNER_RADIUS = 1.0F;

static const float MIDDLE_RADIUS = 5.0F;

static const float OUTER_RADIUS = 10.0F;

uint8_t darts_score(darts_target_coordinates_t coordinates)
{
    float distance = sqrt(coordinates.x * coordinates.x + coordinates.y * coordinates.y);

    if (distance > OUTER_RADIUS)
    {
        return 0;
    }
    else if (distance > MIDDLE_RADIUS)
    {
        return 1;
    }
    else if (distance > INNER_RADIUS)
    {
        return 5;
    }
    else
    {
        return 10;
    }
}
