/*
** EPITECH PROJECT, 2024
** my_string
** File description:
** Compare two blocks of memory
*/

#include "my_string.h"

int my_memcmp(const void *str1, const void *str2, my_size_t n)
{
    while (n > 0 &&
        ((unsigned char *)str1)[n - 1] == ((unsigned char *)str2)[n - 1])
        n--;
    if (n == 0)
        return 0;
    if (((unsigned char *)str1)[n] > ((unsigned char *)str2)[n])
        return 1;
    return -1;
}
