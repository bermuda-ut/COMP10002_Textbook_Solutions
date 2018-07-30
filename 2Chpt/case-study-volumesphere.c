/*=============================================================================
#     FileName: volumesphere.c
#         Desc: calculates volume of the sphere 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-31 00:29:29
#      History:
=============================================================================*/
#include <stdio.h>

#define PI 3.14159

int
main(int argc, char *argv[]) {
    double radius, volume;

    printf("Entre radius(m) : ");
    if (scanf("%lf", &radius)) {
        volume = 4.0 / 3.0 * PI * radius * radius * radius;
        printf("Voume is %.2fm3.\n", volume);
    } else {
        printf("Invalid input\n");
    }
    return 0;
}
