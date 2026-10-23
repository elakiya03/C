#include <stdio.h>

void count()
{
    static int num = 0;
    num++;
    printf("%d\n", num);
}

int main()
{
    count();
    count();
    count();
    return 0;
}