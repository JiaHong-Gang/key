#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include "compute_hash.h"
#include "save_password.h"
#include "lock_unlock_file.h"
void setup_password()
{
    char input1[16],input2[16], filename[256];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    printf("Please set your password\n");
    scanf("%15s",input1);    
    while (1) 
    {
        printf("Please enter your password again\n");
        scanf("%15s",input2);
        if (strcmp(input1,input2) ==0)
        {
            break;
        }
        else
        {
            printf("password does not march, Please enter again\n");
        }
    }    
    printf("Please tell me which file you want to lock\n");
    scanf("%255s",filename);
    lock_file(filename);
    compute_hash(input1, hash);
    save_password(hash);
}