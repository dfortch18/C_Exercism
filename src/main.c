#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "c_exercism.h"

#define ARRAY_LENGTH(arr) sizeof(arr) / sizeof((arr)[0])

void print_separator();

static inline time_t days_from_1ad(int);

static time_t construct_date(int, int, int, int, int, int);

static void print_triplets(const triplets_t *, bool);

static void print_proteins(const proteins_t, bool);

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

    print_separator();

    // Eliuds Eggs
    size_t eliuds_eggs_decimals[] = {0, 16, 89, 2000000000};

    for (size_t i = 0; i < ARRAY_LENGTH(eliuds_eggs_decimals); i++)
    {
        size_t decimal = eliuds_eggs_decimals[i];
        printf("Eliuds Eggs (%d): %d\n", decimal, eliuds_eggs_egg_count(decimal));
    }

    print_separator();

    // Two Fer
    const char *two_fer_names[] = {"Alice", "Bob", NULL};

    for (size_t i = 0; i < ARRAY_LENGTH(two_fer_names); i++)
    {
        char buffer[100];
        two_fer(buffer, two_fer_names[i]);
        printf("Two fer for (%s): %s\n", two_fer_names[i], buffer);
    }

    print_separator();

    // Raindrops
    int raindrops_drops[] = {1, 3, 5, 7, 6, 8, 9, 10, 15, 21, 25, 35, 39};

    for (size_t i = 0; i < ARRAY_LENGTH(raindrops_drops); i++)
    {
        char result[16] = {0};
        raindrops_convert(result, raindrops_drops[i]);
        printf("Raindrops (%d): %s\n", raindrops_drops[i], result);
    }

    print_separator();

    // D&D Character
    int dnd_character_modifiers[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    dnd_character_t character = make_dnd_character();

    for (size_t i = 0; i < ARRAY_LENGTH(dnd_character_modifiers); i++)
    {
        printf("Dnd character score (%d): %d\n", dnd_character_modifiers[i], dnd_character_modifier(dnd_character_modifiers[i]));
    }

    printf("Dnd character random ability: %d\n", dnd_character_ability());

    print_dnd_character(&character);

    print_separator();

    // Perfect Numbers
    size_t perfect_numbers_inputs[] = {6, 28, 33550336, 12, 30, 33550335, 2, 4, 32, 33550337, 1};

    for (size_t i = 0; i < ARRAY_LENGTH(perfect_numbers_inputs); i++)
    {
        size_t number = perfect_numbers_inputs[i];
        perfect_numbers_kind_t kind = perfect_numbers_classify_number(number);
        printf("Perfect number classification for (%d): %s\n", number, perfect_numbers_kind_name(kind));
    }

    print_separator();

    // High Scores
    int32_t high_scores_list[] = {10, 30, 90, 30, 100, 20, 10, 0, 30, 40, 40, 70};
    size_t high_score_len = ARRAY_LENGTH(high_scores_list);
    int32_t top[3] = {0, 0, 0};
    size_t top_n = high_scores_personal_top_three(high_scores_list, high_score_len, top);
    printf("Top 3: 1. %d; 2. %d; 3. %d\n", top[0], top[1], top[2]);
    printf("Personal best: %d\n", high_scores_personal_best(high_scores_list, high_score_len));
    printf("Latest score: %d\n", high_scores_latest(high_scores_list, high_score_len));
    printf("Top n: %d\n", top_n);

    print_separator();

    // Pangram
    const char *pangram_sentences[] = {
        "abcdefghijklmnopqrstuvwxyz",
        "the quick brown fox jumps over the lazy dog",
        "a quick movement of the enemy will jeopardize five gunboats",
        "five boxing wizards jump quickly at it",
        "the_quick_brown_fox_jumps_over_the_lazy_dog",
        "the 1 quick brown fox jumps over the 2 lazy dogs",
        "7h3 qu1ck brown fox jumps ov3r 7h3 lazy dog",
        "\"Five quacking Zephyrs jolt my wax bed.\"",
        "abcdefghijklm ABCDEFGHIJKLM"};

    for (size_t i = 0; i < ARRAY_LENGTH(pangram_sentences); i++)
    {
        printf("Sentence ('%s') is pangram: %s\n", pangram_sentences[i], is_pangram(pangram_sentences[i]) ? "true" : "false");
    }

    print_separator();

    // Resistor Color Trio
    resistor_trio_band_t resistor_trio_bands[][3] = {
        {TRIO_ORANGE, TRIO_ORANGE, TRIO_BLACK},
        {TRIO_BLUE, TRIO_GREY, TRIO_BROWN},
        {TRIO_RED, TRIO_BLACK, TRIO_RED},
        {TRIO_GREEN, TRIO_BROWN, TRIO_ORANGE},
        {TRIO_YELLOW, TRIO_VIOLET, TRIO_YELLOW},
        {TRIO_BLUE, TRIO_VIOLET, TRIO_BLUE},
        {TRIO_BLACK, TRIO_BLACK, TRIO_BLACK},
        {TRIO_WHITE, TRIO_WHITE, TRIO_WHITE},
        {TRIO_BLACK, TRIO_GREY, TRIO_BLACK},
        {TRIO_BLUE, TRIO_GREEN, TRIO_YELLOW},
        {TRIO_BLACK, TRIO_BLACK, -1}};

    for (size_t i = 0; i < ARRAY_LENGTH(resistor_trio_bands); i++)
    {
        size_t bands_len = ARRAY_LENGTH(resistor_trio_bands[i]);
        resistor_trio_value_t value = resistor_trio_band_color_code(resistor_trio_bands[i], bands_len);
        char bands[100] = "";

        for (size_t j = 0; j < bands_len; j++)
        {
            strcat(bands, resistor_trio_band_name(resistor_trio_bands[i][j]));
            if (j < bands_len - 1)
            {
                strcat(bands, ",");
            }
        }

        const char *unit_name = resistor_trio_ohms_unit_name(value.unit);

        printf("Resistor trio value for (%s): value = %d, unit = %s\n", bands, value.value, unit_name);
    }

    print_separator();

    // Armstrong numbers
    int armstrong_number_candidates[] = {0, 5, 10, 153, 100, 9474, 9475, 9926315, 9926314};

    for (size_t i = 0; i < ARRAY_LENGTH(armstrong_number_candidates); i++)
    {
        int candidate = armstrong_number_candidates[i];
        printf("Is armstrong number (%d): %s\n", candidate, is_armstrong_number(candidate) ? "true" : "false");
    }

    print_separator();

    // Isogram
    char *isogram_candidates[] = {
        "isogram",
        "eleven",
        "zzyzx",
        "subdermatoglyphic",
        "Alphabet",
        "alphAbet",
        "thumbscrew-japingly",
        "thumbscrew-jappingly",
        "six-year-old",
        "Emily Jung Schwartzkopf",
        "accentor",
        "angola",
        "up-to-date"};

    for (size_t i = 0; i < ARRAY_LENGTH(isogram_candidates); i++)
    {
        char *candidate = isogram_candidates[i];
        printf("Is isogram (%s): %s\n", candidate, is_isogram(candidate) ? "true" : "false");
    }

    print_separator();

    // Robot Simulator
    robot_simulator_direction_t robot_simulator_directions[5] = {
        ROBOT_SIMULATOR_DIRECTION_DEFAULT,
        ROBOT_SIMULATOR_DIRECTION_SOUTH,
        ROBOT_SIMULATOR_DIRECTION_WEST,
        ROBOT_SIMULATOR_DIRECTION_EAST,
        ROBOT_SIMULATOR_DIRECTION_NORTH};
    int robot_simulator_positions[5][2] = {
        {9, 4},
        {-4, 1},
        {-3, -8},
        {11, 5},
        {8, 4}};
    const char *robot_simulator_commands[5] = {
        "R",
        "R",
        "RAALAL",
        "RAALAL",
        "LAAARALA"};

    for (size_t i = 0; i < 5; i++)
    {
        robot_simulator_direction_t direction = robot_simulator_directions[i];
        int *positions = robot_simulator_positions[i];
        const char *commands = robot_simulator_commands[i];

        robot_simulator_status_t robot = robot_simulator_create(direction, positions[0], positions[1]);

        const char *created_direction_name = robot_simulator_direction_name(robot.direction);

        printf("Robot simulator created: direction = %s, position = (%d,%d)\n", created_direction_name, robot.position.x, robot.position.y);

        robot_simulator_move(&robot, commands);

        const char *actual_direction_name = robot_simulator_direction_name(robot.direction);

        printf("Robot simulator moved: direction = %s, position = (%d,%d)\n", actual_direction_name, robot.position.x, robot.position.y);
    }

    print_separator();

    const time_t gigasecond_dates[] = {
        construct_date(2011, 4, 25, 0, 0, 0),
        construct_date(1977, 6, 13, 0, 0, 0),
        construct_date(1959, 7, 19, 0, 0, 0),
        construct_date(2015, 1, 24, 22, 0, 0),
        construct_date(2015, 1, 24, 23, 59, 59)};

    for (size_t i = 0; i < ARRAY_LENGTH(gigasecond_dates); i++)
    {
        char date_formatted[GIGASECOND_DATE_FORMATTED_BUFFER_SIZE] = {0};

        struct tm *initial_time = localtime(&gigasecond_dates[i]);
        if (initial_time != NULL)
        {
            strftime(date_formatted, sizeof(date_formatted), GIGASECOND_DATE_FORMAT, initial_time);
        }
        else
        {
            snprintf(date_formatted, sizeof(date_formatted), "Invalid time");
        }

        char output[GIGASECOND_DATE_FORMATTED_BUFFER_SIZE] = {0};

        gigasecond(gigasecond_dates[i], output, sizeof(output));

        printf("Gigasecond after (%s): %s\n", date_formatted, output);
    }

    print_separator();

    triangle_t triangles[21] = {
        {2, 2, 2},
        {2, 3, 2},
        {5, 4, 6},
        {0, 0, 0},
        {0.5, 0.5, 0.5},
        {3, 4, 4},
        {4, 4, 3},
        {4, 3, 4},
        {4, 4, 4},
        {2, 3, 4},
        {1, 1, 3},
        {1, 3, 1},
        {3, 1, 1},
        {0.5, 0.4, 0.5},
        {5, 4, 6},
        {4, 4, 4},
        {4, 4, 3},
        {3, 4, 3},
        {4, 3, 3},
        {7, 3, 2},
        {0.5, 0.4, 0.6}};

    uint8_t triangle_checks[21] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2};

    for (size_t i = 0; i < 21; i++)
    {
        triangle_t triangle = triangles[i];
        char *triangle_type;
        triangle_checker_t triangle_checker;
        switch (triangle_checks[i])
        {
        case 0:
            triangle_type = "Equilateral";
            triangle_checker = triangle_is_equilateral;
            break;
        case 1:
            triangle_type = "Isosceles";
            triangle_checker = triangle_is_isosceles;
            break;
        case 2:
            triangle_type = "Scalene";
            triangle_checker = triangle_is_scalene;
            break;
        default:
            printf("Invalid triangle checker");
            exit(1);
        }
        printf("Is triangle %s (%f, %f, %f): %s\n", triangle_type, triangle.a, triangle.b, triangle.c, triangle_checker(triangle) ? "true" : "false");
    }

    print_separator();

    // Luhn
    const char *luhn_candidates[] = {
        "1",
        "0",
        "059",
        "59",
        "055 444 285",
        "055 444 286",
        "8273 1232 7352 0569",
        "1 2345 6789 1234 5678 9012",
        "1 2345 6789 1234 5678 9013",
        "095 245 88",
        "234 567 891 234",
        "059a",
        "055-444-285",
        "055£ 444$ 285",
        " 0",
        "0000 0",
        "091",
        "9999999999 9999999999 9999999999 9999999999",
        "109",
        "055b 444 285",
        ":9",
        "59%59"};

    for (size_t i = 0; i < ARRAY_LENGTH(luhn_candidates); i++)
    {
        printf("Is valid luhn (%s): %s\n", luhn_candidates[i], luhn(luhn_candidates[i]) ? "true" : "false");
    }

    print_separator();

    // Allergies
    size_t allergens_scores[] = {0, 1, 2, 8, 3, 5, 248, 255, 509, 257};
    const allergen_t *all_allergens = get_all_allergens();

    for (size_t i = 0; i < ARRAY_LENGTH(allergens_scores); i++)
    {
        int score = allergens_scores[i];
        allergen_list_t list = get_allergens_for(score);

        for (size_t i = 0; i < ALLERGEN_COUNT; i++)
        {
            allergen_t allergen = all_allergens[i];

            printf("Is allergic for %s (%d): %s\n", get_allergen_name(allergen), score, list.allergens[allergen] ? "true" : "false");
        }
        printf("Total allergens: %d\n", list.count);
    }

    print_separator();

    // Complex numbers
    complex_t complex_real_inputs[] = {{1.0, 0.0}, {0.0, 1.0}, {1.0, 2.0}};
    complex_t complex_imag_inputs[] = {{1.0, 0.0}, {0.0, 1.0}, {1.0, 2.0}};
    complex_t complex_add_inputs[][2] = {
        {{1.0, 0.0}, {2.0, 0.0}},
        {{0.0, 1.0}, {0.0, 2.0}},
        {{1.0, 2.0}, {3.0, 4.0}},
        {{1.0, 2.0}, {5.0, 0.0}},
        {{5.0, 0.0}, {1.0, 2.0}}};
    complex_t complex_sub_inputs[][2] = {
        {{1.0, 0.0}, {2.0, 0.0}},
        {{0.0, 1.0}, {0.0, 2.0}},
        {{1.0, 2.0}, {3.0, 4.0}},
        {{5.0, 7.0}, {4.0, 0.0}},
        {{4.0, 0.0}, {5.0, 7.0}}};
    complex_t complex_mul_inputs[][2] = {
        {{1.0, 2.0}, {1.0, 2.0}},
        {{0.0, 1.0}, {0.0, 1.0}},
        {{0.0, 1.0}, {0.0, 2.0}},
        {{1.0, 2.0}, {3.0, 4.0}},
        {{2.0, 5.0}, {5.0, 0.0}},
        {{5.0, 0.0}, {2.0, 5.0}}};
    complex_t complex_div_inputs[][2] = {
        {{1.0, 0.0}, {2.0, 0.0}},
        {{0.0, 1.0}, {0.0, 2.0}},
        {{1.0, 2.0}, {3.0, 4.0}},
        {{1.0, 100.0}, {10.0, 0.0}},
        {{5.0, 0.0}, {1.0, 1.0}}};
    complex_t complex_abs_inputs[] = {{5.0, 0.0}, {-5.0, 0.0}, {0.0, 5.0}, {0.0, -5.0}, {3.0, 4.0}};
    complex_t complex_conjugate_inputs[] = {{5.0, 0.0}, {0.0, 5.0}, {1.0, 1.0}};
    complex_t complex_exp_inputs[] = {{0.0, 0.0}, {1.0, 0.0}, {log(2.0) / 2.0, acos(-1)}, {log(2.0) / 2.0, acos(-1) / 4.0}};

    for (size_t i = 0; i < ARRAY_LENGTH(complex_real_inputs); i++)
    {
        complex_t complex = complex_real_inputs[i];
        printf("Real part of (%3.2f,%3.2f): %3.2f\n", complex.real, complex.imag, complex_real(complex));
    }

    for (size_t i = 0; i < ARRAY_LENGTH(complex_imag_inputs); i++)
    {
        complex_t complex = complex_imag_inputs[i];
        printf("Imaginary part of (%3.2f,%3.2f): %3.2f\n", complex.real, complex.imag, complex_imag(complex));
    }

    for (size_t i = 0; i < ARRAY_LENGTH(complex_add_inputs); i++)
    {
        complex_t complex1 = complex_add_inputs[i][0];
        complex_t complex2 = complex_add_inputs[i][1];
        complex_t result = complex_add(complex1, complex2);
        printf("Sum of (%3.2f,%3.2f) and (%3.2f,%3.2f): (%3.2f,%3.2f)\n", complex1.real, complex1.imag, complex2.real, complex2.imag, result.real, result.imag);
    }

    for (size_t i = 0; i < ARRAY_LENGTH(complex_sub_inputs); i++)
    {
        complex_t complex1 = complex_sub_inputs[i][0];
        complex_t complex2 = complex_sub_inputs[i][1];
        complex_t result = complex_sub(complex1, complex2);
        printf("Subtract of (%3.2f,%3.2f) and (%3.2f,%3.2f): (%3.2f,%3.2f)\n", complex1.real, complex1.imag, complex2.real, complex2.imag, result.real, result.imag);
    }

    for (size_t i = 0; i < ARRAY_LENGTH(complex_mul_inputs); i++)
    {
        complex_t complex1 = complex_mul_inputs[i][0];
        complex_t complex2 = complex_mul_inputs[i][1];
        complex_t result = complex_mul(complex1, complex2);
        printf("Multiplication of (%3.2f,%3.2f) and (%3.2f,%3.2f): (%3.2f,%3.2f)\n", complex1.real, complex1.imag, complex2.real, complex2.imag, result.real, result.imag);
    }

    for (size_t i = 0; i < ARRAY_LENGTH(complex_div_inputs); i++)
    {
        complex_t complex1 = complex_div_inputs[i][0];
        complex_t complex2 = complex_div_inputs[i][1];
        complex_t result = complex_div(complex1, complex2);
        printf("Division of (%3.2f,%3.2f) and (%3.2f,%3.2f): (%3.2f,%3.2f)\n", complex1.real, complex1.imag, complex2.real, complex2.imag, result.real, result.imag);
    }

    for (size_t i = 0; i < ARRAY_LENGTH(complex_abs_inputs); i++)
    {
        complex_t complex = complex_abs_inputs[i];
        printf("Abs of (%3.2f,%3.2f): %3.2f\n", complex.real, complex.imag, complex_abs(complex));
    }

    for (size_t i = 0; i < ARRAY_LENGTH(complex_conjugate_inputs); i++)
    {
        complex_t complex = complex_conjugate_inputs[i];
        complex_t result = complex_conjugate(complex);
        printf("Conjugate of (%3.2f,%3.2f): (%3.2f,%3.2f)\n", complex.real, complex.imag, result.real, result.imag);
    }

    for (size_t i = 0; i < ARRAY_LENGTH(complex_exp_inputs); i++)
    {
        complex_t complex = complex_exp_inputs[i];
        complex_t result = complex_exp(complex);
        printf("Exp of (%3.2f,%3.2f): (%3.2f,%3.2f)\n", complex.real, complex.imag, result.real, result.imag);
    }

    print_separator();

    // Sum of Multiples
    const unsigned int multiples[16][5] = {
        {3, 5},
        {3, 5},
        {3},
        {3, 5},
        {3, 5},
        {3, 5},
        {7, 13, 17},
        {4, 6},
        {5, 6, 8},
        {5, 25},
        {43, 47},
        {1},
        {0},
        {0},
        {3, 0},
        {2, 3, 5, 7, 11}};
    const unsigned int limits[16] = {1, 4, 7, 10, 100, 1000, 20, 15, 150, 51, 10000, 100, 1000, 1, 4, 10000};

    for (size_t i = 0; i < 16; i++)
    {
        char multiples_str[20] = "";
        for (size_t j = 0; j < 5; j++)
        {
            if (multiples[i][j] == 0)
                continue;
            char temp[10] = "";
            sprintf(temp, "%d", multiples[i][j]);
            strcat(multiples_str, temp);
            if (multiples[i][j + 1] > 0)
            {
                strcat(multiples_str, ",");
            }
        }

        printf("Sum of multiples (%s): %d\n", multiples_str, sum_of_multiples(multiples[i], 5, limits[i]));
    }

    print_separator();

    // Nucleotide Count
    const char *nucleotide_count_inputs[] = {
        "",
        "G",
        "GGGGGGG",
        "AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC",
        "AGXXACT"};

    for (size_t i = 0; i < ARRAY_LENGTH(nucleotide_count_inputs); i++)
    {
        const char *input = nucleotide_count_inputs[i];
        char *result = nucleotide_count(input);
        printf("Nucleotide count (%s): %s\n", input, result);
        free(result);
    }

    print_separator();

    // Yacht
    yacht_dice_t yacht_dices[29] = {
        {{5, 5, 5, 5, 5}},
        {{1, 3, 3, 2, 5}},
        {{1, 1, 1, 3, 5}},
        {{3, 1, 1, 5, 1}},
        {{4, 3, 6, 5, 5}},
        {{2, 3, 4, 5, 6}},
        {{1, 4, 1, 4, 1}},
        {{3, 3, 3, 3, 3}},
        {{3, 3, 3, 3, 3}},
        {{1, 5, 3, 5, 3}},
        {{2, 3, 4, 5, 6}},
        {{2, 2, 4, 4, 4}},
        {{5, 3, 3, 5, 3}},
        {{2, 2, 4, 4, 5}},
        {{1, 4, 4, 4, 4}},
        {{2, 2, 2, 2, 2}},
        {{6, 6, 4, 6, 6}},
        {{3, 3, 3, 3, 3}},
        {{3, 3, 3, 5, 5}},
        {{3, 5, 4, 1, 2}},
        {{1, 2, 3, 4, 5}},
        {{1, 1, 2, 3, 4}},
        {{1, 2, 3, 4, 6}},
        {{1, 1, 3, 4, 5}},
        {{4, 6, 2, 5, 3}},
        {{6, 5, 4, 3, 2}},
        {{6, 5, 4, 3, 1}},
        {{3, 3, 5, 6, 6}},
        {{2, 2, 2, 2, 2}}};
    yacht_mode_t yacht_modes[29] = {
        YACHT_YACHT_MODE,
        YACHT_YACHT_MODE,
        YACHT_ONES_MODE,
        YACHT_ONES_MODE,
        YACHT_ONES_MODE,
        YACHT_TWOS_MODE,
        YACHT_FOURS_MODE,
        YACHT_THREES_MODE,
        YACHT_FIVES_MODE,
        YACHT_FIVES_MODE,
        YACHT_SIXES_MODE,
        YACHT_FULL_HOUSE_MODE,
        YACHT_FULL_HOUSE_MODE,
        YACHT_FULL_HOUSE_MODE,
        YACHT_FULL_HOUSE_MODE,
        YACHT_FULL_HOUSE_MODE,
        YACHT_FOUR_OF_A_KIND_MODE,
        YACHT_FOUR_OF_A_KIND_MODE,
        YACHT_FOUR_OF_A_KIND_MODE,
        YACHT_LITTLE_STRAIGHT_MODE,
        YACHT_BIG_STRAIGHT_MODE,
        YACHT_LITTLE_STRAIGHT_MODE,
        YACHT_LITTLE_STRAIGHT_MODE,
        YACHT_LITTLE_STRAIGHT_MODE,
        YACHT_BIG_STRAIGHT_MODE,
        YACHT_LITTLE_STRAIGHT_MODE,
        YACHT_BIG_STRAIGHT_MODE,
        YACHT_CHOICE_MODE,
        YACHT_CHOICE_MODE};

    for (size_t i = 0; i < 29; i++)
    {
        yacht_dice_t dice = yacht_dices[i];
        yacht_mode_t mode = yacht_modes[i];
        const char *mode_name = yacht_mode_name(mode);
        char dice_str[10] = {0};

        for (size_t i = 0; i < YACHT_DICE_COUNT; i++)
        {
            char temp[2] = {0};
            sprintf(temp, "%d", dice.faces[i]);
            strcat(dice_str, temp);
            if (i + 1 != YACHT_DICE_COUNT)
            {
                strcat(dice_str, ",");
            }
        }
        dice_str[9] = '\0';

        printf("Dice faces (%s) score in mode %s: %d\n", dice_str, mode_name, yacht_score(dice, mode));
    }

    print_separator();

    // Phone Number
    const char *phone_number_inputs[] = {
        "(223) 456-7890",
        "223.456.7890",
        "223 456   7890   ",
        "123456789",
        "22234567890",
        "12234567890",
        "+1 (223) 456-7890",
        "321234567890",
        "523-abc-7890",
        "523-@:!-7890",
        "(023) 456-7890",
        "(123) 456-7890",
        "(223) 056-7890",
        "(223) 156-7890",
        "1 (023) 456-7890",
        "1 (123) 456-7890",
        "1 (223) 056-7890",
        "1 (123) 156-7890"};

    for (size_t i = 0; i < ARRAY_LENGTH(phone_number_inputs); i++)
    {
        const char *phone_number = phone_number_inputs[i];
        printf("Phone number cleaned (%s): %s\n", phone_number, phone_number_clean(phone_number));
    }

    print_separator();

    // Pythagorean Triplet
    uint16_t pythagorean_triplet_sum[] = {12, 108, 1000, 1001, 90, 840, 30000};

    for (size_t i = 0; i < ARRAY_LENGTH(pythagorean_triplet_sum); i++)
    {
        triplets_t *triplets = triplets_with_sum(pythagorean_triplet_sum[i]);

        printf("Triplets for (%d): ", pythagorean_triplet_sum[i]);
        print_triplets(triplets, true);
        free_triplets(triplets);
    }

    print_separator();

    // Protein Translation
    const char *const protein_translation_rnas[] = {
        "",
        "AUG",
        "UUU",
        "UUC",
        "UUA",
        "UUG",
        "UCU",
        "UCC",
        "UCA",
        "UCG",
        "UAU",
        "UAC",
        "UGU",
        "UGG",
        "UAA",
        "UAG",
        "UGA",
        "UUUUUU",
        "UUAUUG",
        "AUGUUUUGG",
        "UAGUGG",
        "UGGUAG",
        "AUGUUUUAA",
        "UGGUAGUGG",
        "UGGUGUUAUUAAUGGUUU",
        "AAA",
        "XYZ",
        "AUGU",
        "UUCUUCUAAUGGU"};

    for (size_t i = 0; i < ARRAY_LENGTH(protein_translation_rnas); i++)
    {
        const char *rna = protein_translation_rnas[i];

        proteins_t proteins = protein_translation(rna);
        
        printf("Protein translation for rna (%s): ", rna);
    
        print_proteins(proteins, true);
    }
    
}

