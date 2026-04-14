#include <unistd.h>

int main()
{
    write(1, "Hello sys call\n", 19);
    write(2, "Error\n", 6);

    write(1, "ABC\n", 4);
    write(1, "XYZ\n", 4);
    return 0;
}

/*
1 - file descriptor (stdout)
string - message
19 - number of bytes
*/