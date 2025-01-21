/*
** EPITECH PROJECT, 2024
** my_string
** File description:
** my_string header
*/

#ifndef MY_NULL_H_
    #define MY_NULL_H_

    #define MY_NULL ((void *)0)

#endif /* MY_NULL_H_ */

#ifndef MY_SIZE_T_H_
    #define MY_SIZE_T_H_

typedef unsigned long my_size_t;

#endif /* MY_SIZE_T_H_ */

#ifndef MY_STRING_H_
    #define MY_STRING_H_

void *my_memcpy(void *dest, const void *src, my_size_t)
__attribute__((nonnull(1, 2)));
void *my_memrcpy(void *dest, const void *src, my_size_t n)
__attribute__((nonnull(1, 2)));
void *my_memset(void *str, int c, my_size_t n)
__attribute__((nonnull(1)));
my_size_t my_strlen(const char *str)
__attribute__((nonnull(1)));

#endif /* MY_STRING_H_ */
