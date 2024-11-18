#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
void save_password(unsigned char *hash)
{
    const char *filename = "save_password.txt";
    FILE *file;
    file = fopen(filename,"w");
    if (file == NULL)
    {
        printf("Error!No such file\n");
        exit(0);
    }
    else
    {
        fwrite(hash,1,SHA256_DIGEST_LENGTH,file);
    }
    fclose(file);
}


