/*
bitcount: zlicza bity o wartości 1 w zmiennej x
*/

#include <stdio.h>

int bitcount(unsigned int x) { /*Deklaracja unsigned sprawia, że przy przesuwaniu w prawo
                                 nowe bity zawsze będą zerami niezależnie od tego jak komputer
                                 przechowuje bity znaku */
  int b;

  for(b = 0; x != 0; x >>= 1)
    if(x & 0x1U)
      b++;
  return b;
}

int main() {
  printf("%d", bitcount(0b1111U));
}
