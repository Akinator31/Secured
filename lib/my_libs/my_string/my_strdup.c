/*
** EPITECH PROJECT, 2025
** my_string
** File description:
** my_strdup (non-standard)
*/

#include "my_string.h"
#include <stdlib.h>

char *my_strdup(const char *str)
{
    my_size_t len = my_strlen(str);
    char *duplicata = malloc(len);

    my_memcpy(duplicata, str, len);
    return duplicata;
}
