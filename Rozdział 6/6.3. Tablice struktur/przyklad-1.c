#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct key {
    char* keyword;
    int count;
} keytab[32] = {
"auto", 0,	
"break", 0,	
"case", 0,	
"char", 0,	
"const", 0,	
"continue", 0,	
"default", 0,	
"do", 0,	
"double", 0,	
"else", 0,	
"enum", 0,	
"extern", 0,	
"float", 0,	
"for", 0,	
"goto", 0,	
"if", 0,	
"int", 0,	
"long", 0,	
"register", 0,	
"return", 0,	
"short", 0,	
"signed", 0,	
"sizeof", 0,	
"static", 0,	
"struct", 0,
"switch", 0,
"typedef", 0,
"union", 0,
"unsigned", 0,
"void", 0,
"volatile", 0,
"while", 0
};


#define NKEYS 32
#define MAXWORD (sizeof(keytab) / sizeof(struct key))

int getword  (char* word, int max );
int binsearch(char* word, struct key keytab[], int size) {
    int low = 0;
    int cond;
    int high = size - 1;

    while(low <= high) {
        int mid = low + ((high - low) / 2);
        if((cond = strcmp(word, keytab[mid].keyword)) < 0) //word jest pierwsze alfabetycznie
            high = mid - 1;
        else if(cond > 0) //keyword jest pierwsze
            low = mid + 1;
        else 
            return mid;
    }
    return -1;
}

int getword(char* word, int lim) {
    int c;
    int i;
    char* w = word;

    while(isspace(c = getc(stdin))) //pomiń znaki białe
        ;

    if(c != EOF)
         *w++ = c;

    if(!isalpha(c)) { // słowo się kończy
        *w = '\0';
        return c;
    }

    for(; --lim > 0; w++) {
        if(!isalnum(*w = getc(stdin))) { //jeśli znak nie może być słowem, zwróć go i przerwij pętlę
            ungetc(*w, stdin);
            break;
        }
    }

    *w = '\0'; //zakończ słowo nullem
    return word[0];
}   

int main() {
    int n;
    char word[MAXWORD];

    while(getword(word, MAXWORD) != EOF) 
        if(isalpha(word[0]))
            if((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    for(n = 0; n < NKEYS; n++)
        if(keytab[n].count > 0)
            printf("%4d, %s\n", keytab[n].count, keytab[n].keyword);    

    return 0;
}





