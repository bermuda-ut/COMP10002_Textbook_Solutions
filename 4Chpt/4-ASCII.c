/*=============================================================================
#     FileName: 4-ASCII.c
#         Desc: ASCII table 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-08 20:24:49
=============================================================================*/
#include <stdio.h>

#define ROW_START 32
#define ROW_END   120
#define ROW_STEP  8

#define COL_START 0
#define COL_END   7
#define COL_STEP  1

int
main(int argc, char **argv) {
    int row, column;

    for(row=ROW_START-ROW_STEP*2; row < ROW_END+ROW_STEP; row+=ROW_STEP) {
        for(column=COL_START-COL_STEP;
            column<COL_END+COL_STEP; column+=COL_STEP) {
            if (row==ROW_START-ROW_STEP*2) {
                /* first row */
                if (column == COL_START-COL_STEP) {
                    /* first column */
                    printf("    ");
                } else {
                    /* normal first row */
                    printf("  +%d", column);
                }
            } else if(row == ROW_START-ROW_STEP) {
                 if (column == COL_START-COL_STEP) {
                    /* first column */
                    printf("   +");
                } else {
                    /* normal first row */
                    printf("----");
                }
            } else {
                /* normal */
                if (column == COL_START-COL_STEP) {
                    /* first column */
                    printf("%3d|", row);
                } else {
                    /* normal */
                    printf("%4c", row+column);
                }
            }
        }
        printf("\n");
    }

    return 0;
}
