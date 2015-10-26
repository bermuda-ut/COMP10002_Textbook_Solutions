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

#define DEBUG     0
#define MAX_WDLEN 25
#define DICT_LEN  100000
#define DICT_PATH "/usr/share/dict/british-english"

/* unsigned char to accomodate special characters */
unsigned char *dictsearch(unsigned char *key,
        unsigned char dict[DICT_LEN][MAX_WDLEN], int keylen, int dictlen);
int streql(unsigned char *a, unsigned char *b);

int
main(int argc, char **argv) {
    FILE *dictpointer;
    unsigned char myword[MAX_WDLEN], dict[DICT_LEN][MAX_WDLEN], *found;
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
    while(fgets((char*)dict[i], MAX_WDLEN, dictpointer) != NULL &&
            i < DICT_LEN) {
        i++;
    }
    fclose(dictpointer);
    printf("Dictionary loaded. %d words read.\n---\n",i);

    /* Search Loop */
    printf("Search : ");
    while(scanf("%s", myword) == 1) {
        found = dictsearch(myword, dict, strlen((char*)myword), i);

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
charcmp(unsigned char *a, unsigned char *b) {
    return (*a - *b);
}

int
streql(unsigned char *a, unsigned char *b) {
    int i=0;
#if DEBUG
    printf("First word %s   second %s\n", a, b);
#endif
    while(a[i] != '\n' && b[i] != '\0') {
        if(a[i] != b[i]) {
            return 1;
        }
        i++;
    }
    return 0;
}

unsigned char
*dictsearch(unsigned char *key, unsigned char dict[DICT_LEN][MAX_WDLEN],
        int keylen, int dictlen) {
    int lo, hi, depth=0, start=0, end=dictlen-1, mid, res;
    lo = start;
    hi = end;

    while(depth <= keylen) {
        lo = start;
        hi = end;

        while(lo<hi) {
            /* find starting point of the value */
            mid = (lo+hi)/2;
#if DEBUG
            printf("[lo]checking %d(%c) with %d(%c)\n",
                    key[depth], key[depth], dict[mid][depth],dict[mid][depth]);
            printf("lo %d hi %d mid %d\n", lo, hi, mid);
            printf(">lo %s>hi %s>mid %s\n", dict[lo], dict[hi], dict[mid]);
#endif
            if((res=charcmp(key+depth, dict[mid]+depth)) < 0) {
                /* key is smaller > make hi lower */
                hi = mid-1;
            } else if(res > 0) {
                /* key is greater > make lo higher */
                lo = mid+1;
            } else {
                /* key. make this hi */
                hi = mid;
            }
        }

        start=lo;
#if DEBUG
        printf("--\n");
#endif
        hi=end;

        while(lo<hi) {
            /* find ending point of the value */
            mid = (lo+hi)/2;
#if DEBUG
            printf("[hi]checking %d(%c) with %d(%c)\n",
                    key[depth], key[depth], dict[mid][depth],dict[mid][depth]);
            printf("lo %d hi %d mid %d\n", lo, hi, mid);
            printf(">lo %s>hi %s>mid %s\n", dict[lo], dict[hi], dict[mid]);
#endif
            if((res=charcmp(key+depth, dict[mid]+depth)) < 0) {
                /* key is smaller > make hi lower */
                hi = mid-1;
            } else if(res > 0) {
                /* key is greater > make lo higher */
                lo = mid+1;
            } else {
                /* key. > make lo higher */
                lo = mid+1;
            }
            /*
            int z;
            scanf("%d",&z);
            */
        }

        end=hi;
        depth++;
#if DEBUG
        printf(">> Depth++\n\n");
#endif
    }

#if DEBUG
    printf("start %d end %d\n", start, end);
#endif
    assert(start >= end);
    return dict[start];
}
