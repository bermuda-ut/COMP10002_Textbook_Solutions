/*=============================================================================
#     FileName: print.c
#         Desc: Fancy printing
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-01 14:09:09
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv) {
    int n;
    double x;
    char *m;

    n =      1234, x = 1234.4567, m = "hello        ";
    printf("n=%3d, x=%8.4f, m=\"%-15s\"\n", n, x, m);

    return 0;
}
