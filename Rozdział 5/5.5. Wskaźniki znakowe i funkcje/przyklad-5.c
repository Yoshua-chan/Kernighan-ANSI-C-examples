#include <stdio.h>

int strcmp1(char *s, char *t) {
    int i;
    for( ; *s == *t; s++, t++)
        if(!*s)
            return 0;
    return (*s) - (*t);
}


int main() {
    printf("%d \n", strcmp1("Hello, World!", "hemlo worlmd ;c"));
}