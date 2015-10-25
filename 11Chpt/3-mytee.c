/*=============================================================================
#     FileName: 3-mytee.c
#         Desc: appends command line argument 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-10-25 13:06:27
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv) {
    int i, j, opened=1;
    FILE **files;

    if(argc == 1) {
        printf("No file stated, simply printing input\n"
               "Usage: ./mytee [file1] [file2] ...\n");
        opened=0;
    } else {
        files = malloc((argc-1)*sizeof(FILE*));
        for(i=0; i<argc-1; i++) {
            files[i] = fopen(argv[i+1], "w");
        }
    }


    while((i=getchar()) != EOF) {
        fprintf(stderr, "%c", i);
        for(j=0; j<argc-1; j++) {
            fprintf(files[j], "%c",i);
        }
    }

    for(i=0; i<argc-1 && opened; i++) {
        fclose(files[i]);
    }

    printf("Execution complete\n");
    return 0;
}
