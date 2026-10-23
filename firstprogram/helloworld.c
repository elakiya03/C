#include <stdio.h>
#include <stdlib.h>

int main()
{
    // print("Hi Ben"); - not an inbuilt function
    printf("\tHey Ben\n"); //-------> using \t and \n in a sinlge line

    char *str = (char *)malloc(sizeof(char)); // string using dynamic allocation
    printf("Enter the name: \n");

    scanf("%s", str); // stops at whitespaces
    printf("\n%s", str);

    fgets(str, 100, stdin); // reads entire line
    printf("%s\n", str);

    free(str);
    return 0;
}