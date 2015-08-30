/*=============================================================================
#     FileName: 12-rewrrec.c
#         Desc: re-writing a recursion 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-13 20:02:50
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int t_rec(int n);
int t_itr(int n);

int
main(int argc, char **argv) {
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("rec: %d\nitr: %d\n", t_rec(n), t_itr(n));
    return 0;
}

int
t_rec(int n) {
    if (n<0) {
        return 0;
    }
    return n + t_rec(n-1);
}

int
t_itr(int n) {
    int sum, i;
    sum = 0;
    for (i=1; i<=n; i++) {
        sum += i;
    }
    return sum;
}
