#include <stdio.h>

int main()
{
    char name[100];
    int age;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%i", &age);

    if (age < 18)
        printf("%s cannot vote\n",name);
    else
        printf("%s can vote\n",name);

    return 0;
}