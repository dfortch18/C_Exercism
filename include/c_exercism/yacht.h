#ifndef C_EXERCISM_YACHT_H
#define C_EXERCISM_YACHT_H

#define YACHT_DICE_COUNT 5

#define YACHT_STRAIGHT_SCORE 30

typedef enum _yacht_mode
{
    YACHT_ONES_MODE,
    YACHT_TWOS_MODE,
    YACHT_THREES_MODE,
    YACHT_FOURS_MODE,
    YACHT_FIVES_MODE,
    YACHT_SIXES_MODE,
    YACHT_FULL_HOUSE_MODE,
    YACHT_FOUR_OF_A_KIND_MODE,
    YACHT_LITTLE_STRAIGHT_MODE,
    YACHT_BIG_STRAIGHT_MODE,
    YACHT_CHOICE_MODE,
    YACHT_YACHT_MODE
} yacht_mode_t;

typedef struct _yacht_dice
{
    int faces[YACHT_DICE_COUNT];
} yacht_dice_t;

int yacht_score(yacht_dice_t, yacht_mode_t);

const char *yacht_mode_name(yacht_mode_t);

#endif