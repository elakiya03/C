#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    printf("Hello\n");

    if (pid == 0)
    {
        printf("Child process PID: %d, PPID: %d \n", getpid(), getppid());
    }
    else
    {
        printf("Parent process PID: %d CPID: %d\n", getpid(), pid);
    }

    printf("Before fork\n");
    fork();
    printf("After fork\n");
    return 0;
}