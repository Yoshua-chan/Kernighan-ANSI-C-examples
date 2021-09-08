#include <stdio.h>

/* strcpy, kopiuje zawartość stringa t do s 
    wersja z tablicami i porównaniem*/

void strcpy1(char* s, char* t) {
    int i = 0;
    while((s[i] = t[i]) != '\0')
        i++;
}

int main() {
    char new[20];
    strcpy1(new, "Hello, World!");
    printf("%s", new);
}