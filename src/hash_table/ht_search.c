/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-gael.laguna
** File description:
** ht_search
*/

#include "my_stdlib.h"
#include "hashtable.h"

char *launch_query(linked_list_t *hashed_element, int key)
{
    linked_list_t *temp = hashed_element;
    hashed_data_t *temp_data = MY_NULL;

    while (temp != MY_NULL) {
        temp_data = ((hashed_data_t *)(temp->data));
        if (temp_data->key == key)
            return temp_data->value;
        temp = temp->next;
    }
    return MY_NULL;
}

char *ht_search(hashtable_t *ht, char *key)
{
    linked_list_t **hashtable = ht->hashtable;
    int hashed_key = hash(key, ht->size);
    char *result = MY_NULL;

    if (hashed_key < 0)
        hashed_key *= -1;
    for (int i = 0; i <= ht->size; i++) {
        result = launch_query(hashtable[i], hashed_key);
        if (result != MY_NULL)
            return result;
    }
    return MY_NULL;
}
