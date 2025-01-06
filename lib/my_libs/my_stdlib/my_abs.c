/*
** EPITECH PROJECT, 2024
** my_stdlib
** File description:
** my_abs
*/

#include "my_stdlib.h"

int my_abs(int x)
{
    if (x < 0)
        return x * -1;
    return x;
}
