/*=============================================================================
#     FileName: FtoC.c
#         Desc: Fahrenheit to Celcius
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-06 19:09:32
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv) {
    double farh, celc;

    printf("Enter Fahrenheit then hit Enter\nCtrl-D to terminate\n");
    /*if (scanf("%lf", &farh) != 1) {
        printf("Invalid input");
    }*/

    printf("Enter Value: ");
    while(scanf("%lf", &farh) == 1) {
        celc = (farh - 32) * 5.0/9.0;
        printf("%.2fF to Celcius = %.2f\n", farh, celc);
        printf("Enter Value: ");
    }
    printf("Loop Terminated.\n");

    printf("Program Terminated.\n");
    return 0;
}
