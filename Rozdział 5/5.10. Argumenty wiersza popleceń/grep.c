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


#define MAXLINE 10000

int main(int argc, char** argv) {
    char line[MAXLINE];
    int found = 0, c;
    int except = 0;
    int numbers = 0;
    int linenumber = 0;

    
    while(--argc > 0 && (*++argv)[0] == '-')
        while(c = *++argv[0]) {
            switch(c) {
                case 'x':
                    except = 1;
                break;
                case 'n':
                    numbers = 1;
                break;
                default:
                    printf("error: invalid argument: %c\n", c);
                    return 1;
                break;
            }
        }
    if(argc != 1)
        printf("Usage: %s <pattern>\n", argv[0]);
    else
        while(getln(line, MAXLINE) > 0) {
            linenumber++;
            if((strstr(line, *argv) != NULL) != except) {
                if(numbers)
                    printf("%3d ", linenumber);
                printf("%s", line);
                found++;
            }
        }
    return found;
}