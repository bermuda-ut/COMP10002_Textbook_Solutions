/*=============================================================================
#     FileName: 4-dmy.c
#         Desc: Calculate tomorrow's date 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-06 17:40:54
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int
calc_days(int month, int year) {
    if(month == 2) {
        if (year%4)
            return 28;
        if (!(year%100) && (year%400))
            return 28;
        return 29;
    } else if(month < 8) {
        if (month%2)
            return 31;
        else
            return 30;
    } else if (month < 13) {
        if (month%2)
            return 30;
        else
            return 31;
    } else {
        return 0;
    }
}
int
main(int argc, char **argv) {
    int date, month, year, dInMonth;

    printf("Type DD/MM/YYYY: ");
    scanf("%d/%d/%d", &date, &month, &year);

    dInMonth = calc_days(month, year);
    if (dInMonth == 0) {
        printf("Invalid Date.\n");
        return 0;
    }

    if (date > dInMonth) {
        printf("Invalid date.\n");
        return 0;
    }

    printf("Date read: %02d/%02d/%04d\n", date, month, year);

    if (date == dInMonth) {
        date = 1;
        month ++;
        if (month > 12) {
            month = 1;
            year++;
        }
    } else {
        date++;
    }

    printf("Tomorrow: %02d/%02d/%04d\n", date, month, year);

    if (year <= 1753) {
        printf(">This information is not accurate due to Gregorian Date thingy.\n");
    }

    return 0;
}
