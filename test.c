#include <stdio.h>
void test()
{
    const char * filename = "test.txt";
    printf("filename is %s\n",filename);
    printf("filename address is %p\n", (void *)filename);
    filename = "anthorfile.txt";
    printf("filename is %s\n", filename);
    printf("filename address is %p\n", (void *)filename);    
}

int main()
{
    test();
    return 0;
}