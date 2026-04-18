#include <stdio.h>

int main()
{

    printf("Enter 3 digit number: ");
    int n;
    scanf("%d", &n);
    printf("Hundreds: %d\n", (n / 100) % 10);
    printf("Tens: %d\n", (n / 10) % 10);
    printf("Ones: %d\n", n % 10);
    return 0;
}