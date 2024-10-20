#ifndef C_EXERCISM_ALLERGIES_H
#define C_EXERCISM_ALLERGIES_H

#include <stdbool.h>

typedef enum _allergen
{
    ALLERGEN_EGGS = 1,
    ALLERGEN_PEANUTS = 2,
    ALLERGEN_SHELLFISH = 4,
    ALLERGEN_STRAWBERRIES = 8,
    ALLERGEN_TOMATOES = 16,
    ALLERGEN_CHOCOLATE = 32,
    ALLERGEN_POLLEN = 64,
    ALLERGEN_CATS = 128,
    ALLERGEN_MAX
} allergen_t;

#define ALLERGEN_COUNT 8

typedef struct _allergen_list
{
    int count;
    bool allergens[ALLERGEN_MAX];
} allergen_list_t;

bool is_allergic_to(allergen_t, int);

allergen_list_t get_allergens_for(int);

const allergen_t *get_all_allergens();

const char *get_allergen_name(allergen_t);

#endif