/*
** EPITECH PROJECT, 2025
** my_string
** File description:
** returns the amount of occurences of c in str
*/

#include "my_string.h"

my_size_t my_strcnb(char *str, int c)
{
    my_size_t count = 0;

    for (my_size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            count++;
    }
    return count;
}
