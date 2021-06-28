/*
  napisz alternatywną wersję programu squeeze(s1,s2), usuwającą z s1 wszystkie znaki występujące w ciągu s2
*/

#include <stdio.h>

void squeeze(char s1[], char s2[]) {
  int i, j, k = 0;
  int c;

  while((c = s2[k++]) != '\0'){
    for(i = j = 0; s1[i] != '\0'; i++) {
      if(s1[i] != c)
        s1[j++] = s1[i];
    }
  s1[j] = '\0';
  }
}

int main() {
  char table[20] = "karol charchut";
  char letters[3] = "ca";
  squeeze(table, letters);
  printf("%s", table);
}
