/*
  W systemie liczenia z uzupełnieniem dwójkowym x &= (x-1) usuwa
  z wartości x pierwszą jedynkę po prawej stronie. Wyjaśnij dlaczego
  Wykorzystaj to do napisania szybszej wersji funkcji bitcount
*/

#include <stdio.h>

void printBits(int x) {
  for(int i = 1; i <= (int)sizeof(x)*8; i++) {
    printf("%d", (x >> (sizeof(x)*8 - i)) & 0b00000001);
    if(i % 8 == 0)
      putchar(' ');
  }
}

int bitcount(unsigned int x) { /*Deklaracja unsigned sprawia, że przy przesuwaniu w prawo
                                 nowe bity zawsze będą zerami niezależnie od tego jak komputer
                                 przechowuje bity znaku */
  int b;

  for(b = 0; x != 0; x &= (x-1))
    b++;
  return b;
}

int bitcountAlt(unsigned int x) {
  int b;

  for(b = 0; x != 0; x &= (x-1), b++)
    ;
  return b;
}
int main() {
  int x = 0xfffeffff;
  printf("%d", bitcount(x));
  putchar('\n');
  printf("%d", bitcountAlt(x));
}
