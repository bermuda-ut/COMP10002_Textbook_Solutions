/*=============================================================================
#     FileName: 5-intst.c
#         Desc:  
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-15 19:18:30
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

void int_sort2(int *pi, int *pi2);

int
main(int argc, char **argv) {
    int n, x;

    printf("two numbers : ");
    scanf("%d %d", &n, &x);
    int_sort2(&n, &x);

    printf("n=%d, x=%d\n", n, x);
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
