#include <stdio.h>

void strcat1(char* first, char* second) {
    while(*first != '\0')
        first++;
    while(*second) {
        *first = *second;
        first++;
        second++;
    }
}

int main() {
    char first[500] = "JP2 ";
    char second[500] = "GMD";
    strcat1(first, second);
    printf("%s", first);
}