#include <stdio.h>
#include "calc.h"

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