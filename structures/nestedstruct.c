#include <stdio.h>
struct player
{
    char *firstname;
    char *lastname;
};
struct team
{
    char *name;
    int score;
    struct player player; // nested structure
};
int main()
{
    struct player p;
    p.firstname = "Virat";
    p.lastname = "Kohli";

    struct team t;
    t.name = "RCB";
    t.score = 250;
    t.player = p;

    printf("%s where %s %s belongs to scored total of %d\n", t.name, t.player.firstname, t.player.lastname, t.score);
    return 0;
}