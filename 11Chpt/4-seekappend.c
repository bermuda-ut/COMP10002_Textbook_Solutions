/*=============================================================================
#     FileName: 4-seekappend.c
#         Desc: appends command line argument 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-10-25 14:28:32
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

#define OFFSET 100000 /* not 100000 unlike the question stated for easiness*/

int
main(int argc, char **argv) {
    FILE *file;

    if(argc != 2) {
        printf("No file stated\n"
               "Usage: ./seekappend [file1] ...\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "w+");
    fseek(file, OFFSET, SEEK_SET);
    fputs("\n", file);

    fclose(file);

    printf("Execution complete\n");
    return 0;
}
