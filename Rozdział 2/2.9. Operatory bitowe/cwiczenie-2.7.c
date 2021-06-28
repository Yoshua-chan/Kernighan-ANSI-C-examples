/*
  Napisz funkcję invert(x, p, n), która zwraca wartość x po zamianie zer na jedynki
  i na odwrót w n bitach począwszy od pozycji p
*/

#include <stdio.h>


int invert(int x, int p, int n) {
  int mask = ~0;
  mask = mask >> (n + p - 1);
  mask = mask << n;
  mask = ~(mask);
  mask = mask << (p - 1);

  //int tmp = ~(~x & mask) & mask;
  //int tmp = mask & x;
  int y = ~x;
  x = x & ~mask;
  y = y & mask;

  return (x | y);
}


void printBits(int x) {
  for(int i = 1; i <= (int)sizeof(x)*8; i++) {
    printf("%d", (x >> (sizeof(x)*8 - i)) & 0b00000001);
    if(i % 8 == 0)
      putchar(' ');
  }
}

int main() {
  int x = 0b1101011010011101;
  printf("x:             ");
  printBits(x);
  putchar('\n');
  printf("invert(x,3,6): ");
  printBits(invert(x, 3, 6));
}
