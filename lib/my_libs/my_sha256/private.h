/*
** EPITECH PROJECT, 2025
** my_sha256
** File description:
** Constant variables for a sha-256 hashing
*/

#include <stdint.h>

#ifndef MY_SHA256_PRIVATE_H_
    #define MY_SHA256_PRIVATE_H_

    // Some bitwise chaos
    #define CH(x, y, z) ((x & y) ^ (~x & z))
    #define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))

uint32_t sigma_zero(uint32_t word);
uint32_t sigma_one(uint32_t word);
uint32_t cap_sigma_zero(uint32_t word);
uint32_t cap_sigma_one(uint32_t word);

#endif /* MY_SHA256_PRIVATE_H_ */
