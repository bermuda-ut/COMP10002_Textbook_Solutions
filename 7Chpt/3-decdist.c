/*=============================================================================
#     FileName: 3-decdist.c
#         Desc: to decending order 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-17 01:08:25
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void insert_sort(int A[], int size);
void int_swap(int *a, int *b);
int clean_list(int A[], int n);

int
main(int argc, char **argv) {
    int M[MAX], n, next, excess;

    printf("Type up to 10 integers: ");

    /*
    n = 0;
    while (n < 10 && scanf("%d", &M[n]) == 1) {
        n++;
    }
    */

    n = excess = 0;
    while (scanf("%d", &next) == 1) {
        if (n == MAX) {
            excess++;
        } else {
            M[n] = next;
            n++;
        }
    }
    printf("%d values read into array\n", n);
    if (excess) {
        printf("%d excess values discarded\n", excess);
    }

    printf("Values read:            ");
    int i;
    for(i=0; i<n; i++) {
        printf("%3d", M[i]);
    }
    printf("\n");

    insert_sort(M, n);

    printf("Sorted decending list:  ");
    for(i=0; i<n; i++) {
        printf("%3d", M[i]);
    }
    printf("\n");

    n = clean_list(M, n);

    printf("Cleaned decending list: ");
    for(i=0; i<n; i++) {
        printf("%3d", M[i]);
    }
    printf("\n");
    return 0;
}

void
insert_sort(int A[], int size) {
    int i, j;
    for (i=1; i<size; i++) {
        for (j=i-1; j>=0 && A[j+1]>A[j]; j--) {
            int_swap(&A[j], &A[j+1]);
        }
    }

}

void
int_swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int
clean_list(int A[], int n) {
    int i, S[n], new_size=1;
    S[0] = A[0];

    for(i=1; i < n; i++) {
        if (A[i] != A[i-1]) {
            S[new_size] = A[i];
            new_size++;
        }
    }
 
    for(i=0; i<new_size; i++) {
        A[i] = S[i];
    }
    return new_size;
}
