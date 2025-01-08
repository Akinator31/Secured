/*
** EPITECH PROJECT, 2024
** my_stdlib
** File description:
** reallocate the desired memory size
*/

#include "my_stdlib.h"
#include "../my_string/my_string.h"

// This just copies memory into a larger (or smaller) block
// This is *not* what realloc does
void *my_realloc(void *ptr, my_size_t size)
{
    void *new_ptr = my_malloc(size);

    my_memcpy(new_ptr, ptr, size);
    my_free(ptr);
    return new_ptr;
}
