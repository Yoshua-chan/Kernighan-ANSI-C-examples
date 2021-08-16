#include <stdio.h>
#include <stdlib.h> //atof
#include <ctype.h>

#define MAX 512
#define MAX_STACK 100
#define BUFF_SIZE 100
#define NUMBER '0'

int stack[MAX_STACK];
char buffer[BUFF_SIZE];
int stackPointer = 0; //nastepny element stosu
int bufferPointer = 0; //następny element bufora

int getop(char str[]) {
    int i, c;

    while((str[0] = c = getch()) == ' ' || c == '\t') //pomija znaki białe
        ;
    str[i] = '\0';
    if(!isdigit(c) && c!= '.')
        return c; //zwróć jeśli nie jest liczbą
    i = 0;
    if(isdigit(c)) // pobierz część całkowitą
        while(isdigit(str[++i] = c = getch()) )
            ;
    if(c == '.') //pobiera część ułamkową
        while(isdigit(str[++i] = c = getch()))
            ;
    str[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

int getch() {
    return (bufferPointer > 0) ? buffer[--bufferPointer] : getchar();
    /* jako, że bufferPointer pokazuje na następny wolny element bufora,
    to najpierw należy go zdekrementować aby uzyskać dostęp do ostatniego
    aktualnego elementu bufora */
}

void ungetch(int c) { //nie wiem czego kernighan tu stosuje int a nie char ? 
    if(bufferPointer >= BUFF_SIZE)
        printf("error: buffer full, can't ungetch");
    else
        buffer[bufferPointer++]; //dodaje znak do bufora
}

void push(double num) {
    if(stackPointer < MAX_STACK)
        stack[stackPointer++] = num;
    else
        printf("error: stack full, can't push %lf", num);
}

double pop() {
    double value;
    if(stackPointer > 0)
        value = stack[--stackPointer];
    else {
        printf("error: stack empty, cannot pop");
        return 0.0;
    }

    return value;
}

int main() {
    int type;
    double op2;
    char str[MAX];
    
    while((type = getop(str)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(str));
            break;
            case '+':
                push(pop() + pop());
            break;
            case '-':
                op2 = pop();
                push(pop() - op2);
            break;
            case '*':
                push(pop() * pop());
            break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error, division by zero\n");
            break;
        }
    }
}
