#include <stdio.h>
#include <string.h>

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

int original(char* line, char* pattern) {
    int i, j, k;

    for(i = 0; line[i] != '\0'; i++) {
        for(j = i, k = 0; pattern[k] != '\0' && line[j] == pattern[k]; j++, k++)
            ;
        if(k > 0 && pattern[k] == '\0')
            return i;
    }
    return -1;
}

int strindex(char* line, char* pattern) {
    int i, j, k;
    int pattLen = strlen(pattern);
    int lineLen = strlen(line);

    //for(i = 0; line[i] != '\0'; i++) {
    for(i = 0; i != lineLen; i++) {
        //for(j = i, k = 0; pattern[k] != '\0' && line[j] == pattern[k]; j++, k++)
        for(j = i, k = 0; k != pattLen && line[j] == pattern[k]; j++, k++)
            ;   
        if(k > 0 && k == pattLen)
            return i;
    }
    return -1;
}

int strrindex(char* line, char* pattern) {
    int i, j, k;
    int pattLen = strlen(pattern);
    int lineLen = strlen(line);

    for(i = lineLen - 1; i >= 0; i--) {
        for(j = i, k = 0; k != pattLen && line[j] == pattern[k]; j++, k++)
            ;   
        if(k > 0 && k == pattLen)
            return i;
    }
    return -1;
}

int main() {
    int found = 0;
    int index;
    char line[500];
    char pattern[500] = "ar";
    while(getln(line, 500)) {
        if((index = strrindex(line, pattern)) >= 0) {
            printf("%d\t%s", index, line);
            found++;
        }
        
    }
    return found;
}