/*=============================================================================
#     FileName: 13-mystr.c
#         Desc: my strlen&strcat 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-23 20:55:32
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mystrlen(char *s);
char* mystrcat(char *dest, char *src);

int
main(int argc, char **argv) {
    char str[500], str2[500], cp[500];

    printf("Enter string, enter to end: ");
    scanf("%[^\n]%*c", str);
    printf("String: %s\n", str);

    int size = strlen(str);
    printf("strlen  : %d\n", size);
    printf("mystrlen: %d\n", mystrlen(str));

    printf("Enter string2, Ctrl-D to end: ");
    int i=0;
    for(i=0;(str2[i] = getchar()) != EOF;i++);
    str2[i] = '\0';
    printf("\nString: %s\n", str2);

    strcpy(cp, str);

    printf("strat   : %s\n", strcat(str, str2));
    printf("mystrat : %s\n", mystrcat(cp, str2));
    return 0;
}

int
mystrlen(char *s) {
    int i, len=0;
    for(i=0; s[i] != '\0'; i++) {
        len++;
    }
    return len;
}

char*
mystrcat(char *dest, char *src) {
    int destlen = mystrlen(dest), i;
    for(i=0; src[i] != '\0'; i++) {
        dest[destlen+i] = src[i];
    }
    dest[destlen+i] = '\0';
    return dest;
}
