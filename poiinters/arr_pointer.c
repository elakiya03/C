#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4};
    printf("First element: %d\n", *arr);
    printf("Sec element: %d\n", *(arr + 1));
    printf("third element: %d\n", *(arr + 2));

    // Method 2 - Loop through
    int *ptr = arr;

    for (int i = 0; i < 4; i++)
    {
        printf("%d\n", *(ptr + i));
    }
}