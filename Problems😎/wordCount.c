#include <stdio.h>
#include <string.h>
int main()
{
    char s[500];
    int count = 0;
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0; // go through str until hit \n, give me that position

    for (int i = 0; s[i]; i++)
    {
        if (s[i] == ' ')
            count++;
    }
    printf("%d words\n", count+1);
    return 0;
}