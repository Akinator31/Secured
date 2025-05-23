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

// The following nonull attributes  are non standard as of C11
// Moreover, the banana coding style checker has undefined behaviour with them
// Will need to find some alternative, but it's just a minor issue as of now
void *my_memccpy(void *dest, const void *src, int c, my_size_t n)
__attribute__((nonnull(1, 2)));
void *my_memchr(const void *mem, int c, my_size_t n)
__attribute__((nonnull(1)));
int my_memcmp(const void *str1, const void *str2, my_size_t n)
__attribute__((nonnull(1, 2)));
void *my_memcpy(void *dest, const void *src, my_size_t)
__attribute__((nonnull(1, 2)));
void *my_memrcpy(void *dest, const void *src, my_size_t n)
__attribute__((nonnull(1, 2)));
void *my_memmove(void *dest, const void *src, my_size_t)
__attribute__((nonnull(1, 2)));
void *my_memset(void *str, int c, my_size_t n)
__attribute__((nonnull(1)));
char *my_c_to_bin(char c);
char *my_str_to_bin(const char *str, my_size_t len)
__attribute__((nonnull(1)));
char **my_str_to_word_array(char *str)
__attribute__((nonnull(1)));
char *my_strcat(char *dest, const char *src)
__attribute__((nonnull(1, 2)));
char *my_strncat(char *dest, const char *src, my_size_t n)
__attribute__((nonnull(1, 2)));
char *my_strchr(const char *str, int c)
__attribute__((nonnull(1)));
int my_strcmp(const char *str1, const char *str2)
__attribute__((nonnull(1, 2)));
int my_strncmp(const char *str1, const char *str2, my_size_t n)
__attribute__((nonnull(1, 2)));
my_size_t my_strcnb(char *str, int c)
__attribute__((nonnull(1)));
int my_strcoll(const char *str1, const char *str2)
__attribute__((nonnull(1, 2)));
char *my_strcpy(char *dest, const char *src)
__attribute__((nonnull(1, 2)));
char *my_strncpy(char *dest, const char *src, my_size_t n)
__attribute__((nonnull(1, 2)));
my_size_t my_strcspn(const char *str1, const char *str2)
__attribute__((nonnull(1, 2)));
char *my_strdup(const char *str)
__attribute__((nonnull(1)));
char *my_strerror(int errnum);
my_size_t my_strlen(const char *str)
__attribute__((nonnull(1)));
char *my_strrev(char *str)
__attribute__((nonnull(1)));
char *my_strpbrk(const char *str1, const char *str2)
__attribute__((nonnull(1, 2)));
char *my_strrchr(const char *str, int c)
__attribute__((nonnull(1)));
my_size_t my_strspn(const char *str1, const char *str2)
__attribute__((nonnull(1, 2)));
char *my_strstr(const char *haystack, const char *needle)
__attribute__((nonnull(1, 2)));
char *my_strtok(char *str, const char *delim)
__attribute__((nonnull(2)));
my_size_t my_strxfrm(char *dest, const char *src, my_size_t n)
__attribute__((nonnull(1, 2)));
char *my_strdup(const char *str);

#endif /* MY_STRING_H_ */
