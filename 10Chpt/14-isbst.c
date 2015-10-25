/*=============================================================================
#     FileName: 14-isbst.c
#         Desc: calculate average depth of items 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-10-25 03:52:53
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
int is_bst(tree_t *tree);
node_t *gen_node(char* str);

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
    tree_t *wrongt = make_empty_tree(void_strcmp);

    /* make invalid tree */
    wrongt->root = gen_node("b");
    wrongt->root->rght = gen_node("a");

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

    if(is_bst(mytree)) {
        printf("mytree is valid tree\n");
    } else {
        printf("mytree is invalid tree\n");
    }

    if(is_bst(wrongt)) {
        printf("wrongt is valid tree\n");
    } else {
        printf("wrongt is invalid tree\n");
    }

    return 0;
}

int
void_strcmp(void *a, void *b) {
    char* ta = (char*) a;
    char* tb = (char*) b;
    return strcmp(ta, tb);
}

const int
rec_check(node_t *node, int cmp(void*,void*)) {
    if(node->left != NULL) {
        if(cmp(node->left->data, node->data) > 0 ||
           rec_check(node->left, cmp) == 0) {
            return 0;
        }
    }

    if(node->rght != NULL) {
        if(cmp(node->rght->data, node->data) < 0 ||
           rec_check(node->rght, cmp) == 0) {
            return 0;
        }
    }

    return 1;
}

int
is_bst(tree_t *tree) {
    return rec_check(tree->root, tree->cmp);
}

node_t
*gen_node(char *str) {
    node_t *temp = malloc(sizeof(node_t));
    temp->data = str;
    temp->left = temp->rght = NULL;

    return temp;
}
