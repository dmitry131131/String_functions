/**
 * @file
 * @brief Custom string functions
*/
/// realloc memory step
const size_t MinMemorySize = 256;

/**
 * @brief Function put string in stdout flow and put '\n' symbol in the end of string
 * @param [in] string string pointer
 * @return EOF in case error and 0 in case no error
*/
int puts_custom(const char* string);
/**
 * @brief Function search ch in string and return pointer to first entry ch in string
 * @param [in] string pointer to string
 * @param [in] ch code of the target symbol 
 * @return pointer to symbol or NULL if symbol not found
*/
const char* strchr_custom(const char* string, int ch);
/**
 * @brief Function returns length of string 
 * @param [in] string string pointer
 * @return length of string
*/
size_t strlen_custom(const char* string);
/**
 * @brief Function copy string data from source to destination 
 * @param [in] destination destination of copying
 * @param [in] source sourse of copying
 * @return pointer to destination
*/
char* strcpy_custom(char* destination, const char* source);
/**
 * @brief Function copy n symbols of string data from source to destination with '\0' symbol
 * @param [in] destination destination of copying
 * @param [in] source sourse of copying
 * @param [in] n length of copying string
 * @return pointer to destination
*/
char* strncpy_custom(char* destination, const char* source, size_t n);
/**
 * @brief Function append append string in the end of destination and returns destination pointer
 * @param [in] destination target string 
 * @param [in] append append string
 * @return destination pointer
*/
char* strcat_custom(char* destination, const char* append);
/**
 * @brief Function append n symbols of append string in the end of destination and returns destination pointer
 * @param [in] destination target string 
 * @param [in] append append string
 * @param [in] n length of append string
 * @return destination pointer
*/
char* strncat_custom(char* destination, const char* append, size_t n);
/**
 * @brief Read first n symbols of string ot until found '\n'
 * @param [in] string target symbol array 
 * @param [in] n max length of string
 * @param [in] stream input flow
 * @return pointer to string array
*/
char* fgets_custom(char* string, int n, FILE* stream);
/**
 * @brief Make dublicate of string and allocates memory for this
 * @param [in] string input string
 * @return pointer to dublicate string
*/
char* strdup_custom(const char* string);
/**
 * @brief Gets string from stream, allocs memory for string put pointer to memory to string and returns len of memory
 * @param [out] string pointer to alloced symbol array 
 * @param [in] n size of symbols array
 * @param [in] stream input flow
 * @return Size of alloced memory  
*/
size_t getline_custom(char** string, size_t* n, FILE* stream);
/**
 * @brief Function find strA in strB and return pointer to first found
 * @param [in] strB string where function find strA
 * @param [in] strA searched string
 * @return pointer to first found of strA in strB
*/
const char* strstr_custom(const char* strB, const char* strA);

const char* strstrh_custom(const char* strB, const char* strA);

int hash(const char* str, size_t len);

int strCompare(const char* first, const char* second, size_t len);

int strstrC_custom(const char* text, const char* pattern);