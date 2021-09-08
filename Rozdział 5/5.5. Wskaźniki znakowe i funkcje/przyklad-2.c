#include <stdio.h>

/* strcpy, kopiuje zawartość stringa t do s 
    wersja ze wskaźnikami i porównaniem*/

void strcpy1(char* s, char* t) {
    while((*s++ = *t++) != '\0')
        ;
}


int main() {
    char new[20];
    strcpy1(new, "Hello, World!");
    printf("%s", new);
}