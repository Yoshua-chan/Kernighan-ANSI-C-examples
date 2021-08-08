/*
 Napisz ponownie funkcję lower(c) zamieniającą wielkie litery na małe.
 zastosuj w mijesce instrukcji if-else wyrażenie warunkowe.
*/

#include <stdio.h>
#include <stdlib.h>

void lower(char s[]) {
  for(int i = 0; s[i] != '\0'; i++) {
    s[i] = (s[i] >='A' && s[i] <= 'Z') ? s[i] - ('A' - 'a') : s[i];
  }
}

int main() {
  char napis[20] = "KaRoL cHaRcHuT";
  lower(napis);
  printf("%s", napis);
}
