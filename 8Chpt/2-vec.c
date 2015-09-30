/*=============================================================================
#     FileName: 2-vec.c
#         Desc: structure of vector t 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-09-22 11:01:54
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} vector_t;

double distance(vector_t p1, vector_t p2);

int
main(int argc, char **argv) {
    vector_t vectors[10];
    int n=0, i;

    printf("Gimme some vectors(x y): ");
    while(scanf("%lf %lf", &vectors[n].x, &vectors[n].y) == 2 && n < 10) {
        n++;
    }
    printf("%d vectors read!\n", n);
    printf("Pivot Vector (%.3f, %.3f)\n---\n", vectors[0].x, vectors[0].y);

    for(i=0; i<=n; i++) {
        printf("Vector  : (%.3f, %.3f)\nDistance: %.3f\n---\n",
                vectors[i].x, vectors[i].y, distance(vectors[0], vectors[i]));
    }
    return 0;
}

double
distance(vector_t p1, vector_t p2) {
    /* Returns Euclidean distance between p1 and p2
     * :) */

    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));

}
