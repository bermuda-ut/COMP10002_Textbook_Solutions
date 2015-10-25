/*=============================================================================
#     FileName: 5-insinorder.c
#         Desc: func for question 4 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-10-24 23:06:39
=============================================================================*/
typedef int data_t;

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "listops.c"

list_t *insert_in_order(list_t *list, data_t value);
int cmp(data_t a, data_t b);
void printlist(list_t *list);

int
main(int argc, char **argv) {
    list_t *mylist;
    int i, find;

    mylist = make_empty_list();

    for(i=100; i > 0; i--) {
        mylist = insert_in_order(mylist, i);
    }

    printf("Insert what value?: ");
    scanf("%d", &find);
    mylist = insert_in_order(mylist, find);

    printlist(mylist);

    return 0;
}

list_t
*insert_in_order(list_t *list, data_t value) {
    node_t *current = list->head,
           *new = malloc(sizeof(node_t));
    new->data = value;

    /* if head */
    if(current == NULL) {
        new->next = NULL;
        list->foot = new;
        list->head = new;
        return list;
    } else if(current->data > value) {
        new->next = list->head;
        list->head = new;
        return list;
    }

    while(current->next != NULL) {
        /* not head or foot */
        if(current->next->data > value) {
            new->next = current->next;
            current->next = new;
            return list;
        }
        current = current->next;
    }

    /* if foot */
    if(current->data < value) {
        new->next = NULL;
        list->foot->next = new;
        list->foot = new;
    } else {
        assert(list->head == list->foot);
        new->next = list->foot;
        list->head = new;
    }
    return list;
}

void
printlist(list_t *list) {
    node_t *curr = list->head;
    while(curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
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
