/*=============================================================================
#     FileName: 9-isperfect.c
#         Desc: Appraoch - quickly knock something off.
#               Recieves a integer input,
#                   returns if it is a perfecto number
#                   returns next perfect number.
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-13 19:30:53
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int sumFactors(int stop, int num);

int
isperfect(int n) {
    if (n == sumFactors(n-1, n)) {
        /* formula following definition of a perfect number */
        return 1;
    }
    return 0;
}
