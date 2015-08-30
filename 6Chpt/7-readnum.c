/*=============================================================================
#     FileName: 7-readnum.c
#         Desc:  
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-15 20:25:35
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

#define READ_OK 0
#define READ_ERROR 1

int read_num(int lo, int hi, int *num);

int
main(int argc, char **argv) {
    int low, high, out;

    printf("Enter a range (ex. 1-10): ");
    if (scanf("%d-%d",&low, &high) != 2) {
        printf("Incorrect format.\n");
        exit(EXIT_FAILURE);
    }

    if (low > high) {
        printf("Do you even count brah?\n");
        exit(EXIT_FAILURE);
    }
    if (read_num(low, high, &out) != READ_OK) {
        printf("Unrecoverable error\n");
        exit(EXIT_FAILURE);
    }

    printf("out = %d\n", out);

    return 0;
}

int
read_num(int lo, int hi, int *num) {
    int next;
    printf("enter a number between %d and %d inclusive: ",
            lo, hi);
    while (scanf("%d", &next) == 1) {
        if (lo <= next && next <= hi) {
            *num = next;
            return READ_OK;
        }
        printf("%d is not btween %d and %d\ntry again: ",
                next, lo, hi);
    }
    return READ_ERROR;
}
