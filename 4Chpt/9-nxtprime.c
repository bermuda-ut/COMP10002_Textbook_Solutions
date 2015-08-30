/*=============================================================================
#     FileName: 9-nxtprime.c
#         Desc:  
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-09 14:27:35
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int isprime(int n);

int
main(int argc, char **argv) {
    int n;

    printf("Enter integer: ");
    if(scanf("%d", &n) != 1) {
        exit(EXIT_FAILURE);
    }

    printf("Entered value %d\n", n);
    n++;
    while(isprime(n) == 0) {
        n++;
    }

    printf("Next prime    %d\n", n);

    return 0;
}

int
isprime(int n) {
    int div;
    for (div=2; div*div <= n; div++) {
        if (n%div == 0) {
            return 0;
        }
    }
    return 1;
}
