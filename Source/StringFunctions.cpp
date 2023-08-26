#include <stdio.h>

#include "StringFunctions.h"

int puts_custom(const char* string)
{   
    if (string)
    {
        while (*string != '\0')
        {
            if (putchar(*string) == EOF) return EOF;
            
            string++;
        }

        if (putchar('\n') == EOF) return EOF;
    }
    else return EOF;

    return 0;
}