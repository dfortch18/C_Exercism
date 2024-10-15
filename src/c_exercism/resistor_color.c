#include "c_exercism/resistor_color.h"

static const resistor_band_t ALL_COLORS[] = {
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
};

const char *resistor_band_name(resistor_band_t resistor_band) {
    switch (resistor_band) {
        case BLACK: return "BLACK";
        case BROWN: return "BROWN";
        case RED: return "RED";
        case ORANGE: return "ORANGE";
        case YELLOW: return "YELLOW";
        case GREEN: return "GREEN";
        case BLUE: return "BLUE";
        case VIOLET: return "VIOLET";
        case GREY: return "GREY";
        case WHITE: return "WHITE";
        default: return "UNKNOWN";
    }
}

int resistor_band_color_code(resistor_band_t resistor_band) {
    if (resistor_band < BLACK || resistor_band > WHITE) {
        return -1;
    }
    return (int) resistor_band;
}

const resistor_band_t *resistor_band_all_colors() {
    return ALL_COLORS;
}

size_t resistor_band_num_colors() {
    return sizeof(ALL_COLORS) / sizeof(ALL_COLORS[0]);
}
