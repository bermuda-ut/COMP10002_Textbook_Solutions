/*=============================================================================
#     FileName: 6-polydata-islistele.c
#         Desc: testing poly-ed listops
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-10-24 23:55:52
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "6-polydata-listops.c"

int is_list_element(list_t *list, void *value);
int cmp(void *a, void *b);
void printlist(list_t *list);

int
main(int argc, char **argv) {
    list_t *mylist;
    int i, find, *temp;

    mylist = make_empty_list();

    for(i=0; i < 100; i++) {
        temp = malloc(sizeof(int));
        *temp = i;
        insert_at_foot(mylist, temp);
    }

    printf("Find what value?: ");
    scanf("%d", &find);

    if (is_list_element(mylist, &find)) {
        printf("Found.\n");
    } else {
        printf("Not Found.\n");
    }

    printlist(mylist);

    return 0;
}

int 
is_list_element(list_t *list, void *value) {
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
cmp(void* a, void* b) {
    int *ta, *tb;
    ta = (int*) a;
    tb = (int*) b;

    if(*ta < *tb) {
        return -1;
    } else if (*ta > *tb) {
        return 1;
    } else {
        return 0;
    }
}

void
printlist(list_t *list) {
    node_t *curr = list->head;
    while(curr != NULL) {
        printf("%d ", *(int*)curr->data);
        curr = curr->next;
    }
    printf("\n");
}
