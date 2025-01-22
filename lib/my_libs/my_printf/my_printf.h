/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** task02
*/

#ifndef MY_H
    #define MY_H
    #define NB_FORMATTER 5
    #include <stdarg.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_printf(const char *format, ...);
void print_percent(va_list *list, __attribute__((unused)) int *nb_output_char);
void print_char(va_list *list, __attribute__((unused)) int *nb_output_char);
void print_string(va_list *list, __attribute__((unused)) int *nb_output_char);
void print_dec_oct_hex_integer(va_list *list,
    __attribute__((unused)) int *nb_output_char);

typedef struct format_specifier {
    char format_specifier;
    void (*f)(va_list *list, int *nb_output_char);
} format_specifier_t;

#endif
