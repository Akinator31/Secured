/*
** EPITECH PROJECT, 2025
** my_string
** File description:
** returns an array of pointers to words
** (delimiters are all non-printable + punct + operators)
** Modifies the original string by changing delimiters by 0s
** (non-standard)
*/

#include <stdlib.h>
#include "my_string.h"
#include "../my_stdlib/my_stdlib.h"

const char *delimiters = " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

// Returns a null-terminated allocated array of pointers to words
// A word is an alphanumerical suite of characters
// Modifies the original string
char **my_str_to_word_array(char *str)
{
    char **array = malloc(sizeof(char *));
    char *words = my_strtok(str, delimiters);
    my_size_t i = 0;

    for (; words; i++) {
        array[i] = words;
        words = my_strtok(MY_NULL, delimiters);
        array = my_reallocarray(array, i + 2, sizeof(char *));
    }
    array[i] = MY_NULL;
    return array;
}
