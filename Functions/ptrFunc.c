#include <stdio.h>
int add(int x, int y) { return x + y; }
int main()
{
    // Method of assinging function to pointer
    int (*ptr)(int, int) = add;
    // Method 2
    int (*ptr2)(int, int);
    ptr = &add;

    // Method 1 - calling function
    int result = ptr(5, 5);

    // Method 2 - calling function
    printf("%d\n", (*ptr)(3, 3));
    return 0;
}