/*=============================================================================
#     FileName: 8-intdiv.c
#         Desc:  
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-15 21:00:05
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

void int_divide(int numerator, int denominator, int *quotient, int *remainder);

int
main(int argc, char **argv) {
    int num, denom, quo, rem;

    printf("Enter Num/Denom: ");

    while (scanf("%d/%d", &num, &denom) == 2) {
        int_divide(num, denom, &quo, &rem);
        printf("> Numerator : %-3d\n> Denom     : %-3d\n> Quo       : %-3d\n\
> Rem       : %-3d\n",
                num, denom, quo, rem);
        printf("Enter Num/Denom: ");
    }

    printf("\n");
    return 0;
}

void
int_divide(int numerator, int denominator, int *quotient, int *remainder) {
    *quotient = numerator / denominator;
    *remainder = numerator - *quotient * denominator;
}
