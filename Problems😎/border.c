// https://www.w3schools.com/practice/practice.php?problem=BASICS05&lang=c

// Print a rectangle border made of stars.

#include <stdio.h>
int main()
{
    int l, b;
    printf("Enter length: ");
    scanf("%d", &l);
    printf("Enter breadth: ");
    scanf("%d", &b);

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (i == 0 || j == b - 1 || j == 0 || i == l - 1)
                printf("*");
            // printf("%d%d ",i,j);
            else
                printf(" ");
        }
        printf("\n");
    }
}