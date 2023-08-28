#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Source\StringFunctions.h"

int main()
{
    char* t = NULL;

    t = strstr_custom("0123456789", "3");

    printf("%s", t);

    return 0;
}