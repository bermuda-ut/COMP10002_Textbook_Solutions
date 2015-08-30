/*=============================================================================
#     FileName: 6-selecsort.c
#         Desc: selection sort 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-20 19:24:52
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

void selection_sort(int A[], int size);
void int_swap(int* a, int* b);
void rec_selection_sort(int A[], int size);

int
main(int argc, char **argv) {
    int mynums[1000], n=0, x, copynums[1000];

    printf("Type integers: ");

    while (scanf("%d", &mynums[n]) == 1) {
        n++;
    }

    for (x=0; x<n; x++) {
        copynums[x] = mynums[x];
    }

    printf("Iteration: ");
    selection_sort(mynums, n);
    
    for (x=0; x<n; x++) {
        printf("%d ", mynums[x]);
    }

    printf("\nRecursion: ");
    rec_selection_sort(copynums, n);
    for (x=0; x<n; x++) {
        printf("%d ", copynums[x]);
    }

    printf("\n");

    return 0;
}

void
selection_sort(int *A, int size) {
    int max, maxloc, i;

    while (size > 0) {
        max = A[0];
        maxloc = 0;

        for(i=1; i<size; i++) {
            if (A[i] > max) {
                max = A[i];
                maxloc = i;
            }
        }

        int_swap(&A[size-1], &A[maxloc]);
        size--;
    }
}

void 
rec_selection_sort(int A[], int size) {
    if (size >= 0) {
        int max, maxloc, i;
        max = A[size-1];
        maxloc = size-1;
        for(i=size-1; i>=0; i--) {
            if (A[i] > max) {
                max = A[i];
                maxloc = i;
            }
        }
        int_swap(&A[maxloc], &A[size-1]);
        rec_selection_sort(A, size-1);
    }
}

void
int_swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

