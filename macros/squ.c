#include <stdio.h>
#define square(x) (x * x)

int main()
{
    printf("Enter a num: ");
    int num;
    scanf("%d", &num);
    printf("Square of %d: %d\n", num, square(num));
}