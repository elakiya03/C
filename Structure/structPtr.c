#include <stdio.h>
struct player
{
    char *firstname;
    char *lastname;
};

void updateName(struct player *ptr)
{
    // Updating the value through function
    ptr->firstname = "Elakiya";
    ptr->lastname = "Sundar";
}
int main()
{
    struct player p = {"Virat", "Kohli"};

    // declare a pointer to struct
    struct player *ptr = &p;

    printf("%s %s\n", ptr->firstname, ptr->lastname);

    updateName(&p);
    printf("%s %s\n", p.firstname, p.lastname);
    return 0;
}