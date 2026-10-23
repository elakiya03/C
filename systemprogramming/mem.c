#include <stdio.h>
#include <stdlib.h>

int global_init = 10;
int global_uninit;

int main()
{
    int local_var = 1;
    int *heap_var = malloc(sizeof(int));

    *heap_var = 30;

    printf("Text (main): %p\n", main);             // complied code and read-only
    printf("Global init: %p\n", &global_init);     // initialized global/static variables
    printf("Global uninit: %p\n", &global_uninit); // uninialized global (default = 0)
    printf("Heap: %p\n", heap_var);                // dynamic mem and grows upwards
    printf("Stack: %p\n", &local_var);             // local var & function calls and grow downwards

    int local2 = 50;
    printf("Stack 2: %p\n", &local2);
    return 0;
}

/*

High Address
------------
|   Stack   |  ↓ grows down
------------
|           |
|   Heap    |  ↑ grows up
------------
|   BSS     |
------------
|   Data    |
------------
|   Text    |
------------
Low Address

*/