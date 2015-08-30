/*=============================================================================
#     FileName: 1-allzero.c
#         Desc:  
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-17 00:04:05
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int all_zero(int A[], int n);

int
main(int argc, char **argv) {
    int n, M[5], x;

    printf("Type value of 5 elements: ");
    x = 0;
    while (x < 5 && scanf("%d", &M[x]) == 1) {
        x++;
    }
    for(x=0; x<5; x++) {
        printf("M[%d] = %d\n", x, M[x]);
    }
    printf("Type value of n: ");
    scanf("%d", &n);


    if (all_zero(M, n)) {
        printf("All zero.\n");
    } else {
        printf("Not all zero.\n");
    }

    return 0;
}

int 
all_zero(int A[], int n) {
    /*
    int x;
    for(x=0; x<5; x++) {
        printf("A[%d] = %d\n", x, A[x]);
    }
    */
    while (n-1 >= 0) {
        printf("A[%d] = %d\n", n-1, A[n-1]);
        if (A[n-1] != 0) {
            return 0;
        }
        n--;
    }
    return 1;
}
