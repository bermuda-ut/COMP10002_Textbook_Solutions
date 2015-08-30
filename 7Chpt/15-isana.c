/*=============================================================================
#     FileName: 15-isana.c
#         Desc: izzit anagram??
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-23 23:21:11
#      History:
=============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WDCOUNT 1000

int is_anagram(char* a, char* b);
int wdcnt(char* str, int* wdlist, int* wdfreq);
void insert_sort_two(int* A, int* B, int len);
void int_swap(int* a, int* b);

int
main(int argc, char **argv) {
    char str[MAX_WDCOUNT], str2[MAX_WDCOUNT];
    int i;

    printf("Press Ctrl-D to finish entering\n");
    printf("Be aware of flushing data into stdin\n");
    printf("Type string1: ");
    for(i=0; scanf("%c", &str[i]) == 1; i++);
    str[i] = '\0';
    printf("\n");

    printf("Type string2: ");
    for(i=0; scanf("%c", &str2[i]) == 1; i++);
    str2[i] = '\0';
    printf("\n");

    if(is_anagram(str, str2)) {
        printf("They are an anagram pair :)\n");
    } else {
        printf("They are not an anagram pair :(\n");
    }

    return 0;
}

int
is_anagram(char* a, char* b) {
    if(*a == *b) {
        return 0;
    }

    int wdlist[MAX_WDCOUNT], wdfreq[MAX_WDCOUNT];
    int wdlist2[MAX_WDCOUNT], wdfreq2[MAX_WDCOUNT];
    int i, len;

    len = wdcnt(a, wdlist, wdfreq);
    insert_sort_two(wdlist, wdfreq, len);

    len = wdcnt(b, wdlist2, wdfreq2);
    insert_sort_two(wdlist2, wdfreq2, len);

    for(i=0; i<len; i++) {
        if(wdlist[i] != wdlist2[i] || wdfreq[i] != wdfreq[i]) {
            return 0;
        }
    }

    return 1;
}

int
wdcnt(char* str, int* wdlist, int* wdfreq) {
    int i=0, j, len, listlen=0, found;
    len = strlen(str);
    for(i=0; i<len; i++) {
        found = 0;
        for(j=0; j<listlen; j++) {
            if(str[i] == wdlist[j]) {
                found = 1;
                break;
            }
        }

        if(found) {
            wdfreq[j]++;
        } else {
            wdlist[j] = str[i];
            wdfreq[j] = 1;
            listlen++;
        }
    }

    return listlen;
}

void 
insert_sort_two(int* A, int* B, int len) {
    int i, j;
    for(i=0; i<len; i++) {
        for(j=i; j>=0 && A[j] < A[j-1]; j--) {
            int_swap(A+j, A+j-1);
            int_swap(B+j, B+j-1);
        }
    }
}

void 
int_swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
