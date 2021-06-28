/* moja implementacja programu kernighana, zrobiona przed przepisaniem pierwszego przykładu */
/* program ma na celu zliczenie każdej z cyfr, całkowitej liczby znaków białych, oraz innych
 * znaków z wejścia standardowego */
#include <stdio.h>

int main() {
  int c = 0;
  int digits[10] = {0,0,0,0,0,0,0,0,0,0};
  int others = 0;
  int whites = 0;

  c = getchar();
  while(c != EOF) {
    if(c >= '0' && c <= '9') {
      ++digits[c - '0'];
      //printf("rzujmi");
    } else if(c == '\t' || c == ' ' || c == '\n') {
      whites++;
    } else {
      others++;
    }
    c = getchar();
  }
  printf("White characters: %d\n", whites);
  printf("Digits:\n");
  for(int i = 0; i < 10; i++) {
    printf("  %d: %d\n", i, digits[i]);
  }
  printf("Other characters: %d", others);
}
