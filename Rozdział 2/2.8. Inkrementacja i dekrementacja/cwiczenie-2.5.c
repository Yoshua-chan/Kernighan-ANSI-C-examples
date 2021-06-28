/*
  napisz funkcję any(s1, s2), która zwraca informację pierwszego wystąpienia
  w ciągu s1 dowolnego znaku z ciągu s2 lub -1 jeżeli s1 nie zawiera żadnych
  znaków z s2 (to samo robi standardowa funkcja strpbrk, ale zwraca ona
  wskaźnik do znalezionej pozycji
*/

#include <stdio.h>

int any(char s1[], char s2[]) {
  int i, j, lowest = -1;

  for(i = 0; s2[i] != '\0'; i++) {
    for(j = 0; s1[j] != '\0'; j++) {
      if(s1[j] == s2[i] && (j < lowest || lowest == -1))
        lowest = j;
    }
  }
  return lowest; 
}

int main() {
  char karol[20] = "karol charchut";
  char znaki[20] = "x";
  any(karol, znaki);
  printf("%d", any(karol, znaki));
}
