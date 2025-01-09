/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-gael.laguna
** File description:
** hash
*/

#include <stddef.h>
#include "hashtable.h"
#include "my_stdlib.h"
#include "my_string.h"

// Take ascii of string, pair up two letters and transform into hexadecimal,
// fill with 0 if not even, cut in half the pairs,
// sum up all hexadecimals of each half,
// stripping the first (or last digit) each time so we keep it at 4 wide,
// multiply both halves result, do some bitshifting
//
// add a 0 if len is odd, for now we assume it's even
int hash(char *key, int len)
{
    return 0;
}
