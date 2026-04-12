#include <stdio.h>
int main()
{
    char str[] = "elaks hi";
    printf("%s\n", str);

    // first char in str
    printf("%c\n", str[0]);

    // modify
    str[0] = 'E';
    printf("%s\n", str);

    // loop through str
    int l = sizeof(str) / sizeof(str[0]);
    for (int i = 0; i < l; i++)
    {
        printf("%c", str[i]);
    }
    return 0;
}