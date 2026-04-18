#include <stdio.h>

int main()
{
    double weight, height;
    scanf("%lf", &weight); // in kg
    scanf("%lf", &height); // in m

    printf("BMI: %.1lf", weight / (height * height));

    return 0;
}