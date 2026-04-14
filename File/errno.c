#include <stdio.h>
#include <errno.h>  //errno
#include <string.h> //strerror
#include <stdlib.h> // exit
int main()
{
    FILE *f = fopen("fil.txt", "r");

    if (f == NULL)
    {
        printf("Error: %s\n", strerror(errno)); // errno is global variable that stores error code from the last failed operation. strerror(errno) will convert error code into a reable message.
        exit(1);
    }
    fclose(f);
    return 0;
}