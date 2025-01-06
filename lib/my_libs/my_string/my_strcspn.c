/*
** EPITECH PROJECT, 2024
** my_string
** File description:
** Returns the length of the longest sub string
** at the start not containing any of str2
*/

#include "my_string.h"

// Uses a jump table
my_size_t my_strcspn(const char *str1, const char *str2)
{
    char ascii_table[256] = {0};
    my_size_t len1 = my_strlen(str1);
    my_size_t len2 = my_strlen(str2);

    for (my_size_t i = 0; i < len2; i++)
        ascii_table[(int)str2[i]] = 1;
    for (my_size_t j = 0; j < len1; j++)
        if (ascii_table[(int)str1[j]] != 0)
            return j;
    return len1;
}
