/*=============================================================================
#     FileName: 6-wc.c
#         Desc: counts number of chars and new lines
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-09 13:13:58
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv) {
    int txt, linecnt, chrcnt;
    linecnt = chrcnt = 0;

    printf("Enter Text:\n");

    while((txt=getchar()) != EOF) {
        if (txt == '\n') {
            /* new line */
            linecnt++;
        } else {
            chrcnt++;
        }
    }

    printf("Lines:%8d\nChars:%8d\n", linecnt, chrcnt);


    return 0;
}
