#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    // Square root
    printf("%f\n", sqrt(2));

    // Cube root
    printf("%f\n", cbrt(3));

    // Ceil
    printf("%f\n", ceil(3.14));

    // Floor
    printf("%f\n", floor(3.14));

    // Power
    printf("%f\n", pow(2, 3));

    // Absolute
    printf("%d\n", abs(-1));

    // Round
    printf("%f\n", round(2.4)); // Round returns double
    return 0;
}