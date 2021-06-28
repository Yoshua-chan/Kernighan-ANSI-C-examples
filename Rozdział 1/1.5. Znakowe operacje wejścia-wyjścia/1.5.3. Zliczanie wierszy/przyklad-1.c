#include <stdio.h>

int main() {
  int c, nl;
  nl = 0;

  while((c = getchar()) != EOF) {
    if(c == '\n') {
      nl++;
    }
  }
  /* program zakłada, że każda linia jest zakończona znakiem \n, co być moze jest konwencją
    lecz możliwe jest napisanie programu którego ostatnia linijka nie będzie zakończona \n
    i liczba wierszy nie będzie prawidłowa

    gnu wc ma ten sam problem xDDDDDD */
  printf("%d\n", nl);
}
