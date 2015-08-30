/*=============================================================================
#     FileName: 7-numword.c
#         Desc: counts number of chars, lines and words
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-09 13:44:16
=============================================================================*/

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv) {
    int txt, linecnt, chrcnt, wdcnt, inaword;
    inaword = linecnt = chrcnt = wdcnt = 0;

    printf("Enter Text:\n");

    while((txt=getchar()) != EOF) {
        if (txt == '\n') {
            /* new line */
            linecnt++;
        } else {
            chrcnt++;
        }

        if ((txt >= 'A' && txt <= 'Z') || (txt >= 'a' && txt <= 'z')) {
            inaword = 1;
        } else if(inaword == 1) {
            inaword = 0;
            wdcnt++;
        }
    }

    printf("Lines:%8d\nChars:%8d\nWords:%8d\n", linecnt, chrcnt, wdcnt);

    return 0;
}
