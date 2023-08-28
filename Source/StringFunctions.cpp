#include <stdio.h>
#include <stdlib.h>

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

const char* strchr_custom(const char* string, int ch)
{
    if (*string == ch) return string;

    while (*string != '\0')
    {
        if (*string == ch) return string;

        string++;
    }

    return NULL;
}

size_t strlen_custom(const char* string)
{
    size_t len = 0;
    while (*string != '\0')
    {
        len++;
        string++;
    }
    return len;
}

char* strcpy_custom(char* destination, const char* source)
{
    if (destination == NULL || source == NULL) return NULL;

    char* ptr = destination;

    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = *source;

    return ptr;
}

char* strncpy_custom(char* destination, const char* source, size_t n)
{
    if (destination == NULL || source == NULL) return NULL;

    char* ptr = destination;

    while ((*source != '\0') && (n))
    {
        *destination = *source;
        destination++;
        source++;
        n--;
    }

    *destination = '\0';

    while (n)
    {
        *destination = '\0';
        destination++;
        n--;
    }

    return ptr;
}

char* strcat_custom(char* destination, const char* append)
{
    if (destination == NULL || append == NULL) return NULL;

    char* ptr = destination;

    while (*destination != '\0') destination++;

    while (*append != '\0')
    {
        *destination = *append;
        destination++;
        append++;
    }

    *destination = *append;

    return ptr;
}

char* strncat_custom(char* destination, const char* append, size_t n)
{
    if (destination == NULL || append == NULL) return NULL;

    char* ptr = destination;

    while (*destination != '\0') destination++;

    while ((*append != '\0') && (n))
    {
        *destination = *append;
        destination++;
        append++;
        n--;
    }

    *destination = '\0';

    while (n)
    {
        *destination = '\0';
        destination++;
        n--;
    }

    return ptr;
}

char* fgets_custom(char* string, int n, FILE* stream)
{
    if ((string == NULL) || (stream == NULL)) return NULL;

    int ch = 0;
    char* ptr = string;
    while (((ch = getc(stream)) != '\n') && n && (ch != EOF))
    {
        *string = (char) ch;
        string++;
        n--;
    }

    *string = '\0';

    return ptr;
}

char* strdup_custom(const char* string)
{
    if (string == NULL) return NULL;
    
    int len = 0;
    const char* str = string;
    while (*str != '\0')
    {
        len++;
        str++;
    }

    char* ptr = (char*) calloc(len + 1, sizeof(char));

    for (int i = 0; i < len + 1; i++)
    {
        *(ptr + i) = *string;
        string++;
    }

    return ptr;
}

size_t getline_custom(char** string, size_t* n, FILE* stream)
{
    int ch = 0;
    *n = 0;

    *string = (char*) calloc(1, sizeof(char));

    while (((ch = getc(stream)) != '\n') && (ch != EOF))
    {
        realloc(*string, (*n + 1)*sizeof(char));
        (*string)[*n] = (char) ch;
        (*n)++;
    }
    if (ch == '\n') 
    {
        realloc(*string, (*n + 2)*sizeof(char));
        (*string)[*n] = '\n';
        (*string)[*n + 1] = '\0';
        (*n) += 2;
    }
    else
    {
        realloc(*string, (*n + 1)*sizeof(char));
        (*string)[*n] = '\0';
        (*n)++;
    }

    return *n;
}

char* strstr_custom(const char* strB, const char* strA)
{
    unsigned int LenA = 0;
    while (*(strA + LenA) != '\0') LenA++;

    unsigned int i = 0;
    while (*strB != '\0')
    {
        if (*(strB + i) == *(strA + i))
        {
            i++;
        }
        else
        {
            i = 0;
            strB++;
        }

        if (i == LenA)
        {
            char* StrPtr = (char*) strB;
            return StrPtr;
        }
    }

    return NULL;
}