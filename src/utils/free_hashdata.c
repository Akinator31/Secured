/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-gael.laguna
** File description:
** free_hashdata
*/

#include <stdlib.h>
#include "hashtable.h"
#include "my_list.h"

int free_hashdata(void *hashdata)
{
    hashed_data_t *data = hashdata;

    if (!hashdata)
        return 84;
    free(data->value);
    free(data);
    return 0;
}
