/*=============================================================================
#     FileName: 8-mymax.c
#         Desc:  
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-09 14:16:35
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

#define PERLINE 5

int
main(int argc, char **argv) {
    int nmax, max, cycles, n, maxcycle, maxseed;
    
    printf("Enter max value for n: ");
    if (scanf("%d", &nmax) != 1) {
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }

    maxcycle = 0;

    int x;
    for(x=2; x<nmax; x++) {
        max = n = x;
        cycles = 0;
        printf("--%03d----------\n", x);
        while (n>1) {
            printf("%7d", n);

            if(n%2 == 0) {
                n = n/2;
            } else {
                n = 3*n+1;
            }
            if (n>max) {
                max = n;
            }

            cycles++;
            if (cycles%PERLINE == 0) {
                printf("\n");
            }
        }

        if (cycles > maxcycle) {
            maxcycle = cycles;
            maxseed = x;
        }
        printf("\n%d cycles consumed, maximum was %d\n\n", cycles, max);
    }

    printf("\nMax cycle: %d, seed: %d\n", maxcycle, maxseed);
    return 0;
}
