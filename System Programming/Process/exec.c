#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    // Program 1
    execl("/bin/ls", "ls", NULL);

    // Program 2 - use with fork
    pid_t pid = fork();

    if (pid == 0)
    {
        execl("/bin/ls", "ls", NULL);
    }
    else
    {
        wait(NULL);
        printf("Parent done\n");
    }

    // Program 3
    printf("Before exec\n");
    execl("/bin/ls", "ls", NULL); // If exec() succeeds: code AFTER it never runs
    printf("After exec\n");

    return 0;
}

/*
    Parent
    |
    fork()
    |
    ├── Child → exec(ls) → becomes ls
    |
    └── Parent → wait → prints message
*/