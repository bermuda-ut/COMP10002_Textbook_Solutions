/*=============================================================================
#     FileName: 3-sqrt.c
#         Desc: accepts a b c, finds out roots of the equation.
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-02 11:41:10
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main(int argc, char **argv) {
    double a, b, c, d, root1, root2;

    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("c: ");
    scanf("%lf", &c);

    d = b * b - 4 * a * c;

    if (d < 0) {
        printf("No roots.\n");
        return 0;
    }
    root1 = (-b + sqrt(d))/(2*a);
    root2 = (-b - sqrt(d))/(2*a);


    if (root1 != root2)
        printf("Root1: %.2f\nRoot2: %.2f\n", root1, root2);
    else
        printf("Root: %.2f\n", root1);
    return 0;
}
