#include <stdio.h>
#include <time.h>

typedef enum
{
    SUN,
    MON,
    TUES,
    WED,
    THUR,
    FRI,
    SAT
} days;

int main()
{
    time_t now = time(NULL);
    printf("%s", ctime(&now));

    struct tm *t = localtime(&now);
    days day = t->tm_wday;
    switch (day) // Day of week 0=sunday
    {
    case 0:
        printf("Sunday");
        break;
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("tuesday");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;
    }
    return 0;
}