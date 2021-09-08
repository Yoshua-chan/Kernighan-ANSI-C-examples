#include <stdio.h>

/* strlen zwraca długość ciągu str */
int strlen(char* str) {
    int len;
    for(len = 0; *str != '\0'; len++, str++)
        ;
    return len;
}

int main() {
    printf("%d\n", strlen("siema"));
}