#include <stdio.h>
#include <stdlib.h>

#include "StringFunctions.h"


int puts_custom(const char* string)
{   
    if (!string) return EOF;

    while (*string != '\0')
    {
        if (putchar(*string) == EOF) return EOF;
        string++;
    }

    if (putchar('\n') == EOF) return EOF;

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
    const char* strStart =  string;
    while (*(string) != '\0') string++;

    return string - strStart;
}

char* strcpy_custom(char* destination, const char* source)
{
    if (destination == NULL || source == NULL) return NULL;

    char* ptr = destination;

    do
    {
        *destination++ = *source++;
    } while (*source != '\0');

    return ptr;
}

char* strncpy_custom(char* destination, const char* source, size_t n)
{
    if (destination == NULL || source == NULL) return NULL;

    char* ptr = destination;

    while ((*source != '\0') && (n))
    {
        *destination++ = *source++;
        n--;
    }

    while (n)
    {
        *destination++ = '\0';
        n--;
    }

    return ptr;
}

char* strcat_custom(char* destination, const char* append)
{
    if (destination == NULL || append == NULL) return NULL;

    char* ptr = destination;

    destination += strlen_custom(destination);

    strcpy_custom(destination, append);

    return ptr;
}

char* strncat_custom(char* destination, const char* append, size_t n)
{
    if (destination == NULL || append == NULL) return NULL;

    char* ptr = destination;

    destination += strlen_custom(destination);

    strncpy_custom(destination, append, n);

    return ptr;
}

char* fgets_custom(char* string, int n, FILE* stream)
{
    if ((string == NULL) || (stream == NULL) || (feof(stream))) return NULL;

    int ch = 0;
    char* ptr = string;
    while (((ch = getc(stream)) != '\n') && (n - 1) && (ch != EOF))
    {
        *string++ = (char) ch;
        n--;
    }

    *string = '\0';

    return ptr;
}

char* strdup_custom(const char* string)
{
    if (string == NULL) return NULL;
    
    size_t len = strlen_custom(string);

    char* ptr = (char*) calloc(len + 1, sizeof(char));

    strcpy_custom(ptr, string);

    return ptr;
}

size_t getline_custom(char** string, size_t* n, FILE* stream)
{
    size_t MemorySizeCount = ((size_t) *n / MinMemorySize) + 1;
    if (!(*string))
    {
        *string = (char*) calloc(MinMemorySize, sizeof(char));
        *n = MinMemorySize;
        MemorySizeCount++;
    }

    size_t i = 0;
    int ch = getc(stream);
    if (ch == EOF) return -1;

    do
    {
        (*string)[i] = (char) ch;
        i++;

        if (i == *n)
        { 
            *string = (char*) realloc(*string, (MemorySizeCount * MinMemorySize) * sizeof(char));
            *n = MinMemorySize * MemorySizeCount;
            MemorySizeCount++;
        }

    } while ((ch = getc(stream)) != '\n' && (ch != EOF) && (i <= *n));

    (*string)[i] = '\0';

    return i;
}

const char* strstr_custom(const char* strB, const char* strA)
{
    size_t LenA = 0;
    while (*(strA + LenA) != '\0') LenA++;

    size_t i = 0;
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
            return strB;
        }
    }

    return NULL;
}

const char* strstrh_custom(const char* text, const char* pattern)
{
    size_t PatternLen = strlen_custom(pattern);
    int hashP = hash(pattern, PatternLen);
    int hashT = hash(text, PatternLen);

    while (*(text) != '\0')
    {
        if (hashP == hashT)
        {
            if (strCompare(text, pattern, PatternLen)) return text;
        }
        hashT = ((hashT * (*(text + PatternLen))) / *(text));
        text++;
    }

    return NULL;
}

int hash(const char* str, size_t len)
{
    int has = 1;
    for (size_t i = 0; i < len; i++)
    {
        has *= *(str + i);
    }

    return has;
}

int strCompare(const char* first, const char* second, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        if (*(first + i) != *(second + i)) return 0;
    }

    return 1;
}

int strstrC_custom(const char* text, const char* pattern)
{
    const char* ptr = text - 1;
    int count = 0;
    while ((ptr = strstrh_custom(ptr + 1, pattern)))
    {
        count++;
    }

    return count;
}