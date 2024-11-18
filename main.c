#include <stdio.h>
#include <openssl/sha.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "setup_password.h"
#include "confirm_password.h"
int main()
{
    int first_time = 1;
    if(access("save_password.txt", F_OK) != 0)
    {
        first_time = 1;
    }
    else
    {
        first_time = 0;
    }
    if(first_time)
    {
       setup_password();
       exit(0);
    }
    for (int i = 10; i>0;i--)
    {
       confirm_password(i);
    }
    return 0;
}