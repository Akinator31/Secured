/*
** EPITECH PROJECT, 2025
** secured
** File description:
** Main test file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/hashtable.h"
#include "my_string.h"
#include "my_printf.h"
#include "my_list.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

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

Test(is_hashtable_empty, empty_hashtable_empty_test)
{
    hashtable_t *ht = NULL;
    cr_assert_eq(is_hashtable_empty(ht), 1);
}

Test(is_hashtable_empty, empty_hashtable_no_empty_test)
{
    hashtable_t *ht = new_hashtable(&hash, 8);

    ht_insert(ht, "key", "value");
    ht_delete(ht, "key");
    cr_assert_eq(is_hashtable_empty(ht), 1);
    delete_hashtable(ht);
}

Test(is_hashtable_empty, empty_hashtable_full)
{
    hashtable_t *ht = new_hashtable(&hash, 8);

    ht_insert(ht, "key", "value");
    cr_assert_eq(is_hashtable_empty(ht), 0);
    delete_hashtable(ht);
}

Test(new_hashtable, null_size)
{
    hashtable_t *ht = new_hashtable(&hash, 0);

    cr_assert_null(ht);
}

Test(ht_search, search_with_null_hashtable)
{
    hashtable_t *ht = NULL;

    cr_assert_null(ht_search(ht, "key"));
}

Test(ht_search, search_test_normal)
{
    hashtable_t *ht = new_hashtable(&hash, 6);

    ht_insert(ht, "quzifuizehgfuizs", "value");
    cr_assert_not_null(ht_search(ht, "quzifuizehgfuizs"));
    delete_hashtable(ht);
}

Test(ht_insert, insert_in_null_hashtable)
{
    cr_assert_eq(ht_insert(NULL, "key", "value"), 84);
}

Test(ht_insert, collision_test)
{
    hashtable_t *ht = new_hashtable(&hash, 3);

    ht_insert(ht, "uiheguihziughiu", "value");
    ht_insert(ht, "uihegujhziughiu", "value");
    cr_assert_neq(ht_insert(ht, "uihegujhziughiu", "value"), 84);
    delete_hashtable(ht);
}

Test(ht_dump, try_display_null_hashtable, .init = redirect_all_std)
{
    ht_dump(NULL);
    cr_assert_stdout_eq_str("");
}

Test(ht_dump, try_display_not_null_hashtable, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 3);

    ht_insert(ht, "uiheguihziughiu", "value");
    ht_dump(ht);
    cr_assert_stdout_eq_str("[0]:\n> 2110624758 - value\n[1]:\n[2]:\n");
    delete_hashtable(ht);
}

Test(ht_delete, try_deleting_with_null_hashtable)
{
    cr_assert_eq(ht_delete(NULL, "key"), 84);
}

Test(delete_hashtable, try_delete_null_hashtable, .init = redirect_all_std)
{
    delete_hashtable(NULL);
    cr_assert_stdout_eq_str("");
}

Test(my_strlen, classic_strlen_test)
{
    char *str = "Cette string est un vrai test.";
    int test = my_strlen(str);

    cr_assert_eq(strlen(str), my_strlen(str));
}

Test(my_put_number, classic_put_nbr_test, .init = redirect_all_std)
{
    my_put_nbr(-2147483648);
    my_put_nbr(-1);
    cr_assert_stdout_eq_str("-2147483648-1");
}

Test(my_printf, test_print_char, .init=redirect_all_std)
{
    my_printf("%c", 'c');
    cr_assert_stdout_eq_str("c");
}

Test(my_printf, test_print_percent, .init = redirect_all_std)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(new_list, create_linked_list)
{
    cr_assert_null(new_list());
}

Test(clear_list, clear_classic_linked_list)
{
    int test = 9;
    linked_list_t *list = NULL;

    list = push_front_list_all(list, 1, &test);
    list = clear_list(list);
    cr_assert_null(list);
}

Test(get_linked_list_len, len_linked_list)
{
    int test = 0;
    linked_list_t *list = NULL;

    list = push_front_list(list, &test);
    cr_assert_eq(get_linked_list_len(list), 1);
    list = clear_list(list);
}

Test(pop_front_list, pop_front_list_test)
{
    int test = 0;
    int test2 = 8;
    linked_list_t *list = NULL;
    linked_list_t *temp = NULL;

    list = push_front_list(list, &test);
    temp = pop_front_list(list, &free);
    cr_assert_null(temp);
}

Test(pop_front_list, test_with_null_linked_list)
{
    cr_assert_null(pop_front_list(NULL, &free));
}

Test(delete_node, test_delete_node)
{
    int test = 0;
    int test2 = 1;
    int test3 = 2;
    int test4 = 3;
    int test5 = 4;
    int test6 = 5;
    linked_list_t *list = NULL;

    list = push_front_list(list, &test);
    list = push_front_list(list, &test2);
    list = push_front_list(list, &test3);
    list = push_front_list(list, &test4);
    list = push_front_list(list, &test5);
    list = push_front_list(list, &test6);

    list = delete_node(&list, list->next->next->next);
    cr_assert_eq(get_linked_list_len(list), 5);
    cr_assert_null(delete_node(&list, NULL));
    list = clear_list(list);
}

Test(push_front_list, test_with_null_data)
{
    linked_list_t *list = NULL;

    cr_assert_null(push_front_list(list, NULL));
}

Test(push_back_list, push_back_list_test)
{
    int test = 0;
    int test2 = 8;
    linked_list_t *list = NULL;
    linked_list_t *temp = NULL;

    list = push_back_list(list, &test);
    list = push_back_list(list, &test2);
    cr_assert_eq(get_linked_list_len(list), 2);
    list = clear_list(list);
}

Test(push_back_list_all, test_push_back_list)
{
    linked_list_t *list = NULL;
    int test = 0;
    int test2 = 2;
    int test3 = 8;

    list = push_back_list_all(list, 3, &test, &test2, &test3);
    cr_assert_eq(get_linked_list_len(list), 3);
    list = clear_list(list);
}

Test(my_rev_list, linked_list_reverse)
{
    linked_list_t *list = new_list();
    linked_list_t *temp = NULL;
    int data = 42;
    int data1 = 45;
    int result = 0;

    list = push_back_list(list, &data);
    list = push_back_list(list, &data1);
    my_rev_list(&list);
    temp = list;

    while (temp != NULL) {
        result = *(int *)temp->data;
        temp = temp->next;
    }
    cr_assert_eq(result, 42);
    list = clear_list(list);
}

Test(pop_front_list, test_pop_from_linked_list)
{
    linked_list_t *list = new_list();
    linked_list_t *temp = NULL;
    int *data = (int *)malloc(sizeof(int));
    int *data1 = (int *)malloc(sizeof(int));
    int result = 0;

    *data = 84;
    *data1 = 42;
    list = push_front_list(list, data);
    list = push_back_list(list, data1);
    list = pop_front_list(list, free);
    temp = list;
    while (temp != NULL) {
        result = *(int *)temp->data;
        temp = temp->next;
    }
    cr_assert_eq(result, 42);
    free(data);
    free(data1);
    list = clear_list(list);
}

Test(delete_node, test_deleting_node_with_null_linked_list)
{
    linked_list_t *list = NULL;
    linked_list_t **list2 = NULL;

    cr_assert_null(delete_node(&list, NULL));
    cr_assert_null(delete_node(list2, NULL));
}
