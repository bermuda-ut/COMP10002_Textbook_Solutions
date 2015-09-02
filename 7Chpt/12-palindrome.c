/*=============================================================================
#     FileName: 12-palindrome.c
#         Desc: calculate palindrome 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-22 19:45:33
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int is_palindrome(char* str);

int
main(int argc, char **argv) {
    int ispalin=0, i;
    char mystr[1000];

    printf("Type string sir (Ctr-D x 2 to end): ");
    i=0;
    while(scanf("%c", &mystr[i]) == 1) {
        i++;
    }
    mystr[i] = '\0';
    printf("\n");

    ispalin = is_palindrome(mystr);

    if (ispalin) {
        printf("It is :)\n");
    } else {
        printf("It isn't :(\n");
    }

    return 0;
}

int
is_palindrome(char* str) {
    int i, len;
    char cleaned[1000];
    char inved[1000];

    for(len=i=0; str[i] != '\0'; i++) {
        if(str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
            cleaned[len] = str[i];
            len++;
        }
    }
    cleaned[len] = '\0';

    for(i=0; i<len; i++) {
        inved[i] = cleaned[len-i-1];
    }
    inved[len] = '\0';

    printf("String: %s\nClean : %s\nInved : %s\n", str, cleaned, inved);

    if(strcmp( inved, cleaned) == 0) {
        return 1;
    }
    return 0;
}
