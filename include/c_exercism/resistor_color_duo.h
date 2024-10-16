#ifndef C_EXERCISM_RESISTOR_COLOR_DUO_H
#define C_EXERCISM_RESISTOR_COLOR_DUO_H

#include <stdint.h>

typedef enum resistor_duo_band
{
    DUO_BLACK,
    DUO_BROWN,
    DUO_RED,
    DUO_ORANGE,
    DUO_YELLOW,
    DUO_GREEN,
    DUO_BLUE,
    DUO_VIOLET,
    DUO_GREY,
    DUO_WHITE
} resistor_duo_band_t;

uint16_t resistor_duo_band_color_code(resistor_duo_band_t *);

const char *resistor_duo_band_name(resistor_duo_band_t);

#endif
