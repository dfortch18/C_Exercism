#include "c_exercism/two_fer.h"
#include <stdio.h>

static const char *TWO_FER_FORMAT = "One for %s, one for me.";

void two_fer(char *buffer, const char *name)
{
    if (name == NULL)
    {
        sprintf(buffer, TWO_FER_FORMAT, "you");
    }
    else
    {
        sprintf(buffer, TWO_FER_FORMAT, name);
    }
}
