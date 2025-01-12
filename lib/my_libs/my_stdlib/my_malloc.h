/*
** EPITECH PROJECT, 2025
** my_malloc
** File description:
** Header for my_malloc
*/

#ifndef MY_BOOL_H_
    #define MY_BOOL_H_

    #define BOOL long
    #define TRUE 1
    #define FALSE 0

#endif /* MY_BOOL_H_ */

#ifndef MY_NULL_H_
    #define MY_NULL_H_

    #define MY_NULL ((void *)0)

#endif /* MY_NULL_H_ */

#ifndef MY_SIZE_T_H_
    #define MY_SIZE_T_H_

typedef unsigned long my_size_t;

#endif /* MY_SIZE_T_H_ */

#ifndef MY_MALLOC_H_
    #define MY_MALLOC_H_

    #define MEMORY_AMOUNT 1000000
    #define CHUNKS_AMOUNT 1000000

// Index is the memory adress
// Size is the amount of bytes allocated
typedef struct mem_chunk_s {
    my_size_t index;
    my_size_t size;
    BOOL free;
} mem_chunk_t;

void my_malloc_init(void)
__attribute__((constructor));
my_size_t get_chunk_size(void *ptr);

#endif /* MY_MALLOC_H_ */
