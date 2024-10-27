#ifndef C_EXERCISM_PROTEIN_TRANSLATION
#define C_EXERCISM_PROTEIN_TRANSLATION

#include <stdbool.h>
#include <stddef.h>

#define MAX_PROTEINS 10

typedef enum _protein
{
    Methionine,
    Phenylalanine,
    Leucine,
    Serine,
    Tyrosine,
    Cysteine,
    Tryptophan
} protein_t;

typedef struct _proteins
{
    bool valid;
    size_t count;
    protein_t proteins[MAX_PROTEINS];
} proteins_t;

proteins_t protein_translation(const char *const);

const char *protein_name(protein_t);

#endif