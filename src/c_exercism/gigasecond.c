#include "c_exercism/gigasecond.h"


#define GIGASECOND 1000000000

void gigasecond(time_t input, char *output, size_t size)
{
    time_t new_time = input + GIGASECOND;

    struct tm *result_time = localtime(&new_time);
    strftime(output, size, GIGASECOND_DATE_FORMAT, result_time);
}