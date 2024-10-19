#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

#include <stddef.h>
#include <stdint.h>

typedef enum resistor_trio_band
{
    TRIO_BLACK,
    TRIO_BROWN,
    TRIO_RED,
    TRIO_ORANGE,
    TRIO_YELLOW,
    TRIO_GREEN,
    TRIO_BLUE,
    TRIO_VIOLET,
    TRIO_GREY,
    TRIO_WHITE
} resistor_trio_band_t;

typedef enum resistor_trio_ohms_unit
{
    TRIO_OHMS,
    TRIO_KILOOHMS,
    TRIO_MEGAOHMS,
    TRIO_GIGAOHMS,
    TRIO_INVALID_UNIT
} resistor_trio_ohms_unit_t;

typedef struct resistor_trio_value
{
    uint16_t value;
    resistor_trio_ohms_unit_t unit;
} resistor_trio_value_t;

resistor_trio_value_t resistor_trio_band_color_code(resistor_trio_band_t *, size_t);

const char *resistor_trio_band_name(resistor_trio_band_t);

const char *resistor_trio_ohms_unit_name(resistor_trio_ohms_unit_t);

#endif