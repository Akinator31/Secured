/*
** EPITECH PROJECT, 2025
** secured
** File description:
** Main test file
*/

#include "hashtable.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *random_string(int seed)
{
    FILE *file = fopen("/dev/urandom", "r");
    char *random_str = malloc(sizeof(char) * (25 % seed) + 1);

    fseek(file, seed << 1, SEEK_SET);
    fread(random_str, 25 % seed, 1, file);
    random_str[25 % seed] = 0;
    fclose(file);
    return random_str;
}

int main(int argc, char **argv)
{
    hashtable_t *ht = new_hashtable(hash, 5120);
    char *random_key = NULL;

    for (int i = 1; i < 100000; i++) {
        random_key = random_string(i);
        ht_insert(ht, random_key, "abc");
        free(random_key);
    }
    ht_dump(ht);
    delete_hashtable(ht);
}