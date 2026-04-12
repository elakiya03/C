#include <stdio.h>
int main()
{
    int choice = 1;

    switch (choice)
    {
    case 1:
        printf("First choice\n");
        break;
    case 2:
        printf("Second choice\n");
        break;
    default:
        printf("Default\n");
    }
}