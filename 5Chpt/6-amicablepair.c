/*=============================================================================
#     FileName: 6-amicablepair.c
#         Desc: determines if the pair entered is amicable.
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-13 02:42:38
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int isDivisible(int n, int div);
int sumFactors(int stop, int num);
int isAmicable(int x, int y);
void error(int code);

int
main(int argc, char **argv) {
    int x, y, isPair;

    printf("Enter two integers: ");
    if (scanf("%d %d",&x, &y) != 2) {
        error(0);
    }

    if (x <= 0 || y <= 0) {
        error(2);
    }

    isPair = isAmicable(x, y);
    if (isPair) {
        printf("%d and %d are amicable pairs.\n", x, y);
    } else {
        printf("%d and %d are not amicable pairs.\n", x, y);
    }

    return 0;
}

int
isAmicable(int x, int y) {
    if (sumFactors(x-1,x) == y && sumFactors(y-1,y) == x && x != y) {
        return 1;
    }
    return 0;
}

int
sumFactors(int stop, int num) {
    /*
     * Calculates sum of factors until 'stop'
     * */
    if (stop == 0) {
        return 0;
    }
    return (isDivisible(num, stop))*stop + sumFactors(stop-1, num);
}

int
isDivisible(int n, int div) {
    if (n == (n / div) * div) {
        return 1;
    }
    return 0;
}

void
error(int code) {
    if (code == 0) {
        printf("Illegal input.");
    } else if(code == 1) {
        printf("unknown error");
    } else if(code == 2) {
        printf("x and y must be positive.");
    }

    printf("\n");
    exit(EXIT_FAILURE);
}
