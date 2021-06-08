#include <stdio.h>

#define MAXLINE 1000
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

void reverse(char* string) {
  int charNum = 0;
  char temp;

  for(int i = 0; (string[i] != '\n' && string[i] != '\0'); i++) {
    charNum++;
  }

  for(int i = 1; i <= charNum/2; i++) {
    temp = string[charNum - i];
    string[charNum - i] = string[i - 1];
    string[i - 1] = temp;
  }
}

int main() {
  char line[MAXLINE];
  int len;
  while((len = getln(line, MAXLINE)) != EOF && len > 0) {
    reverse(line);
    printf("%s", line);
  }
}
