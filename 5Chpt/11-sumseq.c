/*=============================================================================
#     FileName: 11-sumseq.c
#         Desc: calculates sum of the sequence 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-13 19:52:27
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

double sum_sequence(int n);
int factorial(int n);
int supersum(int n);

int
main(int argc, char **argv) {
    int n;

    printf("Enter integer value: ");
    scanf("%d", &n);
    printf("%f\n", sum_sequence(n));

    return 0;
}

double
sum_sequence(int n) {
    double sum;
    while (n > 0) {
        sum += (double) supersum(n)/factorial(n);
        n--;
    }

    return sum;
}

int
factorial(int n) {
    if (n == 0) {
        return 1;
    }

    return n*factorial(n-1);
}

int
supersum(int n) {
    if (n == 0) {
        return 0;
    }

    return n+supersum(n-1);
}
