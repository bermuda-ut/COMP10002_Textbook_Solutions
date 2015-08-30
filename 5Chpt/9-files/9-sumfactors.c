/*=============================================================================
#     FileName: 9-sumfactors.c
#         Desc: Appraoch - quickly knock something off.
#               Recieves a integer input,
#                   returns if it is a perfecto number
#                   returns next perfect number.
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-13 19:31:12
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int isDivisible(int n, int div);

int
sumFactors(int stop, int num) {
    /*
     * Calculates sum of factors until 'stop'
     * */
    if (stop == 0) {
        return 0;
    }
    return (isDivisible(num, stop))*stop + sumFactors(stop-1, num);
}
