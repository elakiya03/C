#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
int main()
{
    // int fd = open("f.txt", O_RDONLY);
    int fd = open("test.txt", O_RDONLY);

    if (fd < 0)
    {
        write(2, "File open error\n", 16);
        return 1;
    }

    char *buffer = malloc(100 * sizeof(char));
    int n = read(fd, buffer, 100);
    write(1, buffer, n);
    close(fd);
    free(buffer);
    return 0;
}