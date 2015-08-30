/*=============================================================================
#     FileName: 14-myatoi.c
#         Desc: myatoi 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-23 22:21:53
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myatoi(char* str);

int
main(int argc, char **argv) {
    char chr[1000];
    int i;

    printf("Type string: ");
    for(i=0; scanf("%c", &chr[i])==1; i++);
    chr[i] = '\0';
    printf("\n");
    printf("char=%s\natoi=%d\nmyatoi=%d\n", chr, atoi(chr), myatoi(chr));

    return 0;
}

int
myatoi(char* str) {
    /* int a = (int) *str; 
     * return a;
     * Apparently I had wrong idea of conversion lol */
    int i, j, myint=0, len=0, mult;
    for(len=0; str[len] <= '9' && str[len] >= '0'; len++);

    for(i=0; str[i] <= '9' && str[i] >= '0'; i++) {
        mult = 1;
        for(j=1; j<len-i; j++) {
            mult *= 10;
        }
        myint += mult*(str[i] - '0');
    }

    return myint;
}
