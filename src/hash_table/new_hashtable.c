/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-gael.laguna
** File description:
** new_hashtable
*/

#include "hashtable.h"
#include <stdlib.h>

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *hashtable = NULL;

    if (len <= 0)
        return NULL;
    hashtable = (hashtable_t *)malloc(sizeof(hashtable_t));
    hashtable->hashtable =
        (linked_list_t **)malloc(sizeof(linked_list_t *) * (len + 1));
    hashtable->size = len;
    hashtable->hash_function = hash;
    for (int i = 0; i <= len; i++)
        hashtable->hashtable[i] = NULL;
    return hashtable;
}
