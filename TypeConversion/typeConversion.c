#include <stdio.h>

int main()
{
    int num = 5;
    int num2 = 2;

    // method 1
    float sum1 = num / num2;
    printf("Number (before type conversion): %f\n", sum1);

    // method 2
    float sum2 = (float)num / num2;
    printf("Number (after type conversion): %f\n", sum2);

    return 0;
}