/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-gael.laguna
** File description:
** check_empty_hashtable
*/

#include <stdbool.h>
#include "hashtable.h"

bool is_hashtable_empty(hashtable_t *ht)
{
    linked_list_t **hashtable = ht->hashtable;

    for (int i = 0; i <= ht->size; i++) {
        if (hashtable[i])
            return false;
    }
    return true;
}
