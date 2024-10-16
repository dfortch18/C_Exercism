#ifndef C_EXERCISM_RESISTOR_COLOR_H
#define C_EXERCISM_RESISTOR_COLOR_H

#include <stddef.h>

typedef enum resistor_band
{
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE
} resistor_band_t;

const char *resistor_band_name(resistor_band_t);

int resistor_band_color_code(resistor_band_t);

const resistor_band_t *resistor_band_all_colors();

size_t resistor_band_num_colors();

#endif