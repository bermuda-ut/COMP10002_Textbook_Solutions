/*=============================================================================
#     FileName: shapes.c
#         Desc: calculates various values 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-31 00:29:15
=============================================================================*/
#include <stdio.h>
#define PI 3.14

int
main(int argc, char *argv[]) {
    double r, elapsed_time, spd, rad;
    int start_hour, start_min;

    printf("r(m):");
    scanf("%lf", &r);

    printf("Area of square of edge length %.2f : %.2f\n", r, r * r);
    printf("Perimeter of square of edge length %.2f : %.2f\n", r, r + r);
    rad = PI * r * 2.0;
    printf("Perimeter of circle of edge length %.2f : %.2f\n", r, rad);

    printf("You start running at speed (m/s) of..");
    scanf("%lf", &spd);

    elapsed_time = rad / spd;
    
    while (elapsed_time >= 60) {
        elapsed_time -= 60;
        start_min ++;
    }
    while (start_min >= 60) {
        start_min -= 60;
        start_hour ++;
    }

    printf("You took %d hour %d min %.2f seconds\n",
            start_hour, start_min, elapsed_time);

    return 0;
}
