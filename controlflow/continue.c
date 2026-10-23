#include <stdio.h>

int main()
{

    for (int i = 0; i < 10; i++)
    {
        if (i == 3)
            continue;
        printf("%d\n", i);
    }
}

// skips 3 and continue print all other numbers