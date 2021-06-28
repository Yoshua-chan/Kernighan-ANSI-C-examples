/*
 Napisz funkcję setbits(x, p, n, y), która przypisuje n bitom liczby x począwszy od pozycji p, 
 wartości n prawostronnych bitów (wartości?) y, pozostawiając pozostałe bity x niezmienione, i zwraca wynik
*/

#include <stdio.h>


int setbits(int x, int p, int n, int y) {
  int mask = ~0;
  mask = mask >> (n + p - 1);
  mask = mask << n;
  mask = ~(mask);
  mask = mask << (p - 1);

  //int tmp = ~(~x & mask) & mask;
  //int tmp = mask & x;
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
  int y = 0b0110110111100110;
  printBits(setbits(x, 3, 6, y));
}
