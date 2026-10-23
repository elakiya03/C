#include <stdio.h>

void say_hi() { printf("Hi!😃"); }
void say_bye() { printf("Bye😔\n"); }

void say(void (*ptrFunc)())
{
    ptrFunc();
}

int main()
{
    say(say_hi);
    say(say_bye);
    return 0;
}