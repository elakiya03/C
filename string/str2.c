#include <stdio.h>
#include <string.h>

int main()
{
    // string length
    char str[30] = "Hi elakiya.";
    char str2[] = "Hi muku";
    printf("Length of string: %zu\n", strlen(str));
    // sizeof will always return the memory size (in bytes)
    printf("Length of string: %zu\n", sizeof(str));

    // Concatenate str2 to str1 (result is stored in str1).
    // Note that the size of str1 should be large enough to store the result of the two strings combine.
    strcat(str, str2);
    printf("String concatenation: %s\n", str);

    // string copy
    //  Copy str2 to str
    strcpy(str, str2);
    printf("After copying: %s\n", str);

    // string compare and print the result
    printf("Comparing string: %d\n", strcmp(str, str2));
    return 0;
}