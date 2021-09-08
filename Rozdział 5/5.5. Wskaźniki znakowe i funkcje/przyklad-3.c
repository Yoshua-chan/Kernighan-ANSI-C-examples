#include <stdio.h>

/* strcpy, kopiuje zawartość stringa t do s 
    wersja ze wskaźnikami bez porównania*/

void strcpy1(char* s, char* t) {
    while(*s++ = *t++)
        ;
}


int main() {
    char new[20];
    strcpy1(new, "Hello, World!");
    printf("%s", new);
}