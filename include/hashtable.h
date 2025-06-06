/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H
    #include <stdbool.h>
    #include "my_list.h"

typedef struct hashed_data_s {
    int key;
    char *value;
} hashed_data_t;

typedef struct hashtable_s {
    int size;
    linked_list_t **hashtable;
    int (*hash_function)(char *, int);
} hashtable_t;

// Hash function
int hash(char *key, int len);

// Create & destroy table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);
bool is_hashtable_empty(hashtable_t *ht);
int free_hashdata(void *hashdata);

#endif /* HASHTABLE_H */
