/*=============================================================================
#     FileName: 16-baltree.c
#         Desc: calculate average depth of items 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-10-25 12:01:17
=============================================================================*/
/* WARNING : Lazy comments */
#include <stdio.h>
#include <stdlib.h>
#include "treeops.c"

#define INTCNT 15

int void_intcmp(void *a, void *b);
void printint(void* data);
void print_tree(tree_t *tree);
void int_balance_insert(tree_t *tree, int *datalist, int n);
int intcmp(const void *a, const void *b);

int
main(int argc, char **argv) {
    /*
    int list[INTCNT] = {1,9,0,3,2,4,6,7,5,8,10,13,11,12,14}, i;
    */
    int list[INTCNT] = {0,1,2,3,4,6,7,8,9,23,32,35,33,54,42}, i;

    tree_t *mytree = make_empty_tree(void_intcmp);

    /* Unbalanced */
    for(i=0; i<INTCNT; i++) {
        insert_in_order(mytree, list+i);
    }
    print_tree(mytree);
    printf("------------------------\n");

    free_tree(mytree);
    mytree = make_empty_tree(void_intcmp);

    /* Balanced */
    int_balance_insert(mytree, list, INTCNT);
    print_tree(mytree);

    return 0;
}

int
intcmp(const void *a, const void *b) {
    int ta = *(int*)a, tb = *(int*)b;
    return (ta-tb);
}

void
rec_ins_pair(tree_t *tree, int *datalist, int n) {
    if(n<=0) {
        return;
    }

    insert_in_order(tree, datalist+n/2);
    rec_ins_pair(tree, datalist, n/2);
    rec_ins_pair(tree, datalist+n/2+1, n/2 - !(n%2));
}

void
int_balance_insert(tree_t *tree, int *datalist, int n) {
    qsort((int*)datalist, n, sizeof(int), intcmp);

    printf("qsorted:\n");
    int i;
    for(i=0; i<n; i++) {
        printf("%2d ", datalist[i]);
    }
    printf("\n\n");

    rec_ins_pair(tree, datalist, n);
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

void 
print_tree(tree_t *tree) {
    node_t **pending = malloc(sizeof(node_t*));
    node_t **temppending;
    pending[0] = tree->root;
    int pend=1, temppend, i, depth=1, cnt=0, totdepth=0;

    while(pend > 0) {
        temppend = 0;
        temppending = (node_t**) malloc(sizeof(node_t*));

        for(i=0; i<pend; i++) {
            printf("%d ", *(int*)(pending[i]->data));
            cnt++;
            totdepth += depth;

            if(pending[i]->left != NULL) {
                /* Add left */
                temppend++;
                temppending = realloc(temppending, sizeof(node_t*) * temppend);
                temppending[temppend-1] = pending[i]->left;
            }

            if(pending[i]->rght != NULL) {
                /* Add right */
                temppend++;
                temppending = realloc(temppending, sizeof(node_t*) * temppend);
                temppending[temppend-1] = pending[i]->rght;
            }
        }

        /* reset */
        depth++;
        pend = temppend;
        free(pending);
        pending = temppending;
        printf("\n");
    }

    printf("\nCount       : %2d\nTotal Depth : %2d\nAvg Depth   : %.2f\n",
            cnt, totdepth, (double) totdepth/cnt);
}
