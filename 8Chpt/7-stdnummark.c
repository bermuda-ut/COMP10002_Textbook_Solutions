/*=============================================================================
#     FileName: 7-stdnummark.c
#         Desc: 7.5 reborn
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-09-30 22:20:29
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int number;
    int mark;
} student_t;

void insert_sort(student_t *list, int size);

int
main(int argc, char **argv) {
    student_t student_list[5];
    int i, listnum=5; /* could easily change this */

    for(i=0; i<listnum; i++) {
        printf("Type studentnumber mark: ");
        if(scanf("%d %d", &student_list[i].number, &student_list[i].mark)
                != 2) {
            printf("Invalid input\n");
            break;
        }
    }

    insert_sort(student_list, listnum);

    for(i=0; i<listnum; i++) {
        printf("%6d %3d\n", student_list[i].number, student_list[i].mark);
    }

    return 0;
}

void
swap_data(student_t *s1, student_t *s2) {
    student_t temp;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void
insert_sort(student_t *list, int size) {
    int i,j;
    for(i=1; i<size; i++) {
        for(j=i-1; j>=0 && list[j+1].number < list[j].number; j--) {
            swap_data(list+j+1, list+j);
        }
    }
}
