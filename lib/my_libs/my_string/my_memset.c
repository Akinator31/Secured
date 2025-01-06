/*
** EPITECH PROJECT, 2024
** my_string
** File description:
** copies c into str
*/

#include "my_string.h"

// Seeing some issues with some strings not correctly initialized but...
// not my business
void *my_memset(void *str, int c, my_size_t n)
{
    char *ptr = (char *)str;

    for (my_size_t i = 0; i < n; i++)
        ptr[i] = (char)c;
    return str;
}
