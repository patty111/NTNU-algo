#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print2D(int** arr, int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%d ", arr[j][i]);
        }
        printf("\n");
    }   
}

void fill_plate(int** plate, int num_black_blocks, int** black_blocks, int start_row, int start_col, int size, int* val) {
    int blackx, blacky;
    bool has_black = false;
    if (size == 2) {
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                if (plate[start_row+i][start_col+j] == -1){
                    // plate[start_row+i][start_col+j] = 0;
                    blackx = start_row+i;
                    blacky = start_col+j;
                    has_black = true;
                }
                else if (plate[start_row+i][start_col+j] == 0)
                    plate[start_row+i][start_col+j] = *val;
            }
        }
        *val += 1;


        if (blackx != 0 && blacky != 0 && has_black && num_black_blocks == 1){
            if (plate[blackx+1][blacky] == 0)
                plate[blackx+1][blacky] = *val;

            if (plate[blackx-1][blacky] == 0)
                plate[blackx-1][blacky] = *val;

            if (plate[blackx][blacky+1] == 0)
                plate[blackx][blacky+1] = *val;

            if (plate[blackx][blacky-1] == 0)
                plate[blackx][blacky-1] = *val; 

/////////////////////////////// diagonal
            if (plate[blackx-1][blacky-1] != 0)
                plate[blackx+1][blacky+1] = *val;
            else if (plate[blackx+1][blacky+1] != 0)
                plate[blackx-1][blacky-1] = *val;

            if (plate[blackx-1][blacky+1] != 0)
                plate[blackx+1][blacky-1] = *val;
            else if (plate[blackx+1][blacky-1] != 0)
                plate[blackx-1][blacky+1] = *val;


            *val += 1;
        }

    // print2D(plate, 4);
    //     printf("%d %d\n", blackx, blacky);
        return;
    }
    
    int half_size = size / 2;
    fill_plate(plate, num_black_blocks, black_blocks, start_row, start_col, half_size, val);
    fill_plate(plate, num_black_blocks, black_blocks, start_row, start_col+half_size, half_size, val);
    fill_plate(plate, num_black_blocks, black_blocks, start_row+half_size, start_col, half_size,val);
    fill_plate(plate, num_black_blocks, black_blocks, start_row+half_size, start_col+half_size, half_size, val);
}

int main() {
    int N, L;
    scanf("%d %d",&N , &L);
    
    int** table = (int**)malloc(sizeof(int*) * L);
    for (int i=0;i<L;i++)
        table[i] = (int*)calloc(L, sizeof(int));

    // black blocks seem no use
    int** black_blocks = (int**)malloc(sizeof(int*) * N);
    for (int i=0;i<N;i++)
        black_blocks[i] = (int*)malloc(sizeof(int) * 2);
    


    for (int i = 0; i < N; i++) {
        int x,y;
        scanf("%d %d",&x, &y);
        black_blocks[i][0] = x;
        black_blocks[i][1] = y;
        table[x][y] = -1;   
    }

    // val for filling the table
    int val = 1;
    int* ptrval = &val;
    // print2D(table, L);
    // printf("-------------------------------\n");
    fill_plate(table, N, black_blocks, 0, 0, L, ptrval);
    for (int i=0;i<N;i++){
        table[black_blocks[i][0]][black_blocks[i][1]] = 0;
    }
    print2D(table, L);

    return 0;
}

