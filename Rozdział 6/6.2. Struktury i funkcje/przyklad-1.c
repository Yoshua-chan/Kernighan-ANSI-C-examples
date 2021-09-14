#include <stdio.h>

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

struct point {
    int x;
    int y;
};

struct rect {
    struct point p1;
    struct point p2;
};

/* makepoint: przyjmuje dwa argumenty i tworzy na ich podstawie strukturę */
struct point makepoint(int x, int y) {
    struct point temp;

    temp.x = x;
    temp.y = y;

    return temp;
}

/* addpoints: dodaje dwa punkty */
struct point addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

/* ptinrect: sprawdza czy punkt znajduje się wewnątrz prostokąta */
/* funkcja zakłada, że prostokąt jest w postaci kanonicznej tj.
   koordynaty pierwszego punktu są mniejsze od odpowiadających
   drugiego */
int ptinrect(struct point pt, struct rect re) {
    return pt.x >= re.p1.x && pt.x <= re.p2.x 
        && pt.y >= re.p1.y && pt.y <= re.p2.y;
}

struct rect canonrect(struct rect re) {
    struct rect temp;

    temp.p1.x = min(re.p1.x, re.p2.x);
    temp.p1.y = min(re.p1.y, re.p2.y);

    temp.p2.x = max(re.p1.x, re.p2.x);
    temp.p2.y = max(re.p1.y, re.p2.y);

    return temp;
}

#define XMAX 1920
#define YMAX 1080

int main() {

    struct rect screen;
    screen.p1 = makepoint(0, YMAX);
    screen.p2 = makepoint(XMAX, 0);

    printf("screen\n");
    printf("p1: x - %d; y - %d\n", screen.p1.x, screen.p1.y);
    printf("p2: x - %d; y - %d\n", screen.p2.x, screen.p2.y);

    screen = canonrect(screen);

    printf("screen\n");
    printf("p1: x - %d; y - %d\n", screen.p1.x, screen.p1.y);
    printf("p2: x - %d; y - %d\n", screen.p2.x, screen.p2.y);

    struct point pt1 = makepoint(21, 37);
    if(ptinrect(pt1, screen))
        printf("point (%d;%d) is within the rectangle\n", pt1.x, pt1.y);
    else
        printf("point (%d;%d) is not withing the rectangle\n", pt1.x, pt1.y);
}