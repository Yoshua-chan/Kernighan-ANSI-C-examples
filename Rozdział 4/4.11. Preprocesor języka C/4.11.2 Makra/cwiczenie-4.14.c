#include <stdio.h>

#define swap(type, x, y) { \
type temp = x; \
x = y; \
y = temp; \
}

#define SQUARE(x) x * x

int main() {
    int x = 37, y = 21;
    swap(int, x, y);
    printf("%d %d\n", x, y);
}