/*=============================================================================
#     FileName: 9-nextperfect.c
#         Desc: Appraoch - quickly knock something off.
#               Recieves a integer input,
#                   returns if it is a perfecto number
#                   returns next perfect number.
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-13 19:31:07
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int isperfect(int n);
int error(int code);

int
nextperfect(int n) {
    n++;
    while (!isperfect(n)) {
        n++;
        if (n > 10000) {
            error(1);
        }
    }
    return n;
}
