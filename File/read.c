#include <stdio.h>

int main()
{
    FILE *fptr;
    fptr = fopen("file1.txt", "r");

    if (fptr == NULL)
    {
        perror("Not able to open the file");
        return 1;
    }
    char str[100];

    // fgets read one line at a time
    printf("Using fgets\n");
    while (fgets(str, 100, fptr))
    {
        printf("%s", str);
    }
    printf("\n");

    // fgetc read one char at a time
    rewind(fptr);
    int c;
    printf("Using fgetc\n");
    while ((c = fgetc(fptr)) != EOF)
    {
        putchar(c);
    }
    fclose(fptr);
    return 0;
}