/*
** EPITECH PROJECT, 2024
** my_printf.c
** File description:
** A simple version of printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"

void print_dec_oct_hex_integer(va_list *list, int *nb_output_char)
{
    int value = va_arg(*list, int);

    *nb_output_char += my_put_nbr(value);
}

void print_string(va_list *list, __attribute__((unused)) int *nb_output_char)
{
    char *str = (char *)va_arg(*list, char *);

    my_putstr(str);
}

void print_char(va_list *list, __attribute__((unused)) int *nb_output_char)
{
    char character = va_arg(*list, int);

    my_putchar(character);
}

void print_percent(__attribute__((unused)) va_list *list,
    __attribute__((unused)) int *nb_output_char)
{
    my_putchar('%');
}

static void compute(int *nb_output_char, const char *format,
    int index, va_list *list)
{
    int i;
    static const format_specifier_t specifier_arr[] = {
        {'d', &print_dec_oct_hex_integer},
        {'i', &print_dec_oct_hex_integer},
        {'s', &print_string},
        {'c', &print_char},
        {'%', &print_percent}
    };

    for (i = 0; i < NB_FORMATTER; i++) {
        if (format[index + 1] == specifier_arr[i].format_specifier) {
            (*specifier_arr[i].f)(list, nb_output_char);
        }
    }
}

int my_printf(const char *format, ...)
{
    int i;
    va_list list;
    int nb_output_char = 0;
    int size_str = my_strlen(format);

    va_start(list, format);
    for (i = 0; i < size_str; i++) {
        if ((format[i] == '%') && (format[i + 1] != '\0')) {
            compute(&nb_output_char, format, i, &list);
            i += 1;
            continue;
        }
        my_putchar(format[i]);
        nb_output_char++;
    }
    va_end(list);
    return nb_output_char;
}
