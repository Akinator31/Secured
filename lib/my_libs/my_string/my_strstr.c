/*
** EPITECH PROJECT, 2024
** my_string
** File description:
** Returns the position of needle in haystack if any is found
** Uses the Boyer-Moore-Horspool algorithm
** https://en.wikipedia.org/wiki/Boyer-Moore-Horspool_algorithm
*/

#include "my_string.h"

char *my_strstr(const char *haystack, const char *needle)
{
    my_size_t pattern_len = my_strlen(needle);
    my_size_t haystack_len = my_strlen(haystack);
    my_size_t skip_table[256] = {0};
    my_size_t skip = 0;

    if (my_memcmp(needle, "", 1) == 0)
        return (char *)haystack;
    for (my_size_t j = 0; j < 255; j++)
        skip_table[j] = pattern_len;
    for (my_size_t i = 0; i < pattern_len - 1; i++)
        skip_table[(int)needle[i]] = pattern_len - 1 - i;
    while (haystack_len - skip >= pattern_len) {
        if (my_memcmp(&haystack[skip], needle, pattern_len) == 0)
            return (char *)&haystack[skip];
        skip += skip_table[(int)haystack[skip + pattern_len - 1]];
    }
    return MY_NULL;
}
