#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr1 = malloc(sizeof(*ptr1)); // one integer
    if (ptr1 == NULL)
    {
        printf("Unable to allocate memory");
        return 1; // Exit the program with an error code
    }
    *ptr1 = 2;
    ptr1[1] = 4; // ---> method 1

    printf("%d %d\n", *ptr1, ptr1[1]);

    int *ptr2 = malloc(4 * sizeof(*ptr2)); // 4 integer
    if (ptr2 == NULL)
    {
        printf("Unable to allocate memory");
        return 1; // Exit the program with an error code
    }
    *ptr2 = 5;
    *(ptr2 + 1) = 10; // ---> mwthod 2
    printf("%d\n", *ptr2);

    free(ptr1);
    free(ptr2);
    return 0;
}