#include <stdio.h>
#include <stdlib.h>

int *test()
{
    int x = 100;
    return &x; // wrong
}

int main()
{
    int *p = test();
    printf("%d\n", *p); // unpredictable
}

/*Correct Way
1.Use heap

    ```c
    int* test()
    {
        int *x = malloc(sizeof(int));
        *x = 100;
        return x;
    }
    ```

*/