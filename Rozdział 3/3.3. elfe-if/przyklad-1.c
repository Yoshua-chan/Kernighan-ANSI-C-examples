/* binsearch: znajduje x v tablicy o długości n */
#include <stdio.h>

int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while(low <= high) {
    mid = (low+high)/2;
    if (x > v[mid])
      low = mid + 1;
    else if(x < v[mid])
      high = mid - 1;
    else
      return mid;
  }
  return -1;
}
int main() {
  int tab[16] = {1, 3, 5, 6, 6, 7, 9, 12, 13, 17, 25, 31, 32, 42, 59, 64 };

  printf("%d", binsearch(42, tab, 15));
}
