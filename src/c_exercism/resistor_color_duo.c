#include "c_exercism/resistor_color_duo.h"

uint16_t resistor_duo_band_color_code(resistor_duo_band_t *arr)
{
    return (arr[0] * 10) + arr[1];
}

const char *resistor_duo_band_name(resistor_duo_band_t band)
{
    switch (band)
    {
    case DUO_BLACK:
        return "DUO_BLACK";
    case DUO_BROWN:
        return "DUO_BROWN";
    case DUO_RED:
        return "DUO_RED";
    case DUO_ORANGE:
        return "DUO_ORANGE";
    case DUO_YELLOW:
        return "DUO_YELLOW";
    case DUO_GREEN:
        return "DUO_GREEN";
    case DUO_BLUE:
        return "DUO_BLUE";
    case DUO_VIOLET:
        return "DUO_VIOLET";
    case DUO_GREY:
        return "DUO_GREY";
    case DUO_WHITE:
        return "DUO_WHITE";
    default:
        return "UNKNOWN";
    }
}