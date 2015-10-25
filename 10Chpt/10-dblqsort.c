/*=============================================================================
#     FileName: 10-dblqsort.c
#         Desc: double qsort 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-10-25 02:56:55
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

#define INI_SIZE 2 /* 2 for testing purposes */

int double_cmp(const void* a, const void* b);

int
main(int argc, char **argv) {
    int n=0, size=INI_SIZE, i;
    double x, *list = malloc(INI_SIZE*sizeof(double));

    printf("Type Doubles: ");
    while(scanf("%lf", &x) == 1) {
        if(n+1 >= INI_SIZE) {
            size *= 2;
            list = realloc(list, size*sizeof(double));
        }
        list[n] = x;
        n++;
    }

    for(i=0; i<n; i++) {
        printf("%2.2f ", list[i]);
    }
    printf("\n");

    qsort(list, n, sizeof(double), double_cmp);

    for(i=0; i<n; i++) {
        printf("%.2f ", list[i]);
    }
    printf("\n");

    return 0;
}

int
double_cmp(const void *a, const void *b) {
    double result;
    if((result = *(double*)a - *(double*)b) < 0) {
        return -1;
    } else if(result > 0) {
        return 1;
    } else {
        return 0;
    }
}
