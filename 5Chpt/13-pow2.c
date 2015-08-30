/*=============================================================================
#     FileName: 13-pow2.c
#         Desc: raises power
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-13 20:12:53
#      History: lol
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int int_pow(int base, int power);
int int_pow_rec(int base, int power);

int
main(int argc, char **argv) {
    int n, x;

    printf("Enter two integer with space inbtwn: ");
    if (scanf("%d %d", &n, &x) != 2) {
        printf("illegal input\n");
        exit(EXIT_FAILURE);
    }

    printf("Iterative : %d^%d = %d\n", n, x, int_pow(n, x));
    printf("Recursive : %d^%d = %d\n", n, x, int_pow_rec(n, x));
    return 0;
}

int
int_pow(int base, int power) {
    int answer=1;
    while (power > 0) {
        answer *= base;
        power--;
    }
    return answer;
}

int
int_pow_rec(int base, int power) {
    if (power == 0) {
        return 1;
    }

    return base * int_pow_rec(base, power-1);
}
