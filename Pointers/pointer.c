#include <stdio.h>
int main()
{
    int num = 1;
    int *ptr = &num;
    // memory address
    printf("%p\n", ptr);
    // data stored in pointer points to
    printf("%d\n", *ptr);
    return 0;
}