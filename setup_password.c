#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include "compute_hash.h"
#include "save_password.h"
#include "lock_unlock_file.h"
void setup_password()
{
    char input_password[16],check_input[16], filename[256];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    printf("Please set your password\n");
    scanf("%15s",input_password);    //Enter password
    while (1)   
    {
        printf("Please enter your password again\n");
        scanf("%15s",check_input);  // Enter the password again to verify
        if (strcmp(input_password,check_input) ==0)
        {
            break;
        }
        else
        {
            printf("password does not march, Please enter again\n");
        }
    }    // If the password entered twice is the same, proceed to the next step
    printf("Please tell me which file you want to lock\n");
    scanf("%255s",filename);    // Enter the file path to lock
    lock_file(filename);        // Lock the file
    compute_hash(input_password, hash);     // Compute the hash
    save_password(filename, hash);      // Save the password and file path
}