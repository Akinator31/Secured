/*
** EPITECH PROJECT, 2025
** secured
** File description:
** Main test file
*/

#include <criterion/criterion.h>
#include "../include/hashtable.h"

Test(basic, delete_one_value)
{
    hashtable_t *ht = new_hashtable(&hash, 2);
    ht_insert(ht, "key", "value");
    ht_delete(ht, "key");
    delete_hashtable(ht);
}

Test(basic, delete_non_present_value)
{
    hashtable_t *ht = new_hashtable(&hash, 2);
    ht_insert(ht, "key", "value");
    ht_delete(ht, "whatever");
    delete_hashtable(ht);
}

Test(basic, search_one_value)
{
    hashtable_t *ht = new_hashtable(&hash, 12);
    char *a = NULL;

    ht_insert(ht, "key", "value");
    a = ht_search(ht, "key");
    delete_hashtable(ht);
    cr_assert_str_eq(a, "value");
}

Test(basic, search_non_present_value)
{

    hashtable_t *ht = new_hashtable(&hash, 12);
    char *a = NULL;

    ht_insert(ht, "key", "value");
    a = ht_search(ht, "whatever");
    delete_hashtable(ht);
    cr_assert_null(a);
}
