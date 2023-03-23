#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} point;

// Compare function to sort points based on their x-coordinate.
int cmp(const void* a, const void* b) {
    point* p1 = (point*)a;
    point* p2 = (point*)b;
    return p1->x - p2->x;
}

// Function to compute the cross product of two vectors.
int cross_product(point a, point b, point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

// Function to compute the upper tangent of two convex hulls.
void compute_upper_tangent(point* hull1, int size1, point* hull2, int size2, point* result) {
    int i = size1 - 1;
    int j = size2 - 1;
    while (i >= 0 && j >= 0) {
        if (hull1[i].x < hull2[j].x) {
            result[0] = hull1[i];
            i--;
        } else if (hull1[i].x > hull2[j].x) {
            result[1] = hull2[j];
            j--;
        } else {
            if (hull1[i].y > hull2[j].y) {
                result[0] = hull1[i];
                i--;
            } else {
                result[1] = hull2[j];
                j--;
            }
        }
    }
}

// Function to compute the lower tangent of two convex hulls.
void compute_lower_tangent(point* hull1, int size1, point* hull2, int size2, point* result) {
    int i = 0;
    int j = 0;
    while (i < size1 && j < size2) {
        if (hull1[i].x < hull2[j].x) {
            result[0] = hull1[i];
            i++;
        } else if (hull1[i].x > hull2[j].x) {
            result[1] = hull2[j];
            j++;
        } else {
            if (hull1[i].y < hull2[j].y) {
                result[0] = hull1[i];
                i++;
            } else {
                result[1] = hull2[j];
                j++;
            }
        }
    }
}

// Function to compute the convex hull of a set of points using divide and conquer.
void compute_convex_hull(point* points, int size, point* hull, int* hull_size) {
    if (size <= 1) {
        *hull_size = size;
        for (int i = 0; i < size; i++) {
            hull[i] = points[i];
        }
        return;
    }

    // Sort the points based on their x-coordinate.
    qsort(points, size, sizeof(point), cmp);

    // Divide the set of points into two halves.
    point* left_half = (point*)malloc(sizeof(point) * size);
    point* right_half = (point*)malloc(sizeof(point) * size);

    int left_size = size / 2;
int right_size = size - left_size;

for (int i = 0; i < left_size; i++) {
    left_half[i] = points[i];
}
for (int i = 0; i < right_size; i++) {
    right_half[i] = points[left_size + i];
}

// Recursively compute the convex hulls of the two halves.
point* left_hull = (point*)malloc(sizeof(point) * left_size * 2);
int left_hull_size;
compute_convex_hull(left_half, left_size, left_hull, &left_hull_size);

point* right_hull = (point*)malloc(sizeof(point) * right_size * 2);
int right_hull_size;
compute_convex_hull(right_half, right_size, right_hull, &right_hull_size);

// Merge the two convex hulls.
point* upper_tangent = (point*)malloc(sizeof(point) * 2);
compute_upper_tangent(left_hull, left_hull_size, right_hull, right_hull_size, upper_tangent);

point* lower_tangent = (point*)malloc(sizeof(point) * 2);
compute_lower_tangent(left_hull, left_hull_size, right_hull, right_hull_size, lower_tangent);

*hull_size = 0;
for (int i = 0; i < left_hull_size; i++) {
    if (cross_product(lower_tangent[0], upper_tangent[0], left_hull[i]) >= 0) {
        hull[*hull_size] = left_hull[i];
        *hull_size += 1;
    }
}
for (int i = 0; i < right_hull_size; i++) {
    if (cross_product(lower_tangent[1], upper_tangent[1], right_hull[i]) <= 0) {
        hull[*hull_size] = right_hull[i];
        *hull_size += 1;
    }
}

free(left_half);
free(right_half);
free(left_hull);
free(right_hull);
free(upper_tangent);
free(lower_tangent);
}

int main() {
int n;
scanf("%d", &n);
point* points = (point*)malloc(sizeof(point) * n);
for (int i = 0; i < n; i++) {
    scanf("%d %d", &points[i].x, &points[i].y);
}

point* hull = (point*)malloc(sizeof(point) * n * 2);
int hull_size;
compute_convex_hull(points, n, hull, &hull_size);

double area = 0;
for (int i = 0; i < hull_size; i++) {
    int j = (i + 1) % hull_size;
    area += hull[i].x * hull[j].y - hull[i].y * hull[j].x;
}
area = area / 2.0;
if (area < 0) {
    area = -area;
}
printf("%.1f", area);

free(points);
free(hull);

return 0;
}