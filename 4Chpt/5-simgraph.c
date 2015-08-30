/*=============================================================================
#     FileName: 5-simgraph.c
#         Desc: simple graph
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-13 19:16:55
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv) {
    int g_element;

    printf("Enter numbers: ");
    while(scanf("%d", &g_element) == 1) {
        printf("%-3d|",g_element);
        int x;
        for (x=0; x<g_element; x++){
            printf("*");
        }
        printf("\n");
    }

    printf("Graph complete.\n");

    return 0;
}
