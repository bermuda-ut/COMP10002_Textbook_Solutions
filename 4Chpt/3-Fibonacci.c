/*=============================================================================
#     FileName: 3-Fibonacci.c
#         Desc: Fibonacci number fun 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-07 14:04:11
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10000000

int
main(int argc, char **argv) {
    int days, sum, prev1, prev2, now;
    
    printf("Enter number of days: ");

    if (scanf("%d", &days) == 1) {
        int i;
        prev1 = 0;
        prev2 = 1;
        now = 0;

        for(i=1; i<days; i++) {
            now = (prev1+prev2);
            prev2 = prev1;
            prev1 = now;
            sum += now;
            if (sum > LIMIT) {
                printf("Too big man wtf.\n");
                exit(EXIT_FAILURE);
            }
        }
    } else {
        printf("Invalid input.\n");
        exit(EXIT_FAILURE);
    }

    printf("SUM = %d\n", sum);

    return 0;
}
