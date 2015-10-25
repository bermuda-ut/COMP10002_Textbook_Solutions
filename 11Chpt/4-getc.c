/*=============================================================================
#     FileName: 4-getc.c
#         Desc: appends command line argument 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-10-25 14:20:20
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv) {
    int i;
    FILE *file;

    if(argc != 2) {
        printf("No file stated\n"
               "Usage: ./getc [file1] ...\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    while((i=getc(file)) != EOF) {
        printf("%d ", i);
    }

    fclose(file);

    printf("Execution complete\n");
    return 0;
}
