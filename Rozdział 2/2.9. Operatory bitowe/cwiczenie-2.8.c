/*
  Napisz funkcję rightrot(x, n), która zwraca wartość liczby całkowitej x przesunięto cyklicznie w prawo o n pozycji
  (usuuwane bity z prawej stroy mają zostać przeniesione na lewą)
*/

#include <stdio.h>


unsigned int rightrot(unsigned int x, unsigned int n) {
  int tmp = 0;
  for(unsigned int i = 0; i < n; i++) {
    tmp = (x & 1) * 0x80000000;
    x = x >> 1;
    x = x | tmp;
  }
  return x;
}


void printBits(int x) {
  for(int i = 1; i <= (int)sizeof(x)*8; i++) {
    printf("%d", (x >> (sizeof(x)*8 - i)) & 0b00000001);
    if(i % 8 == 0)
      putchar(' ');
  }
}

int main() {
  unsigned int x = 0b1101011010011101;
  printf("x:               ");
  printBits(x);
  putchar('\n');

  for(unsigned int i = 1; i <= 32U; i++) {
    printf("rightrot(x, %2u): ", i);
    printBits(rightrot(x, i));
    putchar('\n');
  }
}
