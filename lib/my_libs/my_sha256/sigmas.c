/*
** EPITECH PROJECT, 2025
** my_sha256
** File description:
** Hash words computation functions
*/

#include "../my_stdlib/my_stdlib.h"
#include "private.h"
#include <stdint.h>

// Right rotate 7
// Right rotate 18
// Right shift 3
// Bitwise sum of the 3
uint32_t sigma_zero(uint32_t word)
{
    uint32_t first = ROR_32(word, 7);
    uint32_t second = ROR_32(word, 18);
    uint32_t third = word >> 3;

    return (first ^ second) ^ third;
}

// Right rotate 17
// Right rotate 19
// Right shift 10
// Bitwise sum of the 3
uint32_t sigma_one(uint32_t word)
{
    uint32_t first = ROR_32(word, 17);
    uint32_t second = ROR_32(word, 19);
    uint32_t third = word >> 10;

    return first ^ second ^ third;
}

// Right rotate 2
// Right rotate 13
// Right rotate 22
// Bitwise sum of the 3
uint32_t cap_sigma_zero(uint32_t word)
{
    uint32_t first = ROR_32(word, 2);
    uint32_t second = ROR_32(word, 13);
    uint32_t third = ROR_32(word, 22);

    return first ^ second ^ third;
}

// Right rotate 6
// Right rotate 11
// Right rotate 25
// Bitwise sum of the 3
uint32_t cap_sigma_one(uint32_t word)
{
    uint32_t first = ROR_32(word, 6);
    uint32_t second = ROR_32(word, 11);
    uint32_t third = ROR_32(word, 25);

    return first ^ second ^ third;
}
