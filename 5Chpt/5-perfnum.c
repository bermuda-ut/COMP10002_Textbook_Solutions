/*=============================================================================
#     FileName: 5-perfnum.c
#         Desc: Appraoch - quickly knock something off.
#               Recieves a integer input,
#                   returns if it is a perfecto number
#                   returns next perfect number.
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-13 02:37:59
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int isperfect(int n);
int isDivisible(int n, int div);
int sumFactors(int stop, int num);
int nextperfect(int n);
void error(int code);

int
main(int argc, char **argv) {
    int n, nIsPerfect, nextPerfectNum;

    printf("Enter a integer: ");
    if (scanf("%d",&n) != 1) {
        error(0);
    }

    if (n <= 0) {
        error(2);
    }

    nIsPerfect = isperfect(n);
    if (nIsPerfect) {
        printf("%d is a perfect number.\n", n);
    } else {
        printf("%d is not a perfect number.\n", n);
    }

    nextPerfectNum = nextperfect(n);

    printf("Next perfect number is %d\n", nextPerfectNum);

    return 0;
}

int
isperfect(int n) {
    if (n == sumFactors(n-1, n)) {
        /* formula following definition of a perfect number */
        return 1;
    }
    return 0;
}

int
nextperfect(int n) {
    n++;
    while (!isperfect(n)) {
        n++;
        if (n > 10000) {
            error(1);
        }
    }
    return n;
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
        printf("Internally, numbers got too big dawg.");
    } else if(code == 2) {
        printf("n must be positive.");
    }

    printf("\n");
    exit(EXIT_FAILURE);
}
