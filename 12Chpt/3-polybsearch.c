/*=============================================================================
#     FileName: 3-polybsearch.c
#         Desc: polymorphic binary search 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-10-25 21:24:53
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

void *polybsearch(const void *key, void *datalist,
        int nitems, size_t size, int (*cmp)(const void*, const void*));
int intcmp(const void *a, const void *b);

int
main(int argc, char **argv) {
    int data[10] = {6,5,3,2,0,1,9,8,7,4}, i;

    qsort(data, 10, sizeof(int), intcmp);
    printf("Sorted data: ");
    for(i=0; i<10; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    printf("Find what value?: ");
    scanf("%d", &i);

    void* res = polybsearch(&i, data, 10, sizeof(int), intcmp);

    if(res != NULL) {
        printf("Found %d\n", *(int*)res);
    } else {
        printf("Not found\n");
    }
    return 0;
}

void
*polybsearch(const void *key, void *datalist, 
        int nitems, size_t size, int (*cmp)(const void*, const void*)) {
    int mid = nitems/2, outcome;

    if(nitems <= 0) {
        return NULL;
    }

    if((outcome=cmp(key, datalist+(size*mid)/sizeof(void))) < 0) {
        return polybsearch(key, datalist, mid, size, cmp);

    } else if(outcome > 0) {
        return polybsearch(key, datalist+(size*(mid+1))/sizeof(void),
                mid-!(nitems%2), size, cmp);

    } else {
        return datalist+(size*mid)/sizeof(void);
    }
}

int
intcmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
