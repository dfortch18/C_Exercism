#include <stdio.h>
#include "c_exercism.h"

#define ARRAY_LENGTH(arr) sizeof(arr) / sizeof(arr[0])

void print_separator();

int main()
{
    // Print hello world
    print_hello_world();

    print_separator();

    // Leap year
    int years[] = {2000, 160, 1900, 30, 4000, 1200};

    for (size_t i = 0; i < ARRAY_LENGTH(years); i++)
    {
        printf("Is leap year %d?: %d\n", years[i], is_leap_year(years[i]));
    }

    print_separator();

    // Difference of squares
    size_t numbers[] = {15, 2, 4, 6, 10, 9, 8, 3};

    for (size_t i = 0; i < ARRAY_LENGTH(numbers); i++)
    {
        printf("Sum of squares (%d): %d\n", numbers[i], sum_of_squares(numbers[i]));
        printf("Square of sum (%d): %d\n", numbers[i], square_of_sum(numbers[i]));
        printf("Difference of squares (%d): %d\n", numbers[i], difference_of_squares(numbers[i]));
    }

    print_separator();

    // Chess squares
    uint64_t chess_squares[] = {34, 2, 4, 1, 6, 11, 22};

    for (size_t i = 0; i < ARRAY_LENGTH(chess_squares); i++)
    {
        printf("Grains of square (%I64u): %I64u\n", chess_squares[i], grains_of_square(chess_squares[i]));
    }

    print_separator();

    // Resistor Color
    const resistor_band_t *all_colors = resistor_band_all_colors();

    for (size_t i = 0; i < resistor_band_num_colors(); i++)
    {
        printf("Resistor band color (%s): %d\n", resistor_band_name(all_colors[i]), resistor_band_color_code(all_colors[i]));
    }

    resistor_band_t resistor_bands[] = {BLACK, BLUE, BROWN, ORANGE, 56};

    for (size_t i = 0; i < ARRAY_LENGTH(resistor_bands); i++)
    {
        printf("Selected resistor band color (%s): %d\n", resistor_band_name(resistor_bands[i]), resistor_band_color_code(resistor_bands[i]));
    }

    print_separator();

    // Collatz Conjecture
    size_t collatz_conjecture_values[] = {1, 16, 12, 1000000, -12, -100, 0};

    for (size_t i = 0; i < ARRAY_LENGTH(collatz_conjecture_values); i++)
    {
        printf("Collatz conjecture steps for (%d): %d\n", collatz_conjecture_values[i], collatz_conjecture_steps(collatz_conjecture_values[i]));
    }
}

void print_separator()
{
    puts("-------------------------------------------------------");
}