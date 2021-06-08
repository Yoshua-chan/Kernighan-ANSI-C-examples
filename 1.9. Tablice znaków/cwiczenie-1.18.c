/* Program ten usuwa białe znaki na końcu wierszy */

#include <stdio.h>

#define MAXLINE 1000


int getln(char line[], int maxline);
void copy(char to[], char from[]);
int getLastNonWhite(char string[]);
void cutString(char string[], int index);

int main() {         
  char line[MAXLINE];
  int len;
  while((len = getln(line, MAXLINE)) > 0) {
    cutString(line, getLastNonWhite(line));
    printf("%s", line);
  }

}
void cutString(char string[], int index){
  if(string[0] != '\n') {
    string[index + 1] = '\n';
    string[index + 2] = '\0';
  }
}

int getLastNonWhite(char s[]) {
  int index = 0;
  for(int i = 0; s[i] != '\0'; i++) {
    if(s[i] == '\n' || s[i] == ' ' || s[i] == '\t') {
    } else {
      index = i;
    }
  }
  return index;
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
