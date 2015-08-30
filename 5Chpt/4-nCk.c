/*=============================================================================
#     FileName: 4-nCk.c
#         Desc: calculates nCk
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-13 01:40:51
#      History: lol
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int factorial(int x);
int n_choose_k(int n, int k);
void error(int code);

int
main(int argc, char **argv) {
    int n, x;

    printf("Enter two integer with space inbtwn: ");
    if (scanf("%d %d", &n, &x) != 2) {
        error(0);
    }
    if (n < x) {
        error(1);
    }

    printf("%dC%d = %d\n", n, x, n_choose_k(n, x));
    return 0;
}

int
factorial(int x) {
    if (x == 1) {
        return 1;
    }

    return x*factorial(x-1);
}

int
n_choose_k(int n, int k) {
return (factorial(n)/(factorial(n-k)*factorial(k)));
}

void
error(int code) {
    if (code == 0) {
        printf("illegal input\n");
    } else if (code == 1) {
        printf("fucking impossible\n");
    }
    exit(EXIT_FAILURE);
}
