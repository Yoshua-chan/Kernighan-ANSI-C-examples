#include <stdio.h>
#include <stdlib.h>

static char daytab[2][13]= {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
    int i, leap;

    leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);

    if(day > daytab[leap][month] && month > 0 && month < 13) { //error checking
        fprintf(stderr, "error: indalid date, there are only %d days in %d month\n", daytab[leap][month], month);
        exit(1);
    } else if(month > 12) {
        fprintf(stderr, "error: invalid date, month=%d\n",month);
        exit(1);
    }

    for(i = 0; i < month; i++)
        day += daytab[leap][i]; //dodaj dni poprzednich miesięcy
    return day;
}

void month_day(int year, int yearday, int* monthptr, int* dayptr) {
    int i, leap;

    leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);

    if(yearday < 1) { //error checking
        fprintf(stderr, "error: invalid date, yearday=%d\n", yearday);
        exit(1);
    } else if(!leap && yearday > 365) {
        fprintf(stderr ,"error: invalid date, there are only 365 days in year %d\n", year);
        exit(1);
    } else if(leap && yearday > 366) {
        fprintf(stderr, "error: invalid date, there are only 366 days in year %d\n", year);
        exit(1);
    }


    for(i = 0; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *monthptr = i;
    *dayptr = yearday;

}


int main() {
    int c;
    printf("%d\n", (c = day_of_year(2020, 12, 20)));
    int month;
    int day;
    month_day(2013, 366, &month, &day);
    printf("month: %d, day: %d\n", month, day);
}
