#include "c_exercism/grains.h"
#include <math.h>

static const uint64_t squares_of_chessboard = 64;

uint64_t grains_of_square(uint8_t index) {
    if (index < 1 || index > squares_of_chessboard) {
        return 0;
    }
    return (uint64_t) pow(2, index - 1);
}

uint64_t total_grains() {
    uint64_t total_grains = 0;
    for (uint64_t x = 1; x <= squares_of_chessboard; x++) {
        total_grains += grains_of_square(x);
    }
    return total_grains;
}