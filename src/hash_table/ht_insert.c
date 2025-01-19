/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-gael.laguna
** File description:
** ht_insert
*/

#include <stdbool.h>
#include <stdlib.h>
#include "hashtable.h"

static bool hashkey_already_exist(linked_list_t *hashtable,
    const int hashkey, char *value)
{
    linked_list_t *temp = hashtable;
    hashed_data_t *temp_data = NULL;

    while (temp) {
        temp_data = ((hashed_data_t *)(temp->data));
        if (temp_data->key == hashkey) {
            temp_data->value = value;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    hashed_data_t *data = NULL;
    int hashed_key = 0;
    int index = 0;

    if (!ht)
        return 84;
    hashed_key = ht->hash_function(key, ht->size);
    if (hashed_key < 0)
        hashed_key = -hashed_key;
    index = hashed_key % (ht->size + 1);
    if ((index < ht->size) && !hashkey_already_exist(
            ht->hashtable[index], hashed_key, value)) {
        data = (hashed_data_t *)malloc(sizeof(hashed_data_t));
        data->key = hashed_key;
        data->value = value;
        ht->hashtable[index] = push_front_list(ht->hashtable[index], data);
    }
    return 0;
}
