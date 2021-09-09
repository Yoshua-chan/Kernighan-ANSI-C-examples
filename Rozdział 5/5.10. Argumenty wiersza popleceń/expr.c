#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


#define STACKSIZE 1000
static double stack[STACKSIZE];
static int stackptr = 0; 

void push(double value) {
    if(stackptr == STACKSIZE) {
        fprintf(stderr, "How the fuck do you have %d elements on an RPN stack?!\n", STACKSIZE);
        exit(1);
    } else {
        stack[stackptr++] = value;
#ifdef LOG
        printf("pushed %d to stack at position %d\n", value, stackptr - 1);
#endif
    }
}

double pop() {
    if(stackptr == 0) {
        fprintf(stderr, "error: stack empty\n");
        exit(1);
    }
#ifdef LOG
    printf("popped %d from stack\n", stack[stackptr - 1]);
#endif
    return stack[--stackptr];
}

#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4
#define SQR 5

int isOp(char c) {
    switch(c) {
        case 'x':
            return MUL;
        break;
        case '+':
            return ADD;
        break;
        case '-':
            return SUB;
        break;
        case '/':
            return DIV;
        break;
        case 'v':
            return SQR;
        break;
        default:
            return 0;
        break;
    }
}

int main(int argc, char** argv) {
    double temp;

    int op;
    char c;
    while(--argc > 0) {
        c = (*++argv)[0]; //pierwsza litera, zaczynając od argv[1]
        op = isOp(**argv);
        if(isdigit(c) || (c == '-' && strcmp(*argv, "-"))) { // *argv nie jest równe "-", traktujemy jako ujemną liczbę
            push(atof(*argv)); 
        } else if(op) {
            switch(op) {
                case ADD:
                    push(pop() + pop());
                break;
                case SUB:
                    temp = pop();
                    push(pop() - temp);
                break;
                case MUL:
                    push(pop() * pop());
                break;
                case DIV:
                    temp = pop();
                    push(pop() / temp);
                break;
                case SQR:
                    push(sqrt(pop()));
                break;
                default:
                    printf("error: invalid operator %s\n", *argv);
                break;
            }
        }
    }
    printf("%f\n", stack[0]);
    return 0;
}
