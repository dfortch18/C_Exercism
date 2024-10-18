#ifndef C_EXERCISM_DND_CHARACTER
#define C_EXERCISM_DND_CHARACTER

typedef struct dnd_character
{
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
    int hitpoints;
} dnd_character_t;

int dnd_character_ability();

int dnd_character_modifier(int);

dnd_character_t make_dnd_character();

void print_dnd_character(dnd_character_t *character);

#endif