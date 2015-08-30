/*=============================================================================
#     FileName: 9-error.c
#         Desc: Appraoch - quickly knock something off.
#               Recieves a integer input,
#                   returns if it is a perfecto number
#                   returns next perfect number.
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-13 19:30:42
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

void
error(int code) {
    if (code == 0) {
        printf("Illegal input.");
    } else if(code == 1) {
        printf("Internally, numbers got too big dawg.");
    } else if(code == 2) {
        printf("n must be positive.");
    }

    printf("\n");
    exit(EXIT_FAILURE);
}
