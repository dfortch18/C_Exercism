#include "c_exercism/protein_translation.h"
#include <string.h>

static protein_t translate_codon(const char *codon)
{
    if (strcmp(codon, "AUG") == 0)
        return Methionine;
    if (strcmp(codon, "UUU") == 0 || strcmp(codon, "UUC") == 0)
        return Phenylalanine;
    if (strcmp(codon, "UUA") == 0 || strcmp(codon, "UUG") == 0)
        return Leucine;
    if (strcmp(codon, "UCU") == 0 || strcmp(codon, "UCC") == 0 || strcmp(codon, "UCA") == 0 || strcmp(codon, "UCG") == 0)
        return Serine;
    if (strcmp(codon, "UAU") == 0 || strcmp(codon, "UAC") == 0)
        return Tyrosine;
    if (strcmp(codon, "UGU") == 0 || strcmp(codon, "UGC") == 0)
        return Cysteine;
    if (strcmp(codon, "UGG") == 0)
        return Tryptophan;
    if (strcmp(codon, "UAA") == 0 || strcmp(codon, "UAG") == 0 || strcmp(codon, "UGA") == 0)
        return -2;
    return -1;
}

proteins_t protein_translation(const char *const rna)
{
    proteins_t result = {.valid = true, .count = 0};
    char codon[4] = {0};

    for (size_t i = 0; i < strlen(rna); i += 3)
    {
        if (i + 3 > strlen(rna))
        {
            result.valid = false;
            return result;
        }

        strncpy(codon, rna + i, 3);
        protein_t protein = translate_codon(codon);

        if ((int)protein == -2) break;

        if ((int)protein == -1)
        {
            result.valid = false;
            return result;
        }

        if (result.count < MAX_PROTEINS)
        {
            result.proteins[result.count++] = protein;
        }
        else
        {
            result.valid = false;
            return result;
        }
    }

    return result;
}

const char *protein_name(protein_t protein)
{
    switch (protein)
    {
    case Methionine:
        return "Methionine";
    case Phenylalanine:
        return "Phenylalanine";
    case Leucine:
        return "Leucine";
    case Serine:
        return "Serine";
    case Tyrosine:
        return "Tyrosine";
    case Cysteine:
        return "Cysteine";
    case Tryptophan:
        return "Tryptophan";
    default:
        return "Unknown";
    }
}
