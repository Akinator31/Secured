/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-gael.laguna
** File description:
** delete_hashtable
*/

#include <stdlib.h>
#include "hashtable.h"

void delete_hashtable(hashtable_t *ht)
{
    if (!ht)
        return;
    for (int i = 0; i < ht->size; ++i)
        ht->hashtable[i] = clear_list_and_data(ht->hashtable[i], &free_hashdata);
    free(ht->hashtable);
    free(ht);
}
