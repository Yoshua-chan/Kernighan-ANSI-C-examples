#include <stdio.h>
#include <string.h>


int atoi(char s[]) {
  int i, n;

  n = 0;
  for(i = 0; (s[i] >= 'A' && s[i] <= 'F') || (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f'); ++i) {
    if(s[i] >= '0' && s[i] <= '9'){
      n = 16 * n + (s[i] - '0');
    } else if(s[i] >= 'a' && s[i] <= 'f') {
      n = 16 * n + (s[i] - 'a' + 10);
    } else if(s[i] >= 'A' && s[i] <= 'F') {
      n = 16 * n + (s[i] - 'A' + 10);
    }
  }
  return n;
}

int main() {
  printf("%d", atoi("FF"));
}
