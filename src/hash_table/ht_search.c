/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-gael.laguna
** File description:
** ht_search
*/

#include "my_stdlib.h"
#include "hashtable.h"

static char *launch_query_lol(linked_list_t *hashed_element, int key)
{
    linked_list_t *temp = hashed_element;
    hashed_data_t *temp_data = MY_NULL;

    while (temp) {
        if (!temp->data)
            break;
        temp_data = ((hashed_data_t *)(temp->data));
        if (temp_data->key == key)
            return temp_data->value;
        temp = temp->next;
    }
    return MY_NULL;
}

char *ht_search(hashtable_t *ht, char *key)
{
    linked_list_t **hashtable = MY_NULL;
    int hashed_key = 0;
    char *result = MY_NULL;

    if (!ht || !key || !ht->hashtable)
        return MY_NULL;
    hashtable = ht->hashtable;
    hashed_key = hash(key, ht->size);
    result = launch_query_lol(hashtable[hashed_key % ht->size], hashed_key);
    return !result ? MY_NULL : result;
}
