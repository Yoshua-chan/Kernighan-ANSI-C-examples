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

int strindex(char* line, char* pattern) {
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
    int found = 0;
    char line[500];
    char pattern[500] = "ould";
    while(getln(line, 500)) {
        if(strindex(line, pattern) >= 0){
            printf("%s", line);
            found++;
        }
        
    }
    return found;
}

