/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** task02
*/

#include "my_printf.h"

int my_putstr(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return i;
}
