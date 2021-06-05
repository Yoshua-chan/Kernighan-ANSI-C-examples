#include <stdio.h>

int main() {
  int fahr, cels;
  int upper, lower, step;
  lower = 0;
  upper = 500;
  step = 10;
  fahr = lower;

  while(fahr <= upper) {
    cels = 5 * (fahr-32) / 9; //gdyby pomnożyć przez (5/9) wynik zostałby obcięty do zera
    printf("%d\t%d\n", fahr, cels);
    fahr = fahr + step;
  }
}
