#include <stdio.h>

/* pobiera linię do stringa i zwraca jej długość */
int getln(char line[], int lim) {
    int c = 0, i = 0;
    while(--lim > 0 && (c=getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }
    if(c == '\n') {
        line[i++] = c;
    }
    line[i] = '\0';

    return i;

}

int strleng(char* line) {
    int i;
    for(i = 0; line[i] != '\0'; i++)
        ;
    return i;
}

int strrindex(char* line, char* pattern) {
    int i, j, k;

    for(i = 0; line[i] != '\0'; i++) {
        for(j = i, k = 0; pattern[k] != '\0' && line[j] == pattern[k]; j++, k++)
            ;
        if(k > 0 && pattern[k] == '\0')
            return i;
    }
    return -1;
}

int main() {

    char guma[50] = "guma";
    printf("%d", strleng(guma));
    return 0;
}

