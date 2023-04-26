/*
    Problem 470 - Rabbit Hole
    http://alienryderflex.com/polygon_area/
    http://wiki.csie.ncku.edu.tw/acm/course/Convex%20Hull
    https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
    https://lvngd.com/blog/convex-hull-graham-scan-algorithm-python/
    https://www.geeksforgeeks.org/convex-hull-using-graham-scan/
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct{
    int x;
    int y;
}vertice;


vertice p;
int cx = 0;
int cy = 0;


double polygonArea(vertice* points, int n){
    double a = points[n-1].x;
    a *= points[0].y;
    double b = points[0].x;
    b *= points[n-1].y;
    double area = a-b;
    // double area = points[n-1].x * points[0].y - points[0].x * points[n-1].y;
    for (int i=1;i<n;i++){
        a = points[i-1].x;
        a *= points[i].y;
        b = points[i].x;
        b *= points[i-1].y;
        area += (a - b);
        // area += points[i-1].x * points[i].y - points[i].x * points[i-1].y;
    }
    return fabs(area/2);
}


void push(vertice* stack, int* top, vertice v){
    stack[++(*top)] = v;
}   


vertice pop(vertice* stack, int* top){
    return stack[(*top)--];
} 


int manhattan_dist(vertice a, vertice b){
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}


int cross_product(vertice a, vertice b, vertice c){
    double cross = 0;
    double tmp1 = b.y;
    tmp1 -= a.y;
    double tmp2 = c.x;
    tmp2 -= b.x;
    cross += tmp1 * tmp2;

    tmp1 = b.x;
    tmp1 -= a.x;
    tmp2 = c.y;
    tmp2 -= b.y;
    cross -= tmp1 * tmp2;

    // int cross = (b.y - a.y)*(c.x - b.x) - (b.x - a.x)*(c.y - b.y);
    if (cross == 0) return 0;  // collinear
    return (cross > 0) ? 1 : 2; // clockwise r/ counter l
}


int cmpfunc(const void* v1, const void* v2) {

    int cp = cross_product(p, *(vertice*)v1, *(vertice*)v2);

    if (cp == 0) {      // collinear
        int d1 = manhattan_dist(p, *(vertice*)v1);
        int d2 = manhattan_dist(p, *(vertice*)v2);
        
        if (d1 == d2) return 0; // sort by dist if same angle
        return (d1 < d2) ? -1 : 1;
    }
    return (cp == 2) ? -1 : 1; // clockwise / counter
}


vertice* convex_hull(vertice* s_V, vertice* stack, int n, int* top){    // s_v: sorted array

    int m = 1;
    for (int i=1; i<n; i++){
        while (i < n-1 && cross_product(p, s_V[i], s_V[i+1]) == 0)
            i++;
        s_V[m] = s_V[i];
        m++;
    }

    if (m < 3) return NULL;
    if (m == 3){
        *top = 2;
        return s_V;
    }

    push(stack, top, s_V[0]);
    push(stack, top, s_V[1]);

    for (int i=2;i<m;i++){
        while ((*top) >= 1 && (cross_product(stack[(*top)-1], stack[(*top)], s_V[i]) != 2))
            *top -= 1;

        push(stack, top, s_V[i]);
    }

    int cnt = 0;
    for (int i=0;i<=(*top);i++){
        s_V[cnt++] = stack[i];
    }
    *top = cnt-1;

    return s_V;
}




int main(){
    int n;
    scanf("%d", &n);
    vertice* V = (vertice*)malloc(sizeof(vertice) * n);
    vertice* stack = (vertice*)malloc(sizeof(vertice) * (n+1));
    
    int t = -1;
    int* top = &t;

    int init_x = INT32_MAX;
    int init_y = INT32_MAX;

    // taking input and find starting vertice(y smallest)
    int index = 0;
    int same_x = 1;
    int same_y = 1;
    for (int i=0;i<n;i++){      
        scanf("%d %d", &V[i].x, &V[i].y);
        cx += V[i].x;
        cy += V[i].y;
        if (V[i].y < init_y || (V[i].y == init_y && V[i].x < init_x)) {
            init_x = V[i].x;
            init_y = V[i].y;
            index = i;
        }
        if (i >=1){
            if (V[i].x != V[i-1].x) same_x = 0;
            if (V[i].y != V[i-1].y) same_y = 0;
        }
    }

    cx /= n; cy /= n;
    p.x = cx; p.y = cy;
    p = V[index];

    vertice tmp = V[0];
    V[0] = V[index];
    V[index] = tmp;

    if (n < 3)  printf("0");
    else if (same_x == 1 || same_y == 1) printf("0\n");
    else{
        qsort(&V[1], n-1, sizeof(vertice), cmpfunc);   // sorting start from index 1 and sort in counter clockwise
        // printf("%d %d\n", V[0].x, V[0].y);
        vertice* result = convex_hull(V, stack, n, top);

        double area = polygonArea(result, (*top)+1);

        if ((long long int)area == area) printf("%.0lf\n", area);
        else printf("%.1lf\n", area);
    }

    return 0;
}