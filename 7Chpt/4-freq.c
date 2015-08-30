/*=============================================================================
#     FileName: 4-freq.c
#         Desc: to decending order 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-27 18:34:25
=============================================================================*/
/* Could also : Read input > Sort Array > record freq*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void insert_sort(int A[], int B[], int size);
void int_swap(int *a, int *b);

int
main(int argc, char **argv) {
    int num[MAX], freq[MAX], n, next, excess, i=0, append, unique;

    printf("Type up to 1000 integers: ");

    n = excess = unique = 0;
    while (scanf("%d", &next) == 1) {
        if (n == MAX) {
            excess++;
        } else {
            append = 1;
            for (i=0; i<unique; i++) {
                /* Linear Search */
                if (next == num[i]) {
                    freq[i]++;
                    append = 0;
                    break;
                }
            }
            if (append) {
                num[i] = next;
                freq[i] = 1;
                unique++;
            }
            n++;
        }
    }

    printf("%d values read into array\n", n);
    if (excess) {
        printf("%d excess values discarded\n", excess);
    }

    insert_sort(num, freq, unique);

    printf("Value | Freq \n");
    for (i=0; i<unique; i++) {
        printf("%6d|%6d\n",num[i], freq[i]);
    }

    return 0;
}

void
insert_sort(int A[], int B[], int size) {
    int i, j;
    for (i=1; i<size; i++) {
        for (j=i-1; j>=0 && A[j+1]<A[j]; j--) {
            int_swap(&A[j], &A[j+1]);
            int_swap(&B[j], &B[j+1]);
        }
    }

}

void
int_swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
