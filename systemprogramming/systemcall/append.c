#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main()
{
    int fd = open("f.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);

    if (fd < 0)
    {
        write(2, "File error\n", 11);
        return 1;
    }

    const char *name1 = "Virat\n";
    const char *name2 = "Kabil\n";

    write(fd, name1, strlen(name1));
    write(fd, name2, strlen(name2));

    close(fd);
    return 0;
}