/*=============================================================================
#     FileName: 10-isotoansi.c
#         Desc: turns C code iso comments into ansi comments 
                For question 10 and 11.
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-09 16:10:03
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv) {
    int ch, incomment=0, detected=0, instr=0, added=0, halt=0, combidect=0, prevch;

    /* Assumes the original code is correct syntax */
    while((ch=getchar()) != EOF) {
        if (ch == '\'' || ch == '\"') {
            /*toggle string mode*/
            if (instr) {
                instr = 0;
            } else {
                instr = 1;
            }
        }

        if (detected == 1) {
            /*if not double slash*/
            if (ch != '/') {
                printf("/");
            } else {
                incomment = 1;
                halt = 1;
            }
            detected = 0;
        }
        if (ch == '/' && !instr && !incomment) {
                /*if single slash found*/
                detected = 1;
                halt = 1;
        }

        if (incomment) {
            /*comment mode*/
            if (!added) {
                /*first letter*/
                printf("/*");
                added = 1;
            } else {
                if (combidect) {
                    /*combination detected previously*/
                    if (prevch == '/' && ch == '*') {
                        halt = 1;
                    } else if (prevch == '*' && ch == '/') {
                        halt = 1;
                    } else {
                        putchar(prevch);
                    }
                    combidect = 0;
                }
                else if (ch == '/' || ch == '*') {
                    combidect = 1;
                    prevch = ch;
                    halt = 1;
                }
            }

            if (ch == '\n') {
                printf("*/");
                added = 0;
                incomment = 0;
            }
        }

        /* print only if not halt */
        if (halt == 0) {
            putchar(ch);
        } else {
            halt--;
        }
    }
    return 0;
}
