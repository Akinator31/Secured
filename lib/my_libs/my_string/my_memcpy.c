/*
** EPITECH PROJECT, 2024
** my_string
** File description:
** copy from src to dest until n is reached
*/

#include "my_string.h"

void *my_memcpy(void *dest, const void *src, my_size_t n)
{
    for (my_size_t i = 0; i < n; i++)
        ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
    return dest;
}
