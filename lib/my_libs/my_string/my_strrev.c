/*
** EPITECH PROJECT, 2025
** my_string
** File description:
** reverse a string, this is a non standard function
*/

#include "my_string.h"

char *my_strrev(char *str)
{
    my_size_t len = my_strlen(str) - 1;
    char tmp = 0;

    for (my_size_t i = 0; i < len; i++) {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
        len--;
    }
    return str;
}
