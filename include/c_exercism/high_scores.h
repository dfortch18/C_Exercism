#ifndef C_EXERCISM_HIGH_SCORES_H
#define C_EXERCISM_HIGH_SCORES_H

#include <stddef.h>
#include <stdint.h>

int32_t high_scores_latest(const int32_t *scores, size_t scores_len);

int32_t high_scores_personal_best(const int32_t *scores, size_t scores_len);

size_t high_scores_personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output);

#endif