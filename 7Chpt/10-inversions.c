/*=============================================================================
#     FileName: 10-inversions.c
#         Desc: calculate inversions 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-22 18:45:29
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 1000

int calc_inv(int A[], int n);

int
main(int argc, char **argv) {
    int A[MAXVAL], n=0;

    printf("Type integers: ");
    while (scanf("%d", &A[n]) == 1) {
        n++;
    }

    printf("Invs: %d\n", calc_inv(A, n));

    return 0;
}

int
calc_inv(int A[], int n) {
    int i, inv=0;
    for(i=0; i<n-1; i++) {
        if(i > 0 && A[i] < A[i-1]) {
            printf("%d < %d\n",A[i], A[i-1]);
            /* check behind */
            inv++;
        }
        if(i < n-1 && A[i] > A[i+1]) {
            printf("%d > %d\n",A[i], A[i+1]);
            /* check infront */
            inv++;
        }
    }

    return inv;
}
