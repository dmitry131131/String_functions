/**
 * @file
 * @brief Functions working with double arrays and matrix
*/

enum OutputMode {
    CHAR,
    INT
};

char* rect_arr_input(size_t rows, size_t cols, FILE* stream);

int rect_arr_output(size_t rows, size_t cols, const int* array, FILE* stream);

int* triangle_arr_input(size_t rows, FILE* stream);

int triangle_arr_output(size_t rows, const int* array, FILE* stream);

int array_getter(int row, int num, int cols, const int* array);

int rect_arr_meta_output(const int* array, FILE* stream);

void dual_char_output(int symbol, FILE* stream);