#include "c_exercism/yacht.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

static int *yacht_dice_get_counts(yacht_dice_t dice)
{
    int *counts = malloc(6 * sizeof(int));

    if (counts == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < 6; i++)
    {
        counts[i] = 0;
    }

    for (size_t i = 0; i < YACHT_DICE_COUNT; i++)
    {
        counts[dice.faces[i] - 1]++;
    }

    return counts;
}

static int yacht_normal_score(yacht_dice_t dice, int value)
{
    int count = 0;

    for (size_t i = 0; i < YACHT_DICE_COUNT; i++)
    {
        if (dice.faces[i] == value)
        {
            count++;
        }
    }
    return value * count;
}

static int yacht_full_house_score(yacht_dice_t dice)
{
    int *counts = yacht_dice_get_counts(dice);

    bool has_three_of_a_kind = false;
    bool has_two_of_a_kind = false;

    for (size_t i = 0; i < 6; i++)
    {
        if (counts[i] == 3)
        {
            has_three_of_a_kind = true;
        }
        if (counts[i] == 2)
        {
            has_two_of_a_kind = true;
        }
    }

    free(counts);

    if (!(has_three_of_a_kind && has_two_of_a_kind))
    {
        return 0;
    }

    int score = 0;
    for (size_t i = 0; i < YACHT_DICE_COUNT; i++)
    {
        score += dice.faces[i];
    }
    return score;
}

static int yacht_four_of_a_kind_score(yacht_dice_t dice)
{
    int *counts = yacht_dice_get_counts(dice);

    bool has_four_of_a_kind = false;
    int kind = -1;

    for (size_t i = 0; i < 6; i++)
    {
        if (counts[i] >= 4)
        {
            has_four_of_a_kind = true;
            kind = i + 1;
        }
    }

    free(counts);

    if (!has_four_of_a_kind)
    {
        return 0;
    }

    return kind * 4;
}

static int yacht_little_straight_score(yacht_dice_t dice)
{
    int *counts = yacht_dice_get_counts(dice);

    for (int x = 1; x <= 5; x++)
    {
        if (counts[x - 1] < 1)
        {
            return 0;
        }
    }

    free(counts);

    return YACHT_STRAIGHT_SCORE;
}

static int yacht_big_straight_score(yacht_dice_t dice)
{
    int *counts = yacht_dice_get_counts(dice);

    for (int x = 2; x <= 6; x++)
    {
        if (counts[x - 1] < 1)
        {
            return 0;
        }
    }

    free(counts);

    return YACHT_STRAIGHT_SCORE;
}

static int yacht_choice_score(yacht_dice_t dice)
{
    int score = 0;
    for (size_t i = 0; i < YACHT_DICE_COUNT; i++)
    {
        score += dice.faces[i];
    }
    return score;
}

static int yacht_yacht_score(yacht_dice_t dice)
{
    int *counts = yacht_dice_get_counts(dice);

    for (size_t i = 0; i < 6; i++)
    {
        if (counts[i] == 5)
        {
            return 50;
        }
    }

    free(counts);

    return 0;
}

int yacht_score(yacht_dice_t dice, yacht_mode_t mode)
{
    if (mode >= YACHT_ONES_MODE && mode <= YACHT_SIXES_MODE)
    {
        return yacht_normal_score(dice, (int)mode + 1);
    }
    else if (mode == YACHT_FULL_HOUSE_MODE)
    {
        return yacht_full_house_score(dice);
    }
    else if (mode == YACHT_FOUR_OF_A_KIND_MODE)
    {
        return yacht_four_of_a_kind_score(dice);
    }
    else if (mode == YACHT_LITTLE_STRAIGHT_MODE)
    {
        return yacht_little_straight_score(dice);
    }
    else if (mode == YACHT_BIG_STRAIGHT_MODE)
    {
        return yacht_big_straight_score(dice);
    }
    else if (mode == YACHT_CHOICE_MODE)
    {
        return yacht_choice_score(dice);
    }
    else if (mode == YACHT_YACHT_MODE)
    {
        return yacht_yacht_score(dice);
    }
    else
    {
        return 0;
    }
}

const char *yacht_mode_name(yacht_mode_t mode)
{
    switch (mode)
    {
    case YACHT_ONES_MODE:
        return "ONES_MODE";
    case YACHT_TWOS_MODE:
        return "TWOS_MODE";
    case YACHT_THREES_MODE:
        return "THREES_MODE";
    case YACHT_FOURS_MODE:
        return "FOURS_MODE";
    case YACHT_FIVES_MODE:
        return "FIVES_MODE";
    case YACHT_SIXES_MODE:
        return "SIXES_MODE";
    case YACHT_FULL_HOUSE_MODE:
        return "FULL_HOUSE_MODE";
    case YACHT_FOUR_OF_A_KIND_MODE:
        return "FOUR_OF_A_KIND_MODE";
    case YACHT_LITTLE_STRAIGHT_MODE:
        return "LITTLE_STRAIGHT_MODE";
    case YACHT_BIG_STRAIGHT_MODE:
        return "BIG_STRAIGHT_MODE";
    case YACHT_CHOICE_MODE:
        return "CHOICE_MODE";
    case YACHT_YACHT_MODE:
        return "YACHT_MODE";
    default:
        return "INVALID";
    }
}
