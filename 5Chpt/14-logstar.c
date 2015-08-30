/*=============================================================================
#     FileName: 14-logstar.c
#         Desc: log* algorithm 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-13 20:15:00
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double logstar(double number);

int
main(int argc, char **argv) {
    double x;

    printf("Type a value: ");
    scanf("%lf", &x);
    printf("log*%.2f = %.0f\n", x, logstar(x));

    return 0;
}

double
logstar(double number) {
    double newnumb = log(number) / log(2);
    if (newnumb < 0) {
        return 0;
    }
    return 1+logstar(newnumb);
}

