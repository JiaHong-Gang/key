#include <stdio.h>
#include <openssl/sha.h>
#include <string.h>
void compute_hash(char *input, unsigned char *hash)
{
    SHA256((unsigned char *)input, strlen(input), hash);
}