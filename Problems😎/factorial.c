#include <stdio.h>

long factorial(int num)
{
    if (num == 0)
        return 1;
    return num * factorial(num - 1);
}

int main()
{
    printf("Enter a number: ");
    int n;
    scanf("%d", &n);

    long res = factorial(n);
    printf("%d! = %ld\n", n, res);
    return 0;
}