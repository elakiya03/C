#include <stdio.h>
#include <string.h>
struct team
{
    char name[100];
    int score;
    char *name_;
} t1, t2; // one structure multiple variable

int main()
{
    struct team m1;

    // m1.name = "Virat"; ------> ERROR - array is not a pointer, can't assign like this
    // In C, array are not assignable.
    strcpy(m1.name, "Virat");
    m1.score = 78;
    m1.name_ = "Kohli";

    printf("Player name: %s\n", m1.name);
    printf("%s score: %d\n", m1.name_, m1.score);

    t1.name;

    return 0;
}