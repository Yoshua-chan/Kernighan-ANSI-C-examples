#include <stdio.h>

#define ALLOCSIZE 100000
static char allocbuf[ALLOCSIZE];
static char* allocp = allocbuf;

char* alloc(int size) {
    if(allocbuf + ALLOCSIZE - allocp >= size) {
        allocp += size; //przesuń wskaźnik
        return allocp - size; //zwróć stary wskaźnik
    } else {
        return NULL;
    }
}

void afree(char* ptr) {
    if(ptr >= allocbuf && ptr < allocbuf + ALLOCSIZE)
        allocp = ptr;
}

int main() {
    int size  = 2137;
    int* ptr = (int*)alloc(size * sizeof(int));

    for(int i = 0; i < size; i++) {
        ptr[i] = i + 1;
    }
    /*for(int i = 0; i < size; i++) {
        printf("%d ", ptr[i]);
    }*/
    int size2 = 30;
    int* ptr2 = (int*)alloc(size2 * sizeof(int));
    for(int i = 0; i < 10; i++) {
        ptr2[i] = 69420 + i;
    }
    for(int i = 0; i < size + size2; i++) {
        printf("%d ", *((int*)allocbuf + i));
    }
}