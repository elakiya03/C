#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("f.txt", O_RDONLY);

    if (fd < 0)
    {
        perror("Open Failed");
        return 1;
    }
    char buffer[15];
    off_t pos = lseek(fd, 6, SEEK_SET); // MOVE TO 6TH BYTE
    printf("Position: %lld\n", pos);    // Position of cursor

    int n = read(fd, buffer, 15);

    write(1, buffer, n);
    close(fd);

    // write in middle
    int fd1 = open("f.txt", O_WRONLY);
    if (fd1 < 0)
    {
        perror("Open Failed");
        return 1;
    }
    lseek(fd1, 0, SEEK_SET);
    write(fd1, "3", 1);

    // write in end
    lseek(fd1, 0, SEEK_END);
    write(fd1, "BYE\n", 4);
    close(fd1);

    return 0;
}