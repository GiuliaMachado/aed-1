#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matriz.h"

struct Matriz{
    int** array;
    int rows;
    int cols;
};

Matriz* matriz_create(int rows, int cols){
    //aloca primeiro a matriz
    Matriz* matriz = malloc(sizeof(Matriz));
    //depois as linhas que sao arrays
    matriz->array = malloc(rows * sizeof(int*));
    //precisa alocar as colunas e faz isso por meio de for
    for(int i = 0; i < rows; i++){
        matriz->array[i] = malloc(cols * sizeof(int));
    }
    matriz->rows = rows;
    matriz->cols = cols;

    return matriz;
}

void matriz_destroy(Matriz* matriz){
    for(int i = 0; i< matriz->rows; i++){
        //libera primeiro as colunas
        free(matriz->array[i]);
    }
    //depois as linhas
    free(matriz->array);
    //depois a matriz
    free(matriz);
}

void matriz_print(Matriz* matriz){
    for(int i = 0; i < matriz->rows; i++){
        for(int j = 0; j < matriz->cols; j++){
            printf("%d", matriz->array[i][j]);
        }
        printf("\n");
    }
}

int matriz_get(Matriz* matriz, int row, int col){
    return matriz->array[row][col];
}

void matriz_set(Matriz* matriz, int row, int col, int value){
    matriz->array[row][col] = value;
}

int matriz_rows(Matriz* matriz){
    return matriz->rows;
}

int matriz_cols(Matriz* matriz){
    return matriz->cols;
}
