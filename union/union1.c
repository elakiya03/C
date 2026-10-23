#include <stdio.h>

union player
{
    char *name; // 8 bytes
    int score;  // 4 bytes
};

int main()
{
    union player p;

    // size of the union
    printf("Size of union: %zu\n", sizeof(p));

    p.name = "elaks";
    p.score = 80;

    // printf("%s", p.name); // This value is no longer reliable
    printf("%d\n", p.score);
    return 0;
}