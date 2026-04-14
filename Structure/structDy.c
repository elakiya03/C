#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char *name;
} STUDENT;

int main()
{
    STUDENT *ptr = (STUDENT *)malloc(sizeof(STUDENT)); // one student

    if (ptr == NULL)
    {
        printf("Memory allocation is failed\n");
        return 1;
    }

    ptr->name = "brownie";
    ptr->id = 1;

    ptr[1].id = 2;
    ptr[1].name = "purple";

    printf("%d. %s\n", ptr->id, ptr->name);
    printf("%d. %s\n", (ptr + 1)->id, (ptr + 1)->name);

    STUDENT *s = (STUDENT *)malloc(3 * sizeof(STUDENT)); // 3 STUDENT

    if (s == NULL)
    {
        printf("Memory allocation is failed\n");
        return 1;
    }

    s[0].name = "Virat"; // -> 1
    (*s).id = 1;         // -> 2

    (s + 1)->id = 2; // ->3
    (*(s + 1)).name = "Gill";

    s[2].id = 3;
    s[2].name = "Washi";

    for (int i = 0; i < 3; i++)
    {
        printf("%d. %s\n", s[i].id, s[i].name);
    }

    free(ptr);
    free(s);
    return 0;
}