/*=============================================================================
#     FileName: 3-poly.c
#         Desc: Poly fun
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-09-24 20:29:21
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERT 100

typedef struct {
    double x;
    double y;
} coord_t;

typedef struct {
    int num_vert;
    coord_t points[MAX_VERT];
} poly_t;

double perimeter(poly_t P);
double area(poly_t P);

int
main(int argc, char **argv) {
    int x, i;
    poly_t mypoly;

    printf("Enter number of verticies: ");
    if(scanf("%d", &x) != 1 || x == 0) {
        printf("plz\n");
        exit(EXIT_FAILURE);
    }

    mypoly.num_vert = x;

    for(i=0; i<x; i++) {
        printf("Enter coordinates x y : ");
        scanf("%lf %lf", &mypoly.points[i].x, &mypoly.points[i].y);
    }

    printf("Perimeter : %.3f\n", perimeter(mypoly));
    printf("Area : %.3f\n", area(mypoly));

    return 0;
}

double 
perimeter(poly_t P) {
    int i, diff_x, diff_y;
    double sum=0;
    if(P.num_vert == 1) {
        return sqrt(P.points[0].x*P.points[0].x + P.points[0].y*P.points[0].y);
    }

    for(i=0; i < P.num_vert-1; i++) {
        diff_x = P.points[i].x - P.points[i+1].x;
        diff_y = P.points[i].y - P.points[i+1].y;
        sum += sqrt(diff_x*diff_x + diff_y*diff_y);
    }
    diff_x = P.points[i].x - P.points[0].x;
    diff_y = P.points[i].y - P.points[0].y;
    sum += sqrt(diff_x*diff_x + diff_y*diff_y);

    return sum;
}

double
area(poly_t P) {
    /* Refer To
     * https://en.wikipedia.org/wiki/Polygon#Area_and_centroid */
    int i;
    double area=0;

    for(i=0; i < P.num_vert-1; i++) {
        area += (P.points[i].x*P.points[i+1].y - P.points[i+1].x*P.points[i].y);
    }
    area += (P.points[i].x*P.points[0].y - P.points[0].x*P.points[i].y);

    return fabs(area)*0.5;
}
