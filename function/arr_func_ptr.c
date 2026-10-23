#include <stdio.h>

void add(int x, int y) { printf("Add: %d\n", x + y); }
void sub(int x, int y) { printf("Sub: %d\n", x - y); }
void mul(int x, int y) { printf("Mul: %d\n", x * y); }

int main()
{
    int x, y, choice;
    void (*ptr[])(int, int) = {add, sub, mul};

    while (1)
    {
        printf("\n0. Add\n1. Sub\n2. Mul\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3)
        {
            printf("BYE!\n");
            break;
        }
        else if (choice < 3)
        {
            printf("Enter x: ");
            scanf("%d", &x);
            printf("Enter y: ");
            scanf("%d", &y);
            ptr[choice](x, y);
        }
        else
            printf("Invalid entry!\n");
    }

    return 0;
}