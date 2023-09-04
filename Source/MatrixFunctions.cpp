/**
 * @file
 * @brief Functions working with matrixx and double arrays source
*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "MatrixFunctions.h"

char* rect_arr_input(size_t rows, size_t cols, FILE* stream)
{
    char* str = (char*) calloc(rows * cols, sizeof(char));

    int ch = 0;

    if (!str) return NULL;

    for(size_t i = 0; i < rows; i++)
    {
        assert(i < rows);

        for(size_t j = 0; j < (cols - 1); j++)
        {
            assert(j < cols);
            if ((ch = getc(stream)) == '\n')
            {
                j--;
                continue;
            }

            *(str + (i * cols) + j) = (char) ch;
        }

        *(str + (i * cols) + (cols - 1)) = '\0';

    }

    return str;
}

int rect_arr_output(size_t rows, size_t cols, const int* array, FILE* stream)
{
    if (!array) return 1;

    for(size_t i = 0; i < rows; i++)
    {
        assert(i < rows);

        for(size_t j = 0; j < cols; j++)
        {
            assert(j < cols);
            
            dual_char_output(array_getter(i, j, cols, array), stream);
        }
        putc('\n', stream);

    }

    return 0;
}

int* triangle_arr_input(size_t rows, FILE* stream)
{
    size_t count = (((rows+1) * rows) / 2);

    int* array = (int*) calloc(count, sizeof(int));

    for(size_t i = 0; i < count; i++)
    {
        if(!(fscanf(stream, "%d", array + i))) return NULL;
    }

    return array;
}

int triangle_arr_output(size_t rows, const int* array, FILE* stream)
{
    if(!array) return 1;

    size_t index = 0;
    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < (i + 1); j++)
        {
            fprintf(stream, "%d ", array[index]);
            index++;
        }
        fprintf(stream, "\n");
    }

    return 0;
}

int array_getter(int row, int num, int cols, const int* array)
{
    return *(array + (row * cols) + num);
}

void dual_char_output(int symbol, FILE* stream)
{
    fprintf(stream, "%c(%-3d)", symbol, symbol);
}

int rect_arr_meta_output(const int* array, FILE* stream)
{
    size_t rows = (size_t) array[0];
    size_t cols = (size_t) array[1];

    rect_arr_output(rows, cols, (array + 2), stream);

    return 0;
}