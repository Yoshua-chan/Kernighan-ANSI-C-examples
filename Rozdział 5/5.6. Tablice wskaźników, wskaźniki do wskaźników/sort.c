#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 50000


char *lineptr[MAXLINES];
int  readlines (char* lineptr[], int nlines);
void writelines(char* lineptr[], int nlines);
void qsortstr(char* v[], int left, int right);
int getln(char line[], int lim);
void swap(char* v[], int i, int j);

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

#define MAXLEN 1000 /* maksymalna długość wiersza */

/* readlines: odczytuje wiersze wejściowe */
int readlines(char* lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while((len = getln(line, MAXLEN)) > 0) {
        if((nlines >= maxlines) || (p = malloc(len * sizeof(char))) == NULL) {
            return -1;
        } else {
            line[len-1] = '\0'; /* usuń znak nowego wiersza */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

/* writeline: wypisuje wiersze wyjściowe */
void writelines(char* lineptr[], int nlines) {
    int i;

    for(i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}


void qsortstr(char* v[], int left, int right) {
    int i, last;

    if(left >= right)
        return;

    swap(v, left, (left + right)/2);
    last = left;

    for(i = left + 1; i <= right; i++)
        if(strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);

    swap(v, left, last);

    qsortstr(v, left, last-1);
    qsortstr(v, last+1, right);
}

void swap(char *v[], int i, int j) {
    char* temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main() {
    int nlines; /*liczba odczytanych wierszy*/
    
    if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsortstr(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}