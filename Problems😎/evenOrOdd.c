#include <stdio.h>
#include <stdbool.h>

bool evenOrodd(int num)
{
    return num % 2 == 0 ? true : false;
}

int main()
{
    printf("Enter any number: ");
    int num;
    scanf("%d", &num);
    if (evenOrodd(num))
        printf("Even\n");
    else
        printf("Odd\n");

    return 0;
}