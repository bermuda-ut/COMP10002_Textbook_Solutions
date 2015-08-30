/*=============================================================================
#     FileName: 7-myctype.c
#         Desc:  
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-13 18:50:30
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int myisupper(char c);
int myislower(char c);

int
main(int argc, char **argv) {
    char c;

    printf("Type a letter: ");
    scanf("%c", &c);
    printf("%d\n", c);

    if (myisupper(c)) {
        printf("Capital letter\n");
    } else {
        printf("Not a capital letter\n");
    }
    if (myislower(c)) {
        printf("Small letter\n");
    } else {
        printf("Not a small letter\n");
    }

    return 0;
}

int
myisupper(char c) {
    if (c >= 'a' && c <= 'z') {
        return 0;
    }
    return 1;
}

int
myislower(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    return 0;
}
