#include "c_exercism/allergies.h"
#include <stddef.h>

static const allergen_t ALLERGENS[ALLERGEN_COUNT] = {
    ALLERGEN_EGGS,
    ALLERGEN_PEANUTS,
    ALLERGEN_SHELLFISH,
    ALLERGEN_STRAWBERRIES,
    ALLERGEN_TOMATOES,
    ALLERGEN_CHOCOLATE,
    ALLERGEN_POLLEN,
    ALLERGEN_CATS};

bool is_allergic_to(allergen_t allergen, int score)
{
    return (score & allergen) != 0;
}

allergen_list_t get_allergens_for(int score)
{
    allergen_list_t list = {0, {false}};

    for (size_t i = 0; i < ALLERGEN_COUNT; i++)
    {
        if (is_allergic_to(ALLERGENS[i], score))
        {
            list.allergens[ALLERGENS[i]] = true;
            list.count++;
        }
    }

    return list;
}

const allergen_t *get_all_allergens()
{
    return ALLERGENS;
}

const char *get_allergen_name(allergen_t allergen)
{
    switch (allergen)
    {
    case ALLERGEN_EGGS:
        return "ALLERGEN_EGGS";
    case ALLERGEN_PEANUTS:
        return "ALLERGEN_PEANUTS";
    case ALLERGEN_SHELLFISH:
        return "ALLERGEN_SHELLFISH";
    case ALLERGEN_STRAWBERRIES:
        return "ALLERGEN_STRAWBERRIES";
    case ALLERGEN_TOMATOES:
        return "ALLERGEN_TOMATOES";
    case ALLERGEN_CHOCOLATE:
        return "ALLERGEN_CHOCOLATE";
    case ALLERGEN_POLLEN:
        return "ALLERGEN_POLLEN";
    case ALLERGEN_CATS:
        return "ALLERGEN_CATS";
    default:
        return "INVALID";
    }
}
