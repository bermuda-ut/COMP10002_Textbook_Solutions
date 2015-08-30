/*=============================================================================
#     FileName: 5-daynumb.c
#         Desc: Calculates day number in a year.
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-06 17:43:29
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

#define LONGMONTH  31
#define SHORTMONTH 30
#define LONGFEB    28
#define SHORTFEB   29
#define FEB        2
#define AUG        8
#define DEC        12

int
calc_days(int month, int year) {
    if(month == FEB) {
        if (year%4)
            return SHORTFEB;
        if (!(year%100) && (year%400))
            return SHORTFEB;
        return LONGFEB;
    } else if(month < AUG) {
        if (month%2)
            return LONGMONTH;
        else
            return SHORTMONTH;
    } else if (month <= DEC) {
        if (month%2)
            return SHORTMONTH;
        else
            return LONGMONTH;
    }
    return 0;
}

int
main(int argc, char **argv) {
    int date, month, year, dInMonth, daynumb;

    printf("Type DD/MM/YYYY: ");

    if (scanf("%d/%d/%d", &date, &month, &year) != 3) {
        printf("Invalid Input.\n");
        exit(EXIT_FAILURE);
    }

    dInMonth = calc_days(month, year);

    if (dInMonth == 0) {
        printf("Invalid date.\n");
        exit(EXIT_FAILURE);
    }
    else if (date > dInMonth || date <= 0) {
        printf("Invalid date.\n");
        exit(EXIT_FAILURE);
    }

    daynumb = date;
    int i;
    for (i = month-1; i > 0; i--) {
        /* printf("adding month %d days %d\n", i, calc_days(i)); */
        daynumb += calc_days(i, year);
    }

    printf("%02d/%02d/%04d is day number %d in the year.\n", date, month, year, daynumb);

    if (year <= 1753) {
        printf(">This information is not accurate due to Gregorian Date thingy.\n");
    }

    return 0;
}
