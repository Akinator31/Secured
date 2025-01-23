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
    int key, int *founded)
{
    linked_list_t *temp = hashdata;
    hashed_data_t *temp_data = MY_NULL;

    while (temp) {
        temp_data = ((hashed_data_t *)(temp->data));
        if (temp_data->key == key) {
            free_hashdata(temp_data);
            *founded = 1;
            return delete_node(&hashdata, temp);
        }
        temp = temp->next;
    }
    return hashdata;
}

int ht_delete(hashtable_t *ht, char *key)
{
    linked_list_t **hashtable = MY_NULL;
    int founded = 0;
    int hashkey = 0;

    if (!ht || !key)
        return 84;
    hashtable = ht->hashtable;
    hashkey = hash(key, ht->size);
    for (int i = 0; i < ht->size; ++i)
        hashtable[i] = try_deleting_field(hashtable[i], hashkey, &founded);
    if (!founded)
        return 84;
    return 0;
}
