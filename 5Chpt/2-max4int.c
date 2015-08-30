/*=============================================================================
#     FileName: 2-max4int.c
#         Desc:  
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-13 01:28:43
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int max_2_ints(int first, int second);
int max_4_ints(int a, int b, int c, int d);
void error(int code);

int
main(int argc, char **argv) {
    int n, x, y, z;

    printf("Type first number: ");
    if (scanf("%d", &n) != 1) {
        error(0);
    }
    printf("Type second number: ");
    if (scanf("%d", &x) != 1) {
        error(0);
    }
    printf("Type third number: ");
    if (scanf("%d", &y) != 1) {
        error(0);
    }
    printf("Type fourth number: ");
    if (scanf("%d", &z) != 1) {
        error(0);
    }
    printf("Bigger number is %d\n", max_4_ints(n, x, y, z));

    return 0;
}

int
max_2_ints(int first, int second) {
    if (first > second) {
        return first;
    }
    return second;
}

int
max_4_ints(int a, int b, int c, int d) {
    return max_2_ints(max_2_ints(a,b),max_2_ints(c,d));
}

void
error(int code) {
    if (code == 0) {
        printf("Illegal input\n");
    }
    exit(EXIT_FAILURE);
}
