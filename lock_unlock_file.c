#include <stdio.h>
#include <sys/stat.h>
void lock_file(const char * filename)
{
    if(chmod(filename,0) == 0)  //Lock the file
    {
        printf("File %s has been locked\n",filename);
    }
    else
    {
        printf("Failed to locked file %s\n",filename);
    }
}

void unlock_file(const char * filename)
{
    if(chmod(filename,0644) == 0)      //Unlock the file
    {
        printf("File %s has been unlocked\n",filename);       
    }
    else
    {
        printf("Failed to unlocked file %s\n",filename);
    }
}