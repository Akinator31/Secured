/*
** EPITECH PROJECT, 2024
** my_stdlib
** File description:
** my_div
*/

#include "my_stdlib.h"

my_div_t my_div(int numer, int denom)
{
    return (my_div_t){numer / denom, numer % denom};
}
