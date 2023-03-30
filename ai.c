#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} vertice;

int compare(const void* a, const void* b) {
    vertice* p1 = (vertice*)a;
    vertice* p2 = (vertice*)b;
    int o = (p2->y - ((vertice*)a)[0].y) * (p1->x - p2->x) - (p2->x - ((vertice*)a)[0].x) * (p1->y - p2->y);
    if (o == 0) {
        int dist1 = p1->x * p1->x + p1->y * p1->y;
        int dist2 = p2->x * p2->x + p2->y * p2->y;
        return (dist1 > dist2) ? 1 : -1;
    }
    return (o > 0) ? 1 : -1;
}







void swap(vertice* a, vertice* b) {
    vertice temp = *a;
    *a = *b;
    *b = temp;
}

int orientation(vertice p, vertice q, vertice r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

void convexHull(vertice* points, int n) {
    int i, j, k = 0;
    vertice* hull = (vertice*)malloc(sizeof(vertice) * n);
    for (i = 1; i < n; i++)
        if (points[i].y < points[k].y || (points[i].y == points[k].y && points[i].x < points[k].x))
            k = i;
    swap(&points[0], &points[k]);
    qsort(&points[1], n - 1, sizeof(vertice), compare);
    hull[0] = points[0];
    hull[1] = points[1];
    int top = 1;
    for (i = 2; i < n; i++) {
        while (top > 0 && orientation(hull[top - 1], hull[top], points[i]) != 2)
            top--;
        hull[++top] = points[i];
    }
    for (i = 0; i <= top; i++)
        printf("(%d, %d) ", hull[i].x, hull[i].y);
    printf("\n");
}

int main() {
    int n, i;
    scanf("%d", &n);
    vertice points[n];
    for (i = 0; i < n; i++)
        scanf("%d %d", &points[i].x, &points[i].y);
    convexHull(points, n);
    return 0;
}
