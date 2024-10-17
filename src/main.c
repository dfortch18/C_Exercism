#include <stdio.h>
#include <stdlib.h>
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

    print_separator();

    // Queen Attack
    queen_position_t queen_positions[][2] = {
        {{0, 0}, {0, 3}},
        {{3, 6}, {4, 6}},
        {{2, 4}, {4, 6}},
        {{3, 2}, {7, 0}},
        {{2, 5}, {5, 3}},
        {{9, 2}, {5, 4}}};

    for (size_t i = 0; i < ARRAY_LENGTH(queen_positions); i++)
    {
        queen_position_t queen_1 = queen_positions[i][0];
        queen_position_t queen_2 = queen_positions[i][1];
        queen_attack_status_t attack_status = queen_can_attack(queen_1, queen_2);
        const char *attack_status_name = queen_attack_status_name(attack_status);

        printf("Attack status of queen_1(%d,%d) queen_2(%d,%d): %s \n", queen_1.row, queen_1.column, queen_2.row, queen_2.column, attack_status_name);
    }

    print_separator();

    darts_target_coordinates_t dart_coordiantes[] = {
        {0.0F, 0.0F},
        {1.0F, 1.0F},
        {3.5F, -2.5F},
        {10.0F, 5.0F},
        {6.0F, 8.0F},
        {-7.0F, -7.0F},
        {9.5F, -9.5F},
        {0.5F, 0.5F},
        {2.0F, -3.0F},
        {-9.0F, 9.0F}};

    for (size_t i = 0; i < ARRAY_LENGTH(dart_coordiantes); i++)
    {
        darts_target_coordinates_t coordinates = dart_coordiantes[i];
        printf("Coordiantes score for (%f,%f): %d\n", coordinates.x, coordinates.y, darts_score(coordinates));
    }

    print_separator();

    // Resistor Color Duo
    resistor_duo_band_t resistor_duo_arr[][2] = {
        {DUO_BLACK, DUO_GREEN},
        {DUO_BROWN, DUO_BLACK},
        {DUO_BLACK, DUO_WHITE},
        {DUO_ORANGE, DUO_BLUE}};

    for (size_t i = 0; i < ARRAY_LENGTH(resistor_duo_arr); i++)
    {
        const char *band_name_1 = resistor_duo_band_name(resistor_duo_arr[i][0]);
        const char *band_name_2 = resistor_duo_band_name(resistor_duo_arr[i][1]);
        uint16_t color_code = resistor_duo_band_color_code(resistor_duo_arr[i]);
        printf("Resistor color duo (%s,%s): %d\n", band_name_1, band_name_2, color_code);
    }

    print_separator();

    // Hamming
    const char *hamming_input_arr[][2] = {
        {"GAGCCTACTAACGGGAT", "CATCGTAATGACGGCCT"},
        {"GGACTGAAATCTG", "GGACTGAAATCTG"},
        {"GGACGGATTCTG", "AGGACGGATTCT"},
        {"AATG", "AAA"},
        {"ATA", "AGTG"},
        {"G", ""}};

    for (size_t i = 0; i < ARRAY_LENGTH(hamming_input_arr); i++)
    {
        const char *lhs = hamming_input_arr[i][0];
        const char *rhs = hamming_input_arr[i][1];
        printf("Hamming Distance (%s, %s): %d\n", lhs, rhs, hamming_compute(lhs, rhs));
    }

    print_separator();

    // Space Age
    space_age_planet_t space_age__planets[9] = {
        SPACE_AGE_PLANET_EARTH,
        SPACE_AGE_PLANET_MERCURY,
        SPACE_AGE_PLANET_VENUS,
        SPACE_AGE_PLANET_MARS,
        SPACE_AGE_PLANET_JUPITER,
        SPACE_AGE_PLANET_SATURN,
        SPACE_AGE_PLANET_URANUS,
        SPACE_AGE_PLANET_NEPTUNE,
        (space_age_planet_t)-1};

    int64_t space_age__seconds[9] = {
        1000000000,
        2134835688,
        189839836,
        2129871239,
        901876382,
        2000000000,
        1210123456,
        1821023456,
        680804807};

    for (size_t i = 0; i < 9; i++)
    {
        space_age_planet_t planet = space_age__planets[i];
        int64_t seconds = space_age__seconds[i];
        printf("Space Age (%s,%I64u): %f\n", space_age_planet_name(planet), seconds, space_age(planet, seconds));
    }

    print_separator();

    const char *rna_transcription_inputs[] = {"", "C", "G", "T", "A", "ACGTGGTCTTAA"};

    for (size_t i = 0; i < ARRAY_LENGTH(rna_transcription_inputs); i++)
    {
        const char *adn = rna_transcription_inputs[i];
        char *rna = rna_transcription_to_rna(adn);
        printf("Rna transcription of (%s): %s\n", adn, rna);
        free(rna);
    }

    print_separator();

    // Binary convert
    const char *binaries[] = {
        "0",
        "1",
        "10",
        "11",
        "100",
        "1001",
        "11010",
        "10001101000",
        "000011111",
        "2",
        "01201",
        "10nope",
        "nope10",
        "10nope10",
        "001 nope"};

    for (size_t i = 0; i < ARRAY_LENGTH(binaries); i++)
    {
        printf("Decimal equivalent of binary (%s): %d\n", binaries[i], binary_convert(binaries[i]));
    }
    
}

void print_separator()
{
    puts("-------------------------------------------------------");
}