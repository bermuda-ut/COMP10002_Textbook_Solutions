/*=============================================================================
#     FileName: 15-treesort.c
#         Desc: calculate average depth of items 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-10-25 03:56:53
=============================================================================*/
/* WARNING : Lazy comments */
#include <stdio.h>
#include <stdlib.h>
#include "treeops.c"

int void_intcmp(void *a, void *b);
void printint(void* data);

int
main(int argc, char **argv) {
    int i, *tmp;

    tree_t *mytree = make_empty_tree(void_intcmp);

    printf("Type some integers: ");
    while(scanf("%d", &i) == 1) {
        tmp = malloc(sizeof(int));
        *tmp = i;
        insert_in_order(mytree, tmp);
    }

    traverse_tree(mytree, printint);
    printf("\n");

    return 0;
}

int
void_intcmp(void *a, void *b) {
    int *ta = a, *tb = b;
    return (*ta-*tb);
}

void
printint(void* data) {
    printf("%d ", *(int*) data);
}
