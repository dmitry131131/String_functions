#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Source\StringFunctions.h"

int main()
{
    char rexr[20] = "ddde33";
    char rext[] = "5555";
    char text[30] = {};

    char* pp = strdup_custom(rexr);

    puts_custom(pp);

    free(pp);

    return 0;
}