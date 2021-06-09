/* Program wypisuje najdłuższy wiersz z wejścia standardowego */
/* Jest to zmieniona wersja jednego z poprzednich programów, lecz ta wersja
 * wykorzystuje zmienne globalne zamiast przekazywania parametrów */
#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];
int getln(void);
void copy(void);

int main() {
  int len;
  extern int max; //słowo kluczowe "extern" deklaruje, że zmienna jest zmienną zewnętrzną
  extern char longest[];

  max = 0;
  while((len = getln()) > 0) {
    if(len > max) {
      max = len;
      copy();
    }
  }
  if(max > 0) {
    printf("%s", longest);
  }
  return 0;
}

int getln(void) {
  int c, i;
  extern char line[];

  for(i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if(c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}
void copy(void) {
  int i;
  extern char line[], longest[];

  i = 0;
  while((longest[i] = line[i]) != '\0')
    ++i;

}
