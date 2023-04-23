#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

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
    
    for (int i=0;i<f;i++){
        printf("%d %d\n", flights[i].start, flights[i].end);
    }




    return 0;	
}
