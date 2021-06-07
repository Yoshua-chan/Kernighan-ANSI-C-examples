/* Poziomy histogram długości znaków */
#include <stdio.h>
#include <stdbool.h>

int main() {
  int wl[20];
  int len = 0;
  int c;

  for(int i = 0; i < 20; i++) {
    wl[i] = 0;
  }

  while((c = getchar()) != EOF) {
    if((c == '\t' || c == '\n' || c == ' ') && len != 0) {
      ++wl[len - 1];
      len = 0;
    } else if(c >= '!' && c <= 125){
      len++;
    }
  }

  for(int i = 0; i < 20; i++) {

    printf("%3d|", i+1);
    for(int k = 0; k < wl[i]; k++) {
      putchar('-');
    }
    putchar('\n');
  }
}
