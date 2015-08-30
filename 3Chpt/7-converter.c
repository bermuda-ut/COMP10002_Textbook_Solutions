/*=============================================================================
#     FileName: 7-converter.c
#         Desc: Unit converter
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-05 08:13:16
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv) {
    double amt, conv;
    char unit, *newunit;

    printf("Entre amount with unit: ");
    if (scanf("%lf%c", &amt, &unit) != 2) {
        printf("Invalid Input\n");
        exit(EXIT_FAILURE);
    }
    if (unit == 'F') {
        conv = 5.0 * (amt - 32) / 9.0;
        newunit = "C";
        printf("The temperature %.1fF", amt);
    } else if (unit == 'C') {
        conv = 9.0 / 5.0 * amt + 32;
        newunit = "F";
        printf("The temperature %.1fC", amt);
    } else if (unit == 'M') {
        conv = 1.609 * amt;
        newunit = " kilometers";
        printf("The distance %.1f miles", amt);
    } else if (unit == 'K') {
        conv = amt / 1.609;
        newunit = " miles";
        printf("The distance %.1f kilometers", amt);
    } else if (unit == 'P') {
        conv = amt * 0.454;
        newunit = " kilograms";
        printf("The weight %.1f pounds", amt);
    } else if (unit == 'G') {
        conv = amt / 0.454;
        newunit = " pounds";
        printf("The weight %.1f kilograms", amt);
    } else {
        printf("Invalid Unit\n");
        exit(EXIT_FAILURE);
    }
    printf(" converts to %.1f%s\n", conv, newunit);

    return 0;
}
