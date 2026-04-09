#include <stdio.h>
int main()
{
    int prime;
    printf("Enter any number:\n");
    scanf("%d", &prime);
    if (prime == 1)
    {
        printf("Not a prime number");
    }
    else if (prime == 2)
    {
        printf("Prime");
    }
    else
    {
        int i = 0;
        for (i = 2; i <= prime / 2; i++)
        {
            if (prime % 2 == 0)
            {
                printf("No Prime");
            }
            else
            {
                printf("Prime");
            }
        }
    }
    return 0;
}