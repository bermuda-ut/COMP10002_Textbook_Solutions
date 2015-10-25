/*=============================================================================
#     FileName: 12-treesize.c
#         Desc: calculate average depth of items 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-10-25 03:16:50
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
int tree_size(tree_t *tree);

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

    printf("TREE has %d elements\n", tree_size(mytree));

    return 0;
}

int
void_strcmp(void *a, void *b) {
    char* ta = (char*) a;
    char* tb = (char*) b;
    return strcmp(ta, tb);
}

const int
rec_tree_size(node_t *node, int n) {
    if(node->left != NULL) {
        n = rec_tree_size(node->left, n);
    }
    if(node->rght != NULL) {
        n = rec_tree_size(node->rght, n);
    }
    n++;

    return n;
}

int 
tree_size(tree_t *tree) {
    /* potentially memory expensive since new int is delcared every recursion */
    return rec_tree_size(tree->root, 0);
}

