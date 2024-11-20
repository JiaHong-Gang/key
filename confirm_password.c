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
    unsigned char saved_hash[SHA256_DIGEST_LENGTH],input_hash[SHA256_DIGEST_LENGTH];
    printf("Please tell me which file you want to unlock\n");
    scanf("%255s",filename);    // Enter the file path to unlock 
    printf("Please enter password to unlock file\n");
    scanf("%15s",password);     //Entrer the password to unlock
    compute_hash(password,input_hash);  // Compute the entered hash
    load_password(filename,saved_hash); // Load the saved file path and password
    if(memcmp(saved_hash,input_hash,SHA256_DIGEST_LENGTH) == 0) //Compare the entered password and file path with the saved ones
    {
        unlock_file(filename);          // Unlock the file
        exit(0);
    }
    else
    {
        printf("Incorrcet password\n");
        printf("You have %d chance left\n", i-1);
    }
}