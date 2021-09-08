#include <stdio.h>

int strcmp1(char *s, char *t) {
    int i;
    for(i = 0; s[i] == t[i]; i++)
        if(s[i] != '\0')
            return 0;
    return (s[i]) - (t[i]);
}


int main() {
    printf("%d \n", strcmp1("Hello, World!", "hemlo worlmd ;c"));
}