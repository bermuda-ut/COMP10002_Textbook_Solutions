/*=============================================================================
#     FileName: simplecalc1.c
#         Desc: Calculate addition
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-31 00:19:32
#      History:
=============================================================================*/
#include <stdio.h>

int
main(int argc, char **argv) {
    int sum;
    int next;

    sum = 0;

    while(scanf("%d", &next) == 1) {
        sum += next;
    }


    printf("sum = %d\n", sum);
    return 0;
}
