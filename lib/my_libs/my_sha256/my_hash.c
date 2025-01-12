/*
** EPITECH PROJECT, 2025
** my_sha256
** File description:
**                 Hash function following the SHA256 protocol
** |--------------------------------------------------------------------------|
** |       All constants and computations come from the following paper:      |
** |        https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf        |
** |--------------------------------------------------------------------------|
** |        Thanks to RedBlockBlue for his amazing video on the topic:        |
** |             https://youtu.be/orIgy2MjqrA?si=g925nXD9982slYoP             |
** |--------------------------------------------------------------------------|
** |                  Check out in3rsha's SHA-256 Animation:                  |
** |                https://github.com/in3rsha/sha256-animation               |
** |--------------------------------------------------------------------------|
*/

#include "../my_string/my_string.h"
#include "../my_stdlib/my_stdlib.h"
#include "my_sha256.h"
#include "private.h"
#include <stdint.h>

// First 32 bits of the fractional parts
// of the cube roots of the first 64 prime numbers
const uint32_t sha256_constants[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

// First 32 bits of the fractional parts
// of the square roots of the first 8 prime numbers
// Added U just in case
static uint32_t h_vars[8];

static void fill_h_vars(void)
{
    h_vars[0] = 0x6a09e667U;
    h_vars[1] = 0xbb67ae85U;
    h_vars[2] = 0x3c6ef372U;
    h_vars[3] = 0xa54ff53aU;
    h_vars[4] = 0x510e527fU;
    h_vars[5] = 0x9b05688cU;
    h_vars[6] = 0x1f83d9abU;
    h_vars[7] = 0x5be0cd19U;
}

// Make a mem block multiple of 512, the 64 last bits are for the str len
// Add key_len as binary to the end of the memory block
//
// Last loop explanation:
// 0xFF is 000000000 111111111 (255), with & (AND), only copies the last 8 bits
// Basically using a 255 mask
// Bitshifting to copy byte per byte into the memory block
static my_size_t prepare_bits(const char *key, char **padded_key)
{
    my_size_t key_len = my_strlen(key);
    char *padded = my_malloc(key_len + 64 - (key_len % 64));
    my_size_t to_pad = 64 - (key_len % 64) - 8;
    uint64_t bits_nb = key_len << 3;

    my_memcpy(padded, key, key_len);
    padded[key_len] = -128;
    my_memset(&padded[key_len + 1], 0, to_pad - 1);
    for (my_size_t i = 0; i < 8; i++)
        padded[key_len + to_pad + i] =
            (char)(bits_nb >> (56 - (i << 3))) & 0xFF;
    *padded_key = padded;
    return (key_len + to_pad + 8) >> 6;
}

static void compute_working_vars(uint32_t vars[8], uint32_t words[64])
{
    uint32_t t1 = 0;
    uint32_t t2 = 0;

    for (int t = 0; t < 64; t++) {
        t1 = vars[7] + cap_sigma_one(vars[4]) + CH(vars[4], vars[5], vars[6])
            + sha256_constants[t] + words[t];
        t2 = cap_sigma_zero(vars[0]) + MAJ(vars[0], vars[1], vars[2]);
        vars[7] = vars[6];
        vars[6] = vars[5];
        vars[5] = vars[4];
        vars[4] = vars[3] + t1;
        vars[3] = vars[2];
        vars[2] = vars[1];
        vars[1] = vars[0];
        vars[0] = t1 + t2;
    }
}

// Create 64 different "words" of 32 bits each
// The 16 first are just the hash we already have
// The next 48 words are found with the next equation:
// Wt = SIGMA1(Wt-2) + Wt-7 + SIGMA0(Wt-15) + Wt-16
//
// working variables
// a, b, c, d, e, f, g, h
// 0  1  2  3  4  5  6  7
static void hash_computation(char hash[64])
{
    uint32_t words[64] = {0};
    uint32_t vars[8] = {h_vars[0], h_vars[1], h_vars[2], h_vars[3],
        h_vars[4], h_vars[5], h_vars[6], h_vars[7]};

    for (int i = 0; i < 16; i++)
        my_memrcpy(&words[i], &hash[i << 2], 4);
    for (int i = 16; i < 64; i++)
        words[i] = sigma_one(words[i - 2]) + words[i - 7]
            + sigma_zero(words[i - 15]) + words[i - 16];
    compute_working_vars(vars, words);
    for (int i = 0; i < 8; i++)
        h_vars[i] += vars[i];
}

// Start by padding the initial key then compute it by blocks of 512
char *my_hash(const char *key)
{
    char hash[64] = {0};
    char *padded_key = MY_NULL;
    char *hashed_key = my_malloc(32);
    my_size_t blocks = prepare_bits(key, &padded_key);

    fill_h_vars();
    for (my_size_t i = 0; i < blocks; i++) {
        my_memcpy(hash, &padded_key[i << 6], 64);
        hash_computation(hash);
    }
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 4; j++)
            hashed_key[(i << 2) + j] =
                (char)(h_vars[i] >> (24 - (j << 3))) & 0xFF;
    my_free(padded_key);
    return hashed_key;
}

// Use example since I know I'll forget
// int main(void)
// {
//     uint32_t tmp = 0;
//     char *a = MY_NULL;i

//     a = my_hash("The quick brown fox keeps jumping "
//         "over my hash table. This is quite annoying");
//     for (int i = 0; i < 8; i++) {
//         my_memrcpy(&tmp, &a[i * 4], 4);
//         my_printf("%x", tmp);
//     }
//     my_free(a);
// }
