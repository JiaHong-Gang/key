#include <stdio.h>
#include <openssl/sha.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "setup_password.h"
#include "confirm_password.h"
#include "config.h"
int main()
{
    int first_time = 1, choice =0;
    printf("\nFile lock system\n");
    printf("1.Lock file\n");
    printf("2.Unlock file\n");
    printf("3.Exit\n");
    printf("Please enter your choice\n");
    scanf("%1d",&choice);   //Enter choice 
    switch(choice)
    {
        case 1:
            setup_password();       //Enter the password and file path to lock the file
            break;
        case 2:
            for (int i = 10; i>0;i--)       //Enter the password up to 10 times
            {
            confirm_password(i);            // Enter the password and file path to unlock the file
            }
            break;
        case 3:
            exit(0);              // Exit the systeam
            break;
        default:
            printf("Invalid choice\n");    
            break;
    }        
    return 0;
}