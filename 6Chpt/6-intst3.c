/*=============================================================================
#     FileName: 6-intst3.c
#         Desc:  
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-15 19:41:23
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

void int_sort2(int *pi, int *pi2);
void int_sort3(int *pi, int *pi2, int *pi3);

int
main(int argc, char **argv) {
    int n, x, y;

    printf("three numbers : ");
    scanf("%d %d %d", &n, &x, &y);
    printf("n = %p\n", &n);
    int_sort3(&n, &x, &y);

    printf("n=%d, x=%d, y=%d\n", n, x, y);
    printf("n = %p\n", &n);
    return 0;
}

void
int_sort2(int *pi, int *pi2) {
    if (*pi > *pi2) {
        int tmp;
        tmp = *pi;
        *pi = *pi2;
        *pi2 = tmp;
    }
}

void
int_sort3(int *pi, int *pi2, int *pi3) {
    printf("pi = %p\n", pi);
    int_sort2(pi, pi2);
    int_sort2(pi2, pi3);
    int_sort2(pi, pi2);
}
