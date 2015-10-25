/*=============================================================================
#     FileName: 4-strbsearch.c
#         Desc: string binary search 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-10-26 00:29:22
=============================================================================*/
/* WARNING : Lazy comments. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define MAX_WDLEN 20
#define DICT_LEN  100000
#define DICT_PATH "/usr/share/dict/british-english"

char *dictsearch(char *key, char dict[DICT_LEN][MAX_WDLEN], int keylen, int dictlen);
int streql(char *a, char *b);

int
main(int argc, char **argv) {
    FILE *dictpointer;
    char myword[MAX_WDLEN], dict[DICT_LEN][MAX_WDLEN], *found;
    int i=0;

    /* Get file pointer to dictionary */
    if(argc == 1) {
        printf("Default dictionary loaded\n");
        dictpointer = fopen(DICT_PATH, "r");
        assert(dictpointer != NULL);
    } else {
        dictpointer = fopen(argv[1], "r");
        if(dictpointer == NULL) {
            printf("Unable to read file\n");
            exit(EXIT_FAILURE);
        }
        printf("Opened %s\n", argv[1]);
    }


    /* Load Dictionary */
    while(fgets(dict[i], MAX_WDLEN, dictpointer) != NULL && i < DICT_LEN) {
        i++;
    }
    fclose(dictpointer);
    printf("Dictionary loaded. %d words read.\n---\n",i);

    /* Search Loop */
    printf("Search : ");
    while(scanf("%s", myword) == 1) {
        found = dictsearch(myword, dict, strlen(myword), i);

        if(streql(found, myword) == 0) {
            printf(" > Found %s\n", myword);
        } else {
            printf(" > Could not find %s\n", myword);
            printf(" > Did you mean   %s", found);
        }
        printf("---\nSearch : ");
    }

    return 0;
}

int
charcmp(char *a, char *b) {
    return (*a - *b);
}

int
streql(char *a, char *b) {
    int i=0;
    while(a[i] != '\n') {
        if(charcmp(a+i, b+i) != 0) {
            return 1;
        }
        i++;
    }
    return 0;
}

char
*dictsearch(char *key, char dict[DICT_LEN][MAX_WDLEN], int keylen, int dictlen) {
    int lo, hi, depth=0, start=0, end=dictlen, mid;

    while(depth <= keylen) {
        lo = start;
        hi = end;

        while(lo<hi) {
            mid = (lo+hi)/2;
            if(charcmp(dict[mid]+depth, key+depth) < 0) {
                /* bring up low */
                lo = mid+1;
            } else {
                hi = mid;
            }
        }

        start=lo;
        hi=end;

        while(lo<hi) {
            mid = (lo+hi)/2;
            if(charcmp(dict[mid]+depth, key+depth) > 0) {
                /* bring down high */
                hi = mid;
            } else {
                lo = mid+1;
            }
        }

        end=hi;

        depth++;
    }

    assert(start == end);
    return dict[start];
}
