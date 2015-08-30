/*=============================================================================
#     FileName: 10-saving.c
#         Desc:  
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-13 19:37:44
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>
/* DO not understand accounting stuff
 * Posponed for now!                  */

double savings_plan(double initial, double amount, double ann_rate, int years);

int
main(int argc, char **argv) {
    double ini, amt, ann;
    int yr;

    printf("Enter number of years    : ");
    scanf("%d", &yr);
    printf("Enter annual rate %%      : ");
    scanf("%lf", &ann);
    printf("Enter monthly amount     : $");
    scanf("%lf", &amt);
    printf("Enter initial balance    : $");
    scanf("%lf", &ini);

    printf("Saving $%.2f plus $%.2f per month for %d years\n", ini, amt, yr);
    int i;
    for (i = -1; i<2; i++) {
        double newrate = ann + i;
        printf("        at %.2f%% per year: %.2f\n", newrate, savings_plan(ini, amt, newrate, yr));
    }
    return 0;
}

double
savings_plan(double initial, double amount, double ann_rate, int years) {
    int month;
    double monthly_mult, balance = initial;
    monthly_mult = 1.00 + (ann_rate/100.0)/12;

    for (month = 1; month <= 12*years; month++) {
        balance *= monthly_mult;
        balance += amount;
    }

    return balance;
}
