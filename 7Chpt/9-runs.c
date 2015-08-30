/*=============================================================================
#     FileName: 9-runs.c
#         Desc: array fun 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-22 18:44:58
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 1000

int calc_runs(int A[], int n);

int
main(int argc, char **argv) {
    int A[MAXVAL], n=0;

    printf("Type integers: ");
    while (scanf("%d", &A[n]) == 1) {
        n++;
    }

    printf("Runs: %d\n", calc_runs(A, n));

    return 0;
}

int
calc_runs(int A[], int n) {
    int total=0, i, j;
    for(i=0; i<n; i++) {
        for(j=i+1; j<n && A[i] < A[j]; j++) {
            i++;
        }
        total++;
    }
    return total;
}
