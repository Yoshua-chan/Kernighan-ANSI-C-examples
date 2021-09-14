#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 50000


char *lineptr[MAXLINES];
int  readlines (char* lineptr[], int nlines);
void writelines(char* lineptr[], int nlines, int reversed);
//void qsortstr(char* v[], int left, int right);
void qsortstr(void* v[], int left, int right, int (*comp)(void*, void*));
int getln(char line[], int lim);
void swap(void* v[], int i, int j);

/* pobiera linię do stringa i zwraca jej długość */
int getln(char line[], int lim) {
    int c = 0, i = 0;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }
    if(c == '\n') {
        line[i++] = c;
    }
    line[i] = '\0';

    return i;
    
}

#define MAXLEN 100000 /* maksymalna długość wiersza */

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
void writelines(char* lineptr[], int nlines, int reversed) {
    int i;

    if(reversed){
        for(i = nlines - 1; i >= 0 ; i--)
            printf("%s\n", lineptr[i]);
    return;
    }

    
    for(i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}


void qsortstr(void* v[], int left, int right, int (*comp)(void*, void*)) {
    int i, last;

    if(left >= right)
        return;

    swap(v, left, (left + right)/2);
    last = left;

    for(i = left + 1; i <= right; i++)
        if( (*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);

    swap(v, left, last);

    qsortstr(v, left, last-1, comp);
    qsortstr(v, last+1, right, comp);
}

int numcmp(char* s1, char* s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if(v1 < v2)
        return -1;
    else if(v1 > v2)
        return 1;
    else 
        return 0;
}

int strcmp_ignore_case(char* s1, char* s2) {
    int i;
    for(i = 0; (tolower(s1[i]) == tolower(s2[i])); i++)
        if(s1[i] == '\0')
            return 0;
    return (tolower(s1[i]) - tolower(s2[i]));
}

void swap(void *v[], int i, int j) {
    void* temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main(int argc, char** argv) {
    int nlines; /*liczba odczytanych wierszy*/
    int numeric    = 0;
    int reversed   = 0;
    int ignoreCase = 0;
    int directory  = 0;
    char c;

    if(argc > 1 && argv[1][0] == '-') {
        for(int i = 0; (c = argv[1][i]) != '\0'; i++) {
            switch(c) {
                case 'n':
                    numeric    = 1;
                break;
                case 'r':
                    reversed   = 1;
                break;
                case 'f':
                    ignoreCase = 1;
                break;
                case 'd':
                    directory  = 1;
                break;
            }
        }
    }
    if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        int (*function)(void*, void*);

        if(ignoreCase) {
            function = (int (*)(void*, void*)) strcmp_ignore_case;
        } else if(numeric) {
            function = (int (*)(void*, void*)) numcmp;
        } else {
            function = (int (*)(void*, void*)) strcmp;
        }

        qsortstr((void**) lineptr, 0, nlines-1, function);
        writelines(lineptr, nlines, reversed);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }

}
