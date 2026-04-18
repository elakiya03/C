#include <stdio.h>
#include<string.h>
int main()
{
    char word[100];
    int n;
    scanf("%s", word);
    scanf("%d", &n);

    char join[300]="";
    for (int i = 0; i < n; i++)
    {
        strcat(join, word);
    }
    printf("%s\n",join);
    return 0;
}