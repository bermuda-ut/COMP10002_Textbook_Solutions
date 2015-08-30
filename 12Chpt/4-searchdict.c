/*=============================================================================
#     FileName: 4-searchdict.c
#         Desc: search dictionary
                /usr/share/dict/british-english
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-27 19:35:21
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_LEN 100
#define DICT_PATH "/usr/share/dict/british-english"

FILE *gbrdict;

int
main(int argc, char **argv) {
    char word[MAX_WORD_LEN];

    gbrdict = fopen(DICT_PATH,"rt");

    printf("Type a word: ");
    scanf("%[^\n]%*c", word);
    printf("Word read: %s\n", word);

    return 0;
}
