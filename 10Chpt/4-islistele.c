/*=============================================================================
#     FileName: 4-islistele.c
#         Desc: func for question 4 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-10-24 22:07:05
=============================================================================*/
typedef int data_t;

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "listops.c"

int is_list_element(list_t *list, data_t value);
int cmp(data_t a, data_t b);

int
main(int argc, char **argv) {
    list_t *mylist;
    int i, find;

    mylist = make_empty_list();

    for(i=0; i < 100; i++) {
        insert_at_foot(mylist, i);
    }

    printf("Find what value?: ");
    scanf("%d", &find);

    if (is_list_element(mylist, find)) {
        printf("Found.\n");
    } else {
        printf("Not Found.\n");
    }

    return 0;
}

int 
is_list_element(list_t *list, data_t value) {
    node_t* temp = list->head;

    while(temp != NULL) {
        if(cmp(temp->data, value) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    
    return 0;
}

int
cmp(data_t a, data_t b) {
    int ta, tb;
    ta = (int) a;
    tb = (int) b;

    if(ta < tb) {
        return -1;
    } else if (ta > tb) {
        return 1;
    } else {
        return 0;
    }
}
