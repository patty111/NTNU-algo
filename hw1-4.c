/*
    Problem 470 - Rabbit Hole
    http://alienryderflex.com/polygon_area/
    shoelace formula:

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
}vertice;


int main(){
    int n;
    scanf("%d", &n);
    vertice* V = (vertice*)malloc(sizeof(vertice) * n);
    

    for (int i=0;i<n;i++){
        scanf("%d %d", &V[i].x, &V[i].y);
    }








    return 0;
}