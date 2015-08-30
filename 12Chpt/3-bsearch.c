/*=============================================================================
#     FileName: 3-bsearch.c
#         Desc: Binary Search 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-25 14:43:31
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

#define BFAIL    0
#define BSUCCESS 1

int mybsearch(int A[], int* key, int lo, int hi, int* loc);
int cmp(int* a, int* b);
int cmpfunc(const void * a, const void * b);

int
main(int argc, char **argv) {
    int A[1000], key, location, n;
    int *item;

    printf("Type up to 1000 integers: ");
    for(n=0; scanf("%d", &A[n]) == 1; n++);
    printf("\n%d values read.\n", n);

    printf("Type value to find: ");
    if(scanf("%d", &key) != 1) {
        printf("INVALID INPUT\n");
        exit(EXIT_FAILURE);
    }

    if(mybsearch(A, &key, 0, n, &location) == BSUCCESS) {
        printf("Found using mybsearch: Index %d\n", location);
    } else {
        printf("Could not find using mybsearch\n");
    }

    item = (int*) bsearch(&key, A, n, sizeof(int), cmpfunc);
    if(item != NULL) {
        printf("Found using bsearch: itemvalue %d\n", *item);
    } else {
        printf("Could not find using bsearch");
    }


    return 0;
}

int cmpfunc(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int
mybsearch(int A[], int* key, int lo, int hi, int* loc) {
    int mid, outcome;

    if(lo >= hi) {
        return BFAIL;
    }

    mid = (lo+hi)/2;
    if((outcome=cmp(key, A+mid)) < 0) {
        mybsearch(A, key, lo, mid, loc);
    } else if(outcome > 0) {
        mybsearch(A, key, mid+1, hi, loc);
    } else {
        *loc = mid;
        return BSUCCESS;
    }

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
