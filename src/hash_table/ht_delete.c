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

bool try_deleting_field(linked_list_t *hashdata, int key)
{
    linked_list_t *temp = hashdata;
    hashed_data_t *temp_data = MY_NULL;

    if (key < 0)
        key = -key;
    while (temp) {
        temp_data = ((hashed_data_t *)(temp->data));
        if (temp_data->key == key) {
            my_free(temp_data);
            temp = delete_node(&hashdata, temp);
            return true;
        }
        temp = temp->next;
    }
    return false;
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
        if (try_deleting_field(hashtable[i], hashkey))
            return 0;
    }
    write(2, "Key not found !\n", 17);
    return 84;
}
