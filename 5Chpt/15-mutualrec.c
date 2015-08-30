/*=============================================================================
#     FileName: 15-mutualrec.c
#         Desc:  
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-13 20:28:24
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int eeee(int n);
int oooo(int n);

int
main(int argc, char **argv) {
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);
    printf("eeee : %d\noooo : %d\n", eeee(n), oooo(n));
    return 0;
}

int
eeee(int n) {
    if (n==0) {
        return 1;
    }
    return oooo(n-1);
}

int
oooo(int n) {
    if (n==0) {
        return 0;
    }
    return eeee(n-1);
}
