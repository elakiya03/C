#include <stdio.h>

inline int add(int x, int y)
{
    return x + y;
}

int main()
{
    printf("%d\n", add(5, 3));
    return 0;
}

/*
gcc -O1 inlineFunc.c -o inlineFunc && ./inlineFunc

use the above command to run this file.

real fix is add static keyword before inline.
static inline int add(..){}
*/