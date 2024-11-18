#include <stdio.h>
#include <stdlib.h>
#include <openssl/sha.h>
#include <string.h>
void load_password(unsigned char *hash1)
{
    
    size_t readbytes;
    FILE *file = fopen("save_password.txt","rb");
    if(file == NULL)
    {
        printf("Error!Can not read file\n");
        exit(0);
    }
    else
    {
    readbytes = fread(hash1, 1, SHA256_DIGEST_LENGTH,file);
    if (readbytes != SHA256_DIGEST_LENGTH)
    {
        printf("Error! Can not read the complete hash from file\n");
        fclose(file);
        exit(0);
    }
    fclose(file);
    }
}