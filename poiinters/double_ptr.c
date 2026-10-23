#include <stdio.h>

int main()
{
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    int *ptr = &num;

    // double pointer
    int **dbl = &ptr;

    **dbl = 5;
    printf("Number: %d\n", num);
    printf("Single pointer: %d\n", *ptr);
    printf("double pointer : %d\n", **dbl);
    return 0;
}