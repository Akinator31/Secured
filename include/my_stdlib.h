/*
** EPITECH PROJECT, 2024
** my_stdlib
** File description:
** my_stdlib header
*/

#ifndef MY_NULL_H_
    #define MY_NULL_H_

    #define MY_NULL ((void *)0)

#endif /* MY_NULL_H_ */

#ifndef MY_SIZE_T_H_
    #define MY_SIZE_T_H_

typedef unsigned long my_size_t;

#endif /* MY_SIZE_T_H_ */

#ifndef MY_WCHAR_T_H_
    #define MY_WCHAR_T_H_

typedef unsigned int my_wchar_t;

#endif /* MY_WCHAR_T_H_ */

#ifndef MY_STDLIB_H_
    #define  MY_STDLIB_H_

    // Macros
    #define MY_EXIT_FAILURE 84
    #define MY_EXIT_SUCCESS 0
    #define MY_RAND_MAX 2147483647
    #define ABS(x) x > 0 ? x : -x
    #define MIN(x, y) x < y ? x : y
    #define MAX(x, y) x > y ? x : y

// Structures
typedef struct my_div_s {
    int quot;
    int rem;
} my_div_t;

typedef struct my_ldiv_s {
    long int quot;
    long int rem;
} my_ldiv_t;

// Functions
double my_atof(const char *str);
int my_atoi(const char *str);
long int my_atol(const char *str);
double my_strtod(const char *str, char **endptr);
long int my_strtol(const char *str, char **endptr, int base);
char *my_ltoa(long value, char *str, int base);
char *my_itoa(int value, char *str, int base);
void *my_calloc(my_size_t nitems, my_size_t size);
void *my_realloc(void *ptr, my_size_t size);
void *my_reallocarray(void *ptr, my_size_t nmemb, my_size_t size);
int my_abs(int x);
my_div_t my_div(int numer, int denom);
long int my_labs(long int x);
my_ldiv_t my_ldiv(long int number, long int denom);

#endif /* MY_STDLIB_H_ */
