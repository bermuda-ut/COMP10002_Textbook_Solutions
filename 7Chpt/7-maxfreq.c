/*=============================================================================
#     FileName: 7-maxfreq.c
#         Desc: takes int array
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-22 15:49:48
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_VALS 1000

int max_freq(int A[], int n);
void quick_sort(int A[], int B[], int n);
void partition(int A[], int B[], int n, int* pivot, int* first_eq, int* first_gt);
void swap_data(int *a, int *b);
int cmp(int* a, int* b);

int
main(int argc, char **argv) {
    int A[1000], n=0, mostfreq;

    printf("Type some integers: ");

    while (scanf("%d", &A[n]) == 1) {
        n++;
    }

    mostfreq = max_freq(A, n);
    printf("Most frequent value is %d\n", mostfreq);

    return 0;
}

int
max_freq(int A[], int n) {
    int value[MAX_VALS], freq[MAX_VALS], i, j, k=0, found, chosen;

    for(i=0; i<n; i++) {
        found = 0;
        for(j=0; j<k; j++) {
            if(value[j] == A[i]) {
                found = 1;
                break;
            }
        }

        if (found) {
            freq[j]++;
        } else {
            assert (j == k);
            freq[k] = 1;
            value[k] = A[i];
            k++;
        }
    }

    n=k;

    for (i=0; i<n; i++) {
        printf("%3d %3d\n", value[i], freq[i]);
    }

    printf("sortingnow\n");

    quick_sort(freq, value, n);

    for (i=0; i<n; i++) {
        printf("%3d %3d\n", value[i], freq[i]);
    }

    found = value[n-1];
    chosen = n-1;

    for(i=chosen-1; i >= 0  && freq[chosen] == freq[i]; i--) {
        if (value[i] < found) {
            found = value[i];
        }
    }

    return found;

}

void
quick_sort(int A[], int B[], int n) {
    int p, fe, fg;

    if (n<=0) {
        return;
    }
    p = A[n/2];
    partition(A, B, n, &p, &fe, &fg);
    quick_sort(A, B, fe);
    quick_sort(A+fg, B+fg, n-fg);
}

void
partition(int A[], int B[], int n, int* pivot, int* first_eq, int* first_gt) {
    int next=0, fe=0, fg=n, outcome;
    while (next<fg) {
        if ((outcome = cmp(&A[next], pivot)) < 0) {
            /* to the left side!*/
            swap_data(&A[next], &A[fe]);
            swap_data(&B[next], &B[fe]);
            fe++;
            next++;
        } else if(outcome > 0) {
            /* to the right side!*/
            fg--;
            swap_data(&A[next], &A[fg]);
            swap_data(&B[next], &B[fg]);
        } else {
            next++;
        }
    }

    *first_eq = fe;
    *first_gt = fg;
}

void 
swap_data(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int
cmp(int* a, int* b) {
    if(*a < *b) {
        return -1;
    } else if(*a > *b) {
        return 1;
    }
    return 0;
}
