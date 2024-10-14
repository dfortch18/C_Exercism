#include "c_exercism/difference_of_squares.h"
#include <math.h>

unsigned int sum_of_squares(unsigned int number) {
    int total = 0;

    for (unsigned int x = 1; x <= number; x++) {
        total += pow(x, 2);
    }
    return total;
}

unsigned int square_of_sum(unsigned int number) {
    int total = 0;

    for (unsigned int x = 1; x <= number; x++) {
        total += x;
    }
    total = pow(total, 2);
    return total;
}

unsigned int difference_of_squares(unsigned int number) {
    return square_of_sum(number) - sum_of_squares(number);
}
