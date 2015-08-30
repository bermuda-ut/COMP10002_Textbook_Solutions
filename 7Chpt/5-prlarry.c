/*=============================================================================
#     FileName: 5-prlarry.c
#         Desc: parallel array fun
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-20 18:52:05
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

void para_insert_sort(int* pri, int* sec, int size);
void swap_int(int* val1, int* val2);

int
main(int argc, char **argv) {
    int stdnum[1000], stdmrk[1000], n;

    n = 0;
    printf("Enter Student Number and Grade\n");
    while (scanf("%d %d", &stdnum[n], &stdmrk[n]) == 2) {
        n++;
    }
    /* n is now size of inputs */

    para_insert_sort(stdnum, stdmrk, n);

    int i;
    for(i=0; i<n; i++) {
        printf("%5d %3d\n", stdnum[i], stdmrk[i]);
    }

    return 0;
}

void
para_insert_sort(int pri[], int sec[], int size) {
    int i, j;
    for(i=1; i<size; i++) {
        for (j=i-1; j>=0 && pri[j+1] < pri[j]; j--) {
            swap_int(&pri[j], &pri[j+1]);
            swap_int(&sec[j], &sec[j+1]);
        }
    }
}

void
swap_int(int* val1, int* val2) {
    int temp;
    temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}
