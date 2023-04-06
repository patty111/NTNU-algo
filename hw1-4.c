/*
    Problem 470 - Rabbit Hole
    http://alienryderflex.com/polygon_area/
    http://wiki.csie.ncku.edu.tw/acm/course/Convex%20Hull

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct{
    int x;
    int y;
}vertice;

int init_x = INT32_MAX;
int init_y = INT32_MAX;

// return a cross b, for sorting in counter clockwise
int cmpcross(const void* a, const void* b){
    vertice* v1 = (vertice*)a;
    v1->x -= init_x;
    v1->y -= init_y;
    vertice* v2 = (vertice*)b;
    v2->x -= init_x;
    v2->y -= init_y;
    return (v1->x * v2->y) - (v1->y * v2->x);
}



// int cmpfunc(const void* a, const void* b){  // compare function for qsort. sort by x, if x same then sort by y
//     return ((vertice*)a)->x == ((vertice*)b)->x ? ((vertice*)a)->y - ((vertice*)b)->y : ((vertice*)a)->x - ((vertice*)b)->x;
// }



int orientation(vertice p, vertice q, vertice r){  // 0 1 2 -> collinear / counter-clockwise / clockwise  , for brute hull
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}


vertice* brute_hull(vertice* points, int n, int* hull_size){
    vertice* hull = NULL;
    int hull_c = 0;
    *hull_size = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int flag = 1;

            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;

                int o = orientation(points[i], points[j], points[k]);
                if (o == 1) {
                    flag = 0;
                    break;
                }
            }

            if (flag) {
                if (*hull_size == hull_c) {
                    hull_c = (hull_c == 0) ? 1 : hull_c * 2;
                    hull = realloc(hull, hull_c * sizeof(vertice));
                }

                hull[*hull_size] = points[i];
                (*hull_size)++;
                break;
            }

        }
    }
    return hull;
}



// void* devide(vertice* V, int len, vertice* stack, int* top){
    // return;
// }



int main(){
    int n;
    scanf("%d", &n);
    vertice* V = (vertice*)malloc(sizeof(vertice) * n);
    vertice* stack = (vertice*)malloc(sizeof(vertice) * n);
    
    int t = -1;
    int* top = &t;


    // taking input and find starting point
    for (int i=0;i<n;i++){      
        scanf("%d %d", &V[i].x, &V[i].y);
        if (V[i].x < init_x)
            init_x = V[i].x;
        else if (V[i].x == init_x && V[i].y < init_y)
            init_y = V[i].x;
    }

    // cx /= n; cy /= n;
    qsort(V, n, sizeof(vertice), cmpcross);

    for (int i=0;i<n;i++)
        printf("%d %d\n", V[i].x, V[i].y);







    return 0;
}