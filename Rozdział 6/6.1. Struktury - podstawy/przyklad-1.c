#include <stdio.h>

/* przykład struktury przedstawiający 
punkt o współrzędnych x i y */

struct point {
    int x;
    int y;
};

struct point maxpt = {21, 37};

struct rectangel {
    struct point p1;
    struct point p2;
};

int main() {
    printf("%d", maxpt.x);
}