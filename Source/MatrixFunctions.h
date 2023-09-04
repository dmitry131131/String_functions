/**
 * @file
 * @brief Functions working with double arrays and matrix
*/

char* rect_arr_input(size_t rows, size_t cols, FILE* stream);

int rect_arr_output(size_t rows, size_t cols, const char* array, FILE* stream);

int* triangle_arr_input(size_t rows, FILE* stream);

int triangle_arr_output(size_t rows, const int* array, FILE* stream);