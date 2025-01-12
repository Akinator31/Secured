/*
** EPITECH PROJECT, 2024
** my_string
** File description:
** copy from src to dest starting from the end until n is reached
** memory reverse copy
*/

#include "my_string.h"

// optimize by copying larger chunks when possible + align
void *my_memrcpy(void *dest, const void *src, my_size_t n)
{
    for (my_size_t i = 0; i < n; i++)
        ((unsigned char *)dest)[n - i - 1] = ((unsigned char *)src)[i];
    return dest;
}
