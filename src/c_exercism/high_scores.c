#include "c_exercism/high_scores.h"
#include <stdio.h>

int32_t high_scores_latest(const int32_t *scores, size_t scores_len)
{
    return scores[scores_len - 1];
}

int32_t high_scores_personal_best(const int32_t *scores, size_t scores_len)
{
    int max = 0;
    for (size_t i = 0; i < scores_len; i++)
    {
        if (max < scores[i])
        {
            max = scores[i];
        }
    }
    return max;
}

size_t high_scores_personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output)
{
    int temp_scores[scores_len];

    for (size_t i = 0; i < scores_len; i++)
    {
        temp_scores[i] = scores[i];
    }

    for (size_t i = 0; i < scores_len; i++)
    {
        for (size_t j = i + 1; j < scores_len; j++)
        {
            if (temp_scores[j] > temp_scores[i])
            {
                int32_t temp = temp_scores[i];
                temp_scores[i] = temp_scores[j];
                temp_scores[j] = temp;
            }
        }
        
    }
    
    size_t top_count = (scores_len < 3) ? scores_len : 3;

    for (size_t i = 0; i < top_count; i++)
    {
        output[i] = temp_scores[i];
    }
    return top_count;
}
