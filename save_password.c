#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include "config.h"
void save_password(const char *filename, unsigned char *hash)
{
    FILE *file;
    file = fopen(PASSWORD_FILE_INFO,"a");     //Open the file and write new information
    if (file == NULL)
    {
        printf("Error!No such file\n");
        exit(0);
    }
    else
    {
        fwrite(hash,1,SHA256_DIGEST_LENGTH,file);   // Write the hash into the file
        fprintf(file,"%s\n",filename);      //Write the file path into the file
        fclose(file);       //Close the file
    }
}


