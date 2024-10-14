#include <stdio.h>
#include "c_exercism.h"

void print_separator();

int main() {
    // Print hello world
    print_hello_world();

    print_separator();

    // Leap year
    int years[] = {2000, 160, 1900, 30, 4000, 1200};

    for (size_t i = 0; i < (sizeof(years) / sizeof(years[0])); i++) {
        printf("Is leap year %d?: %d\n", years[i], is_leap_year(years[i]));
    }

    print_separator();

    // Difference of squares
    size_t numbers[] = {15, 2, 4, 6, 10, 9, 8, 3};

    for (size_t i = 0; i < (sizeof(numbers) / sizeof(numbers[0])); i++) {
        printf("Sum of squares (%d): %d\n", numbers[i], sum_of_squares(numbers[i]));
        printf("Square of sum (%d): %d\n", numbers[i], square_of_sum(numbers[i]));
        printf("Difference of squares (%d): %d\n", numbers[i], difference_of_squares(numbers[i]));
    }

    print_separator();

    // Chess squares
    uint64_t chess_squares[] = {34, 2, 4, 1, 6, 11, 22};

    for (size_t i = 0; i < (sizeof(chess_squares) / sizeof(chess_squares[0])); i++) {
        printf("Grains of square (%I64u): %I64u\n", chess_squares[i], grains_of_square(chess_squares[i]));
    }
}

void print_separator() {
    puts("-------------------------------------------------------");
}