#include <stdio.h>

/* month_name - zwraca wskaźnik do stringa z nazwą miesiąca */
char* month_name(int n) {
    static char* name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };
    
    return (n < 1 || n > 12 ? name[0] : name[n]);
}

int main() {
    printf("%s", month_name(3));
    return 0;
}