
int orientation(vertice p, vertice q, vertice r){  // 0 1 2 -> collinear / counter-clockwise / clockwise
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

vertice* convex_hull(vertice* points, int n, int* hull_size){
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
