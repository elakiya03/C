#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("new.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd < 0)
    {
        write(2, "File error\n", 11);
        return 1;
    }

    write(fd, "Hello elaks\n", 11);

    close(fd);

    return 0;
}