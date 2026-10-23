#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "elaks hi";
    printf("%s\n", str);

    int length = (int)strlen(str);
    printf("Length of str: %d\n", length);
    printf("Array size including '\\0': %d\n", (int)sizeof str);

    // first char in str
    printf("%c\n", str[0]);

    // modify
    str[0] = 'E';
    printf("%s\n", str);

    // loop through str
    for (int i = 0; i < length; i++)
    {
        printf("%c", str[i]);
    }
    return 0;
}