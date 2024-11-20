#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <string.h>
#include "config.h"
void load_password(const char *filename, unsigned char *saved_hash)
{
    
    size_t readbytes;
    char saved_filename[256];
    int found = 0;
    FILE *file = fopen(PASSWORD_FILE_INFO,"r");     //Open the file and read the saved information
    if(file == NULL)
    {
        printf("Error!Can not read file\n");
        exit(0);
    }
    while (fread(saved_hash, 1, SHA256_DIGEST_LENGTH,file) == SHA256_DIGEST_LENGTH) //Read the saved hash from the file
    {
        if(fscanf(file, "%255s\n",saved_filename) == 1 && strcmp(filename,saved_filename) ==0) // Read the file path from the file
        {
        found = 1;
        break;
        }
    }
    fclose(file);   //Close the file

    if(found == 0)
    {
    printf("Error! No match enter found for '%s'\n",filename);
    }
}