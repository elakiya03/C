#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 8};
    int arr2[5];

    // 7*4=28
    printf("Length of the Array: %zu\n", sizeof(arr));

    int length = sizeof(arr) / sizeof(arr[0]);
    // 7
    printf("Length of the Array: %d\n", length);
    return 0;
}