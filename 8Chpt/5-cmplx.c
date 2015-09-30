/*=============================================================================
#     FileName: 5-cmplx.c
#         Desc: complex numbers 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-09-30 17:10:19
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double real;
    double imag;
} complex_t;

void printf_cx(complex_t number);
complex_t complex_add(complex_t v1, complex_t v2);
complex_t complex_mpy(complex_t v1, complex_t v2);

int
main(int argc, char **argv) {
    complex_t temp1, temp2;

    printf("Type complex number # #i : ");
    if(scanf("%lf %lfi", &temp1.real, &temp1.imag) != 2) {
        printf("Invalid Input\n");
        exit(EXIT_FAILURE);
    }
    printf("Type complex number # #i : ");
    if(scanf("%lf %lfi", &temp2.real, &temp2.imag) != 2) {
        printf("Invalid Input\n");
        exit(EXIT_FAILURE);
    }

    printf("Values read : ");
    printf_cx(temp1);
    printf(" and ");
    printf_cx(temp2);
    printf("\n");

    printf("Added : ");
    printf_cx(complex_add(temp1, temp2));
    printf("\n");
    printf("Multi : ");
    printf_cx(complex_mpy(temp1, temp2));
    printf("\n");


    return 0;
}

void
printf_cx(complex_t number) {
    printf("%.3f", number.real);
    if(number.imag < 0) {
        printf(" - %.3fi", fabs(number.imag));
    } else {
        printf(" + %.3fi", number.imag);
    }
}

complex_t 
complex_add(complex_t v1, complex_t v2) {
    complex_t new;
    new.real = v1.real + v2.real;
    new.imag = v1.imag + v2.imag;

    return new;
}

complex_t 
complex_mpy(complex_t v1, complex_t v2) {
    complex_t new;
    new.real = v1.real*v2.real - v1.imag*v2.imag;
    new.imag = v1.real*v2.imag + v2.real*v1.imag;

    return new;
}
