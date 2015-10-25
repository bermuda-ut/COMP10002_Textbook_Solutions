/*=============================================================================
#     FileName: 8-avgdepth.c
#         Desc: calculate average depth of items 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-10-25 00:08:55
=============================================================================*/
/* WARNING : Lazy comments */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treeops.c"

#define ZOD_CNT     12
#define CHI_ZOD_CNT 12
#define FRND_CNT    3

int void_strcmp(void *a, void *b);
void print_tree(tree_t *tree);

int
main(int argc, char **argv) {
    char *zodiac[ZOD_CNT] = {"Aquarius", "Pisces", "Aries", "Taurus", "Gemini",
                        "Cancer", "Leo", "Virgo", "Libra", "Scorpio",
                        "Sagittarius", "Capricon"},
         *chi_zod[CHI_ZOD_CNT] = {"Rat", "Ox", "Tiger", "Rabbit", "Dragon",
                        "Snake", "Horse", "Goat", "Monkey", "Rooster",
                        "Dog", "Boar"},
         name[3] = "Max",
         *friends[FRND_CNT] = {"AlistairMoffat", "TakeshiHosomi", "JohnBain"};
    int i;

    tree_t *mytree = make_empty_tree(void_strcmp);

    printf("Adding zodiac stuff\n");
    for(i=0; i<ZOD_CNT; i++) {
        mytree = insert_in_order(mytree, zodiac[i]);
    }
    printf("Adding chinese zodiac stuff\n");
    for(i=0; i<CHI_ZOD_CNT; i++) {
        mytree = insert_in_order(mytree, chi_zod[i]);
    }
    printf("Adding my name lol\n");
    mytree = insert_in_order(mytree, name);

    printf("Adding friends\n");
    for(i=0; i<FRND_CNT; i++) {
        mytree = insert_in_order(mytree, friends[i]);
    }

    printf("\nTREE: \n");
    print_tree(mytree);

    return 0;
}

int
void_strcmp(void *a, void *b) {
    char* ta = (char*) a;
    char* tb = (char*) b;
    return strcmp(ta, tb);
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
            printf("%s ", (char*)(pending[i]->data));
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
