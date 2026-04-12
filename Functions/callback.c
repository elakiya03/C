#include<stdio.h>

void sayHi(){printf("Hi!😃");}
void sayBye(){printf("Bye😔\n");}

void say(void (*ptrFunc)()){
    ptrFunc();
}

int main(){
    say(sayHi);
    say(sayBye);
    return 0;
}