/*=============================================================================
#     FileName: 1-prec.c
#         Desc: precidence test
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-01 14:29:53
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv) {
    int n = (1 && - 2 * - 3 - 4 < 5 && 6 <= 7 >= 8 != 9 / 10 > ! 11);
    printf("n=%d\n", n);

    return 0;
}
