#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getln(char* string, int max) {
    int i, c;
    for(i = 0; (c = getchar()) != EOF && i < max - 1 && c != '\n' ; i++) {
        string[i] = c;
    }
    if(c == '\n') {
        string[i] = c;
        i++;
    }
    string[i] = '\0';
    return i;
}

#define MAXLINE 100000

int main(int argc, char** argv) {
    char** lines;
    char* templine;
    char line[MAXLINE];
    int nlines;
    int i;
    char c;

    while(--argc) {
        if( (*++argv)[0] == '-')
            for(int i = 0; (*argv)[i] != '\0'; i++) {
                if((*argv)[i] == 'n') {
                    nlines = atoi( *(argv + 1));
                }
            }
    }

    lines = malloc(nlines * sizeof(char*));
    
    int len;

    while((len = getln(line, MAXLINE)) > 0) {
        templine = malloc( (len + 1) * sizeof(char) ); //allocate a new array with lenght of the line from stdin
        strcpy(templine, line); //copy the line from stdin to heap-allocated array
        //printf("%s", templine);
        for(i = 0; i < nlines - 1; i++) { //move all pointers to the left
            lines[i] = lines[i + 1];
        }
        lines[i] = templine; //add new pointer to the end of the array;
    }

    for(i = 0; i < nlines; i++) {
        printf("%s", lines[i]);
    }

    return 0;
}