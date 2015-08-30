/*=============================================================================
#     FileName: 8-floataccu.c
#         Desc: playing with float number accuracy 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-13 19:26:00
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

#define CUBE_LOWER 1e-6
#define CUBE_UPPER 1e+6
#define CUBE_ITERATIONS 25

double cube_root(double v);
int near_equal(double x1, double x2);

int
main(int argc, char **argv) {
    double x;

    printf("Enter a number : ");
    while (scanf("%lf", &x) == 1) {
        printf("> cube root is %.3f\n", cube_root(x));
        printf("Enter a number : ");
    }

    printf("\n");
    return 0;
}

int
near_equal(double x1, double x2) {
    double differ;
    if (x1 < x2) {
        double temp;
        temp = x1;
        x1 = x2;
        x2 = temp;
    }
    differ = x1 - x2;
    if (differ != 0) {
        if (differ / x1 > 0.0001)  {
            return 0;
        }
    }
    return 1;
}

double
cube_root(double v) {
    double next = 1.0;
    int loops = 0;
    if (v < CUBE_LOWER || v > CUBE_UPPER) {
        printf("WARNING: cube root may be inaccurate\n");
    }
    while(!near_equal(v, next*next*next)) {
        next = (2*next + v/(next*next)) / 3;
        loops++;
    }

    printf("> looped %d times\n", loops);

    return next;
}
