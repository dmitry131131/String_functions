#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Source\StringFunctions.h"

int main()
{
    /*
    char* tex = (char*) calloc(2, sizeof(char));
    size_t n = 2;

    printf("%d\n", getline_custom(&tex, &n, stdin));

    printf("%d\n", n);

    printf("%s", tex);

    free(tex);
    */

    printf("%s", strstr_custom("0123456789", "5678"));

    return 0;
}