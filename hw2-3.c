#include <stdio.h>
#include <stdlib.h>
// Maximum Cardinality Bipartite Matching problem
// Hopcroft-Karp algorithm

typedef struct F{
    int start, end;
}flight;

int cmpfunc(const void* a, const void* b){
    return ((flight*)a)->start != ((flight*)b)->start ? ((flight*)a)->start - ((flight*)b)->start : ((flight*)a)->end - ((flight*)b)->end;
}

int main(){
    int n, m, f;
    scanf("%d %d %d", &n, &m, &f);
    flight* flights = (flight*)malloc(sizeof(flight) * n);
    
    for (int i=0;i<f;i++){
        scanf("%d %d", &flights[i].start, &flights[i].end);
    }

    qsort(flights, f, sizeof(flight), cmpfunc);
    
    int* up = (int*)malloc(sizeof(int) * f);
    int* down = (int*)malloc(sizeof(int) * f);
    for (int i=0;i<f;i++){
        up[i] = flights[i].start;
        down[i] = flights[i].end;
    }


    int count = 0;
    int front = flights[0].end;

    for (int i=0;i<f;i++){
        if (flights[i].end < front){
            ;
        }

    }

    for (int i=0;i<f;i++)
        printf("%2d ", up[i]);
    printf("\n\n");
    for (int i=0;i<f;i++)
        printf("%2d ", down[i]);




    return 0;	
}
