// printf(3+3) is NOT possible because printf expects a format string as its first argument,
// not a direct value. Passing 3+3 directly would cause a compilation error since printf
// requires a const char* (string) to specify how to format the output.

// printf("%d", 3+3) IS possible because:
// - "%d" is the format string that tells printf to expect and print an integer
// - 3+3 is evaluated to 6, which is passed as the integer argument to be formatted

// Why C++ and Java can do cout << 3+3 or System.out.println(3+3) directly, but C cannot:
// - C++: cout is an object with overloaded << operators that can handle different data types automatically
// - Java: println() is overloaded for different types (int, double, String, etc.) so it knows how to print them
// - C: printf is a variadic function that requires explicit format specifiers (%d, %f, %s) to know what type of data is being passed

#include <stdio.h>

int main()
{
    printf("%d\n", 3 + 3);

    // print mix of text and numbers
    printf("everything will falls into place on %d %s",2016,"year");
    return 0;
}
