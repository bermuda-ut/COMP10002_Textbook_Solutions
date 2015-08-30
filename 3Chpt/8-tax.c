/*=============================================================================
#     FileName: 8-tax.c
#         Desc: tax calculater - modified 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-02 13:52:00
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

#define RATE0 0.000
#define RATE1 0.190
#define RATE2 0.325
#define RATE3 0.370
#define RATE4 0.450
#define RATE5 0.475
#define RATEM 0.015
#define RATEM2 0.025

#define THRESH1  18200.00
#define THRESH2  37000.00
#define THRESH3  80000.00
#define THRESH4 180000.00
#define THRESH5 250000.00
#define THRESHM 100000.00

#define BASE0 0.00
#define BASE1 (BASE0 + RATE0*THRESH1)
#define BASE2 (BASE0 + RATE1*(THRESH2-THRESH1))
#define BASE3 (BASE0 + RATE2*(THRESH3-THRESH2))
#define BASE4 (BASE0 + RATE3*(THRESH4-THRESH3))
#define BASE5 (BASE0 + RATE4*(THRESH5-THRESH4))

int
main(int argc, char **argv) {
    double gross, tax, medicare, net;
    printf("Enter gross salary: $");
    if (scanf("%lf", &gross) != 1) {
        printf("No value was entered\n");
        exit(EXIT_FAILURE);
    }

    if (gross <= THRESH1) {
        tax = BASE0 + gross * RATE0;
    } else if (gross <= THRESH2) {
        tax = BASE1 + (gross - THRESH1) * RATE1;
    } else if (gross <= THRESH3) {
        tax = BASE2 + (gross - THRESH2) * RATE2;
    } else if (gross <= THRESH4) {
        tax = BASE3 + (gross - THRESH3) * RATE3;
    } else if (gross <= THRESH5) {
        tax = BASE4 + (gross - THRESH4) * RATE4;
    } else {
        tax = BASE5 + (gross - THRESH5) * RATE5;
    }

    if (gross <= THRESHM)
        medicare = RATEM*gross;
    else
        medicare = RATEM2*gross;

    net = gross - tax - medicare;
    printf("gross income        $%9.2f\n", gross);
    printf("less tax            $%9.2f\n", -tax);
    printf("less medicare       $%9.2f\n", -medicare);
    printf("net income          $%9.2f\n", net);

    return 0;
}
