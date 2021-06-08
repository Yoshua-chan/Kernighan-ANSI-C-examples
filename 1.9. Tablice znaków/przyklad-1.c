#include <stdio.h>

#define MAXLINE 1000

int getln(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len; /* długość bieżącego wiersza */
  int max; /* największa znana wartość */
  char line[MAXLINE]; /* bieżacy wiersz wejścia */
  char longest[MAXLINE]; /* najdłuższy znany wiersz */

  max = 0;
  while( (len = getln(line, MAXLINE)) > 0) {
    if(len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if(max > 0){
    printf("%s", longest);
  }
  return 0;
}

int getln(char s[], int lim) {
  int c = 0, i;

  for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    // i < lim - 1, bo musi zostać miejsce na '\0'
    s[i] = c;
  }
  if(c == '\n') {
    s[i] = c;
    i++;
  } s[i] = '\0';
  return i;
}
void copy(char to[], char from[]) {
  int i = 0;

  while((to[i] = from[i]) != '\0') {
    i++;
  }
}
