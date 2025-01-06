/*
** EPITECH PROJECT, 2024
** my_string
** File description:
** compares str1 and str2 until n
*/

#include "my_string.h"

int my_strncmp(char const *str1, char const *str2, my_size_t n)
{
    for (my_size_t i = 0; str1[i] != '\0' && str2[i] != '\0' && i < n; i++)
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
    return 0;
}
