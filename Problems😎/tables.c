#include <stdio.h>

int main()
{
    printf("Enter any number: ");
    unsigned int n;
    scanf("%u", &n);

    for (int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n", n, i, n * i);
    }
    return 0;
}