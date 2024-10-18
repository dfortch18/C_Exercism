#include "c_exercism/dnd_character.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int dnd_character_ability()
{
    srand(time(NULL));
    return rand() % 6 + 1;
}

int dnd_character_modifier(int score)
{
    return floor((double)(score - 10) / 2);
}

dnd_character_t make_dnd_character()
{
    dnd_character_t character;
    character.strength = dnd_character_ability();
    character.dexterity = dnd_character_ability();
    character.constitution = dnd_character_ability();
    character.intelligence = dnd_character_ability();
    character.wisdom = dnd_character_ability();
    character.charisma = dnd_character_ability();
    character.hitpoints = dnd_character_modifier(character.constitution) + 10;
    return character;
}

void print_dnd_character(dnd_character_t *character)
{
    printf("Character %p\n", character);
    printf("Dexterity: %d\n", character->dexterity);
    printf("Constitution: %d\n", character->constitution);
    printf("Intelligence: %d\n", character->intelligence);
    printf("Wisdom: %d\n", character->wisdom);
    printf("Charisma: %d\n", character->charisma);
    printf("Hitpoints: %d\n", character->hitpoints);
}
