#include <stdio.h>

int main() {
  float cels, fahr;
  int min, max, step;
  min = -50;
  max = 200;
  step = 10;
  cels = min;

  while(cels <= max) {
    fahr = (9.0/5.0) * cels + 32;
    printf("%3.0f %6.1f\n", cels, fahr);
    cels += step;
  }
}
