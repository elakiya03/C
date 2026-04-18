#include <stdio.h>
#define PI 3.14
int main()
{
    int n;
    float area;
    printf("Enter any one of these\n1. Recatangle\n2. Triangle\n3. Circle\n");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        int length, breadth;
        printf("Enter Length: ");
        scanf("%d", &length);
        printf("Enter breadth: ");
        scanf("%d", &breadth);
        area = length * breadth;
        break;
    case 2:
        int base, height;
        printf("Enter base: ");
        scanf("%d", &base);
        printf("Enter height: ");
        scanf("%d", &height);
        area = base * height / 2;
        break;
    case 3:
        int radius;
        printf("Enter radius: ");
        scanf("%d", &radius);
        area = PI * radius * radius;
        break;
    default:
        printf("Invalid input\n");
        break;
    }
    printf("Area: %.2f\n", area);
    return 0;
}