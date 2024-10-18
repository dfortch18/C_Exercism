#ifndef C_EXERCISM_PERFECT_NUMBERS_H
#define C_EXERCISM_PERFECT_NUMBERS_H

#include <stddef.h>

typedef enum perfect_numbers_kind
{
    PN_PERFECT_NUMBER = 1,
    PN_ABUNDANT_NUMBER = 2,
    PN_DEFICIENT_NUMBER = 3,
    PN_ERROR = -1
} perfect_numbers_kind_t;

perfect_numbers_kind_t perfect_numbers_classify_number(size_t);

const char *perfect_numbers_kind_name(perfect_numbers_kind_t);

#endif