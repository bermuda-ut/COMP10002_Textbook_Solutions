/*=============================================================================
#     FileName: 2-append.c
#         Desc: appends command line argument 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-10-25 13:03:39
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv) {
    int i;
    FILE *fp1, *fp2;

    if(argc != 3) {
        printf("Invalid arguments\nUsage: ./append [file1] [file2]\n");
        return 1;
    }

    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "a");

    while((i=getc(fp1)) != EOF) {
        fprintf(stderr, "Added %c %d\n", i,i);
        fprintf(fp2, "%c",i);
    }

    fclose(fp1);
    fclose(fp2);

    printf("Execution complete\n");
    return 0;
}
