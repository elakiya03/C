#include <stdio.h>

void function2()
{
    int b = 20;
    printf("func2 - b: %p\n", &b);
}
void function1()
{
    int a = 2;
    printf("func1 - a: %p\n", &a);
    function2();
}
int main()
{
    int x = 9;
    printf("main - x: %p\n", &x);
    function1();
    return 0;
}

/*
Stack Memory

Higher Address
-----------------
| main  frame   |   ← 0x6798
-----------------
| func1 frame   |   ← 0x676c
-----------------
| func2 frame   |   ← 0x674c  (current)
-----------------
Lower Address

*/