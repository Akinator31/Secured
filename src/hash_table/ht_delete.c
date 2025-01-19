/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-gael.laguna
** File description:
** hashtable
*/

#include <stdbool.h>
#include <unistd.h>
#include "my_stdlib.h"
#include "hashtable.h"

static linked_list_t *try_deleting_field(linked_list_t *hashdata,
    int key)
{
    linked_list_t *temp = hashdata;
    hashed_data_t *temp_data = MY_NULL;

    if (key < 0)
        key = -key;
    while (temp) {
        temp_data = ((hashed_data_t *)(temp->data));
        if (temp_data->key == key) {
            my_free(temp_data);
            hashdata = delete_node(&hashdata, temp);
            return hashdata;
        }
        temp = temp->next;
    }
    return hashdata;
}

int ht_delete(hashtable_t *ht, char *key)
{
    linked_list_t **hashtable = MY_NULL;
    int hashkey = 0;

    if (!ht)
        return 84;
    hashtable = ht->hashtable;
    hashkey = hash(key, ht->size);
    for (int i = 0; i <= ht->size; ++i) {
        hashtable[i] = try_deleting_field(hashtable[i], hashkey);
    }
    return 84;
}
