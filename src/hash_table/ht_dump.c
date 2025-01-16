/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-gael.laguna
** File description:
** ht_dump
*/

#include "stdio.h"
#include "my_stdlib.h"
#include "hashtable.h"
#include "my_printf.h"

static void print_data(const linked_list_t *data_list)
{
    linked_list_t *temp = data_list;
    hashed_data_t *data_element = MY_NULL;

    while (temp) {
        data_element = ((hashed_data_t *)(temp->data));
        my_printf("> %d - %s\n", data_element->key, data_element->value);
        temp = temp->next;
    }
}

void ht_dump(hashtable_t *ht)
{
    if (!ht)
        return;
    for (int i = 0; i < ht->size; ++i) {
        if (ht->hashtable[i]) {
            my_printf("[%d]:\n", i);
            print_data(ht->hashtable[i]);
        } else
            my_printf("[%d]:\n", i);
    }
}
