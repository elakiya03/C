#include <stdio.h>

int main()
{
    //constant must be assigned with a value during decalration
    const int BIRTHYEAR = 2001;

    int num;
    printf("\nEnter a signed number: ");
    scanf("%d", &num);
    printf("%d\n", num);
    printf("%i\n", num); // other way to print integer

    printf("\naddress of the %d variable: ", num);
    printf("%p", &num); // to print address of the variable - %p

    printf("\nSize of the operator: ");
    printf("%zu", sizeof(num));

    unsigned int var;
    printf("\nEnter a unsigned num: ");
    scanf("%u", &var);
    printf("%u", var); //%u - to print unsigned variable

    char a;
    printf("\nEnter a single character: ");
    scanf(" %c", &a);
    printf("%c\n", a);

    float f;
    printf("\nEnter a float number: "); // precision is upto 6 places
    scanf("%f", &f);
    printf("%f\n", f);

    char b[100]; // String - array of characters
    printf("\nEnter a name (no whitespaces): ");
    scanf("%s", b);
    printf("%s\n", b); // prints string till whitespace

    double d;
    printf("\nEnter a double: ");
    scanf("%lf", &d);
    printf("\n%lf", d);

    float f1 = 35e3;  // 35 * 10^3 = 35000
    double d1 = 12E4; // 12 * 10^4 = 120000

    printf("%f\n", f1);
    printf("\n%.2f", f1); // only shows 2 decimal points
    printf("\n%lf", d1);

    return 0;
}