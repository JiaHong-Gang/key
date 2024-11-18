#include <stdio.h>
#include <openssl/sha.h>
#include <string.h>
#include <stdlib.h>
#include "compute_hash.h"
#include "load_password.h"
#include "lock_unlock_file.h"
void confirm_password(int i)
{
    char password[16], filename[256];
    unsigned char hash1[SHA256_DIGEST_LENGTH],hash2[SHA256_DIGEST_LENGTH];
    printf("Please tell me which file you want to unlock\n");
    scanf("%255s",filename);    
    printf("Please enter password to unlock file\n");
    scanf("%15s",password);
    compute_hash(password,hash2);
    load_password(hash1);
    if(memcmp(hash1,hash2,SHA256_DIGEST_LENGTH) == 0)
    {
        unlock_file(filename);
        remove("save_password.txt");
        exit(0);
    }
    else
    {
        printf("Incorrcet password\n");
        printf("You have %d chance left\n", i-1);
    }
}