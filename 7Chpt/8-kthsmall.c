/*=============================================================================
#     FileName: 8-kthsmall.c
#         Desc: return kth smallest int 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-22 18:16:29
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 1000

void insert_sort(int A[], int n);
void swap_data(int* a, int* b);
int kth_smallest(int A[], int n, int k);

int
main(int argc, char **argv) {
    int A[MAXVAL], n=0, k;

    printf("Enter Integers: ");
    while(scanf("%d", A+n) == 1) {
        n++;
    }
    
    int i;
    printf("A: ");
    for(i=0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");


    printf("Enter value of k: ");
    if(scanf("%d", &k) != 1) {
        printf("ERROR\n");
        exit(EXIT_FAILURE);
    }

    printf("kth smallest: %d\n", kth_smallest(A,n,k-1));

    printf("A: ");
    for(i=0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}

int
kth_smallest(int A[], int n, int k) {
    int B[n], i;

    for(i=0; i<n; i++) {
        B[i] = A[i];
    }

    insert_sort(B, n);

    printf("B: ");
    for(i=0; i<n; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    return B[k];
}

void
insert_sort(int A[], int n) {
    int i, j;

    for(i=0; i<n; i++) {
        for(j=i-1; j>=0 && A[j] > A[j+1]; j--) {
            swap_data(A+j, A+j+1);
        }
    }
}

void
swap_data(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
