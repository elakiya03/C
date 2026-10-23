#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        return 5;
    }
    else
    {
        int status;
        wait(&status);                                  // parent wait for child to finish ans collect child status
        printf("Exit code: %d\n", WEXITSTATUS(status)); // macrro extracts the actual exit code
    }
}

/*
        fork()
        |
        ├── Child → return 5 → exit
        |
        └── Parent → wait() → gets status → prints 5
*/