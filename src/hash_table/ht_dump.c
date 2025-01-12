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

void print_data(linked_list_t *data_list, int index)
{
    linked_list_t *temp = data_list;
    hashed_data_t *data_element = MY_NULL;

    while (temp != MY_NULL) {
        data_element = ((hashed_data_t *)(temp->data));
        my_printf("> %d - %s\n", data_element->key, data_element->value);
        temp = temp->next;
    }
}

void ht_dump(hashtable_t *ht)
{
    hashed_data_t *hashed_data = MY_NULL;

    for (int i = 0; i < ht->size; i++) {
        hashed_data = ht->hashtable[i];
        if (ht->hashtable[i] != MY_NULL) {
            my_printf("[%d]:\n", i);
            print_data(ht->hashtable[i], i);
        } else {
            my_printf("[%d]:\n", i);
        }
    }
}
