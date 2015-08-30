/*=============================================================================
#     FileName: limits.c
#         Desc: Prints various limits
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-01 13:41:04
#      History:
=============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>  /* Note : Not mentioned in the book */

int
main(int argc, char **argv) {
    printf("\tmax int: %d\n \
            min int: %d\n \
            max flt: %f\n \
            min flt: %f\n \
            max dbl: %f\n \
            min dbl: %f\n", INT_MAX, INT_MIN, FLT_MAX,
                            FLT_MIN, DBL_MAX, DBL_MIN);
    return 0;
}
