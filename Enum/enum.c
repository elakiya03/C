#include <stdio.h>

typedef enum // using typdef
{
    LOW = 8,
    MEDIUM, // NOW 9
    HIGH    // NOW 10
} Level;

int main()
{
    Level l = HIGH;

    switch (l)
    {
    case 10:
        printf("Level High");
        break;
    case 9:
        printf("Level Medium");
        break;
    case 8:
        printf("Level Low");
        break;
    default:
        printf("Invalid");
    }

    return 0;
}