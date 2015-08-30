/*=============================================================================
#     FileName: 6-change.c
#         Desc: calculates change.
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-02 12:55:29
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv) {
    int amt;

    printf("Entre amount in cents: ");
    scanf("%d", &amt);
    printf("The coins requires to make %d cents are:\n", amt);
    while(amt > 0) {
        if (amt >= 50) {
            printf("50");
            amt -= 50;
        } else if (amt >= 20) {
            printf("20");
            amt -= 20;
        } else if (amt >= 10) {
            printf("10");
            amt -= 10;
        } else if (amt >= 5) {
            printf("5");
            amt -= 5;
        } else if (amt >= 2) {
            printf("2");
            amt -= 2;
        } else {
            printf("1");
            amt -= 1;
        }

        if (amt > 0)
            printf(", ");

    }

    printf("\n");
    return 0;
}
