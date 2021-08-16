#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

/*kalkulator z odwrotną notacją polską*/
int main() {
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");                
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100 /*dopuszczalna głębokość stosu wawrtości */
int sp = 0;         /*następna wolna pozycja stosu*/
double val[MAXVAL]; /*stos*/

/*push: zapisuje f na stosie*/
void push(double f) {
    if(sp < MAXVAL)
        val[sp++] = f;
    else 
        printf("error: stack full, can't push %g\n", f);
}

/*pop: zdejmuje i zwraca wartość z wierzchołka stosu*/
double pop(void) {
    if(sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void clearStack(void) {
    sp = 0;
}

int getLast(void) {
    return val[sp - 1];
}

int duplicate(void) {
    int x = getLast();
    push(x);
    return x;
}

void swap() {
    int x, y;
    x = pop();
    y = pop();
    push(x);
    push(y);
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/*getop: pobiera następny operator lub operand (liczbę)*/
int getop(char s[]) {
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c; /*nie jest liczbą*/
    i = 0;
    if(isdigit(c)) /*pobierz część całkowitą */
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c == '.') /*pobierz część całkowitą*/
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /*bufur dla ungetch*/
int bufp = 0;      /*następna wolna pozycja w buforze*/

int getch(void){ /*pobiera znak (może być znakiem wcześniej wycofanym)*/
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}