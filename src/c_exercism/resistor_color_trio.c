#include "c_exercism/resistor_color_trio.h"
#include <math.h>

resistor_trio_value_t resistor_trio_band_color_code(resistor_trio_band_t *bands, size_t bands_len)
{
    resistor_trio_value_t invalid_value = {.value = 0xFFFF, .unit = TRIO_INVALID_UNIT};

    if (bands_len < 3) {
        return invalid_value;
    }

    for (size_t i = 0; i < bands_len; i++) {
        if (bands[i] < TRIO_BLACK || bands[i] > TRIO_WHITE) {
            return invalid_value;
        }
    }

    uint64_t value = (bands[0] * 10) + bands[1];
    value *= (uint64_t) pow(10, bands[2]);
    resistor_trio_ohms_unit_t unit = TRIO_OHMS;

    if (value >= 1000000000)
    {
        value /= 1000000000;
        unit = TRIO_GIGAOHMS;
    }
    else if (value >= 1000000)
    {
        value /= 1000000;
        unit = TRIO_MEGAOHMS;
    }
    else if (value >= 1000)
    {
        value /= 1000;
        unit = TRIO_KILOOHMS;
    }

    return (resistor_trio_value_t){(uint16_t)value, unit};
}

const char *resistor_trio_band_name(resistor_trio_band_t band)
{
    switch (band)
    {
    case TRIO_BLACK:
        return "BLACK";
    case TRIO_BROWN:
        return "BROWN";
    case TRIO_RED:
        return "RED";
    case TRIO_ORANGE:
        return "ORANGE";
    case TRIO_YELLOW:
        return "YELLOW";
    case TRIO_GREEN:
        return "GREEN";
    case TRIO_BLUE:
        return "BLUE";
    case TRIO_VIOLET:
        return "VIOLET";
    case TRIO_GREY:
        return "GREY";
    case TRIO_WHITE:
        return "WHITE";
    default:
        return "UNKNOWN";
    }
}

const char *resistor_trio_ohms_unit_name(resistor_trio_ohms_unit_t unit)
{
    switch (unit)
    {
    case TRIO_OHMS:
        return "OHMS";
        break;
    case TRIO_KILOOHMS:
        return "KILOOHMS";
    case TRIO_MEGAOHMS:
        return "MEGAOHMS";
    case TRIO_GIGAOHMS:
        return "GIGAOHMS";
    case TRIO_INVALID_UNIT:
        return "INVALID_UNIT";
    default:
        return "UNKNOWN";
    }
}
