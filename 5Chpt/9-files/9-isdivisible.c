/*=============================================================================
#     FileName: 9-isdivisible.c
#         Desc: Appraoch - quickly knock something off.
#               Recieves a integer input,
#                   returns if it is a perfecto number
#                   returns next perfect number.
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-13 19:30:47
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int
isDivisible(int n, int div) {
    if (n == (n / div) * div) {
        return 1;
    }
    return 0;
}

