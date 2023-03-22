/*
    shoelace formula: 
    1/2 [ (x1y2 + x2y3 + … + xn-1yn + xny1) – (x2y1 + x3y2 + … + xnyn-1 + x1yn) ] 
    
    given n ordered vertice find polygon area
*/
#include <stdio.h>
#include <stdlib.h>


double polygonArea(int* x, int* y, int n){
    double area = x[n-1] * y[0] - x[0] * y[n-1];
    for (int i=1;i<n;i++)
        area += x[i-1] * y[i] - x[i] * y[i-1];

    return abs(area * 0.5);
}

int main(){


    int X[] = {0, 4, 2};
    int Y[] = {0, 0, 4};
    printf("%.1lf", polygonArea(X, Y, 3));





    return 0;
}