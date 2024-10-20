#ifndef C_EXERCISM_GIGASECOND_H
#define C_EXERCISM_GIGASECOND_H

#include <time.h>

#define GIGASECOND_DATE_FORMAT "%Y-%m-%d %H:%M:%S"

#define GIGASECOND_DATE_FORMATTED_BUFFER_SIZE sizeof("YYYY-mm-dd HH:MM:SS")

void gigasecond(time_t, char *, size_t);

#endif