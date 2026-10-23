#include <stdio.h>

int main()
{
    FILE *fptr;

    // write
    fptr = fopen("file.txt", "w");

    // printf but to a file
    fprintf(fptr, "Hi elaks!!");
    fprintf(fptr, "Name: %s", "virat");
    fprintf(fptr, "Score: %d", 278);

    // fputc - write single character
    fputc('i', fptr);

    // fputs - write a string
    fputs("அ", fptr);
    fputs("தமிழ்", fptr);

    // fwrite - write raw bytes (for binary or bulk data)
    // int num[] = {1, 2, 3, 4};
    // fwrite(num, sizeof(int), 5, fptr);
    // fclose(fptr);

    // append
    fptr = fopen("file1.txt", "a");
    fprintf(fptr, "appending some texts");
    fclose(fptr);

    return 0;
}