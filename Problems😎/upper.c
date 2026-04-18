#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[100];
    fgets(s, 100, stdin);
    s[strcspn(s, "\n")] = 0;

    for (int i = 0; s[i]; i++)
    {
        s[i] = toupper(s[i]);
    }

    printf("%s\n", s);
    printf("Length: %lu\n", strlen(s));
    return 0;
}