/*
** EPITECH PROJECT, 2024
** my_string
** File description:
** compares str1 and str2
*/

#include "my_string.h"

int my_strcmp(char const *str1, char const *str2)
{
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
    if (my_strlen(str1) > my_strlen(str2))
        return str1[my_strlen(str2)];
    if (my_strlen(str1) < my_strlen(str2))
        return - str2[my_strlen(str1)];
    return 0;
}
