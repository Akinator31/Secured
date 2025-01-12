/*
** EPITECH PROJECT, 2025
** my_stdlib
** File description:
** long to str
** (non-standard)
*/

#include "my_stdlib.h"
#include "../my_string/my_string.h"
#include "private.h"

char *my_ltoa(long value, char *str, int base)
{
    int index = 0;
    int negative = 0;

    if (value < 0) {
        negative = 1;
        value = value * -1;
    }
    if (value == 0) {
        str[index] = '0';
        str[index + 1] = '\0';
        return str;
    }
    while (value > 0) {
        str[index] = BASE_TABLE[value % base];
        value /= base;
        index++;
    }
    if (negative)
        str[index] = '-';
    return my_strrev(str);
}