void print_separator()
{
    puts("-------------------------------------------------------");
}

static inline time_t days_from_1ad(int year)
{
    --year;
    return 365 * year + (year / 400) - (year / 100) + (year / 4);
}

static time_t construct_date(int year, int month, int day, int hour, int min, int sec)
{
    static const time_t seconds_in_day = 86400;
    static const time_t days[2][12] = {
        {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
        {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335}};

    time_t days_since_epoch = (days_from_1ad(year) - days_from_1ad(1970)) + days[is_leap_year(year)][(month - 1)] + (day - 1);

    time_t result = (seconds_in_day * days_since_epoch) + (60 * ((hour * 60) + min) + sec);

    return result;
}

static void print_triplets(const triplets_t *triplets, bool endl)
{
    if (triplets->count == 0)
    {
        printf("[]");
    }
    else
    {
        printf("[");

        for (size_t i = 0; i < triplets->count; i++)
        {
            printf("(%d, %d, %d)", triplets->triplets[i].a, triplets->triplets[i].b, triplets->triplets[i].c);
            if (i < triplets->count - 1)
            {
                printf(", ");
            }
        }

        printf("]");
    }

    if (endl)
    {
        printf("\n");
    }
}

static void print_proteins(const proteins_t proteins, bool endl)
{
    if (proteins.count == 0)
    {
        printf("[]");
    }
    else
    {
        printf("[");

    for (size_t i = 0; i < proteins.count; i++)
    {
        printf("%s", protein_name(proteins.proteins[i]));
        if (i < proteins.count - 1)
        {
            printf(", ");
        }
    }

        printf("]");
    }

    if (endl)
    {
        printf("\n");
    }
}
