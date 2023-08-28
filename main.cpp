#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Source\StringFunctions.h"

int main()
{
    char* t = NULL;

    getline_custom(&t, 5, stdin);

    printf("%s", t);

    printf("fff\n");

    free(t);

    return 0;
}