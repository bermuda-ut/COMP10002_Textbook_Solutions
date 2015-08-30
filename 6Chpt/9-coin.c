/*=============================================================================
#     FileName: 9-coin.c
#         Desc:  
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-15 21:03:33
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int try_one_coin (int *cents, int coin);
void print_change (int cents);
int round_to_5 (int cents);
/*coins 50 20 10 5 2 1*/
#define COIN_50 50
#define COIN_20 20
#define COIN_10 10
#define COIN_5  5
#define COIN_2  2
#define COIN_1  1
#define UPPER_LIMIT 3
#define TEST_LIMIT 1000

int new_coin_system = 1;

int
main(int argc, char **argv) {
    int cnts;

    for(cnts = 0; cnts <= TEST_LIMIT; cnts++) {
        printf("CENTS : %d\n", cnts);
        print_change(cnts);
        printf("\n");
    }

    return 0;
}

int
try_one_coin (int *cents, int coin) {
    int count = 0;
    while (*cents >= coin) {
        count ++;
        *cents -= coin;
    }
    return count;
}

void
print_change (int cents){
    if (new_coin_system) {
        cents = round_to_5(cents);
        printf("rounded: %d\n", cents);
    }
    int fif, twn, ten, fiv, two, one;
    fif = try_one_coin(&cents, COIN_50);
    twn = try_one_coin(&cents, COIN_20);
    ten = try_one_coin(&cents, COIN_10);
    fiv = try_one_coin(&cents, COIN_5);
    if (!new_coin_system) {
    two = try_one_coin(&cents, COIN_2);
    one = try_one_coin(&cents, COIN_1);
    }
    printf("\
    %d : %d coins.\n\
    %d : %d coins.\n\
    %d : %d coins.\n\
    %d : %d coins.\n", COIN_50, fif, COIN_20, twn, COIN_10, ten,
    COIN_5, fiv); 
    if (!new_coin_system) {
        printf("\
        %d : %d coins.\n\
        %d : %d coins.\n\n", COIN_2, two, COIN_1, one);
    }
}

int
round_to_5 (int cents){
    int single, rest;
    rest = (cents / 5)*5;
    single = cents - rest;
    if (single >= UPPER_LIMIT) {
        single = 5;
    } else {
        single = 0;
    }

    return rest + single;
}
