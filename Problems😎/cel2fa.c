#include <stdio.h>

float celToFah(int cel)
{
    return cel * 9 / 5 + 32;
}
int main()
{
    printf("Enter a temperature in celcius: ");
    int celcius;
    scanf("%d", &celcius);
    float result = celToFah(celcius);
    printf("Equivalent Fahrenheit: %.1f\n", result);
    return 0;
}