/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-gael.laguna
** File description:
** hash
*/

#include <stdlib.h>
#include <stdint.h>
#include "hashtable.h"
#include "my_string.h"
#include "my_sha256.h"

// The actual hash function is my_hash in lib/my_libs/my_sha256/
// Using the sha256 secure hash function, we retrieve 256 bits of data,
// However we only want an int (32 bits), so we only return 1/8 of the data.
int hash(char *key, int len)
{
    uint32_t digested_data = 0;
    char *digested_message = my_hash_lol(key);

    my_memrcpy(&digested_data, &digested_message[(len % 8) << 2], 4);
    free(digested_message);
    return (int)digested_data;
}
