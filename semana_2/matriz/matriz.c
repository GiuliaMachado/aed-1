#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matriz.h"

struct Matriz{
    double** array;
    int rows;
    int cols;
};

Matriz* matriz_create(int rows, int cols){
    //aloca primeiro a matriz
    Matriz* matriz = malloc(sizeof(Matriz));
    //depois as linhas que sao arrays
    matriz->array = malloc(rows * sizeof(double*));
    //precisa alocar as colunas e faz isso por meio de for
    for(int i = 0; i < rows; i++){
        matriz->array[i] = malloc(cols * sizeof(double));
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
            printf("%.4f", matriz->array[i][j]);
        }
        printf("\n");
    }
}

double matriz_get(Matriz* matriz, int row, int col){
    return matriz->array[row][col];
}

void matriz_set(Matriz* matriz, int row, int col, double value){
    matriz->array[row][col] = value;
}

int matriz_rows(Matriz* matriz){
    return matriz->rows;
}

int matriz_cols(Matriz* matriz){
    return matriz->cols;
}

bool matriz_equals(Matriz* matriz1, Matriz* matriz2) {
    if (matriz1->rows != matriz2->rows || matriz1->cols != matriz2->cols) {
        return false;
    }

    for (int i = 0; i < matriz1->rows; i++) {
        for (int j = 0; j < matriz1->cols; j++) {
            if (matriz1->array[i][j] != matriz2->array[i][j]) {
                return false;
            }
        }
    }

    return true;
}
//funcoes extras
bool verifica_tamanho(Matriz* matriz1, Matriz* matriz2){
    return matriz1->rows == matriz2->rows && matriz1->cols == matriz2->cols;
}
//
Matriz* matriz_add(Matriz* matriz1, Matriz* matriz2){
    if(!verifica_tamanho(matriz1, matriz2)){
        printf("As matrizes devem ter o mesmo tamanho para a adição.\n");
        abort();
    }
    Matriz* soma =  matriz_create(matriz1->rows, matriz1->cols);
    for(int i = 0; i< matriz1->rows; i++){
        for(int j = 0; j < matriz1->cols; j++){
            soma->array[i][j] = matriz1->array[i][j] + matriz2->array[i][j];
        }
    }
    return soma;
}

Matriz* matriz_sub(Matriz* matriz1, Matriz* matriz2){
    if(!verifica_tamanho(matriz1, matriz2)){
        printf("As matrizes devem ter mesmo tamanho para subtração.\n");
        abort();
    }
    Matriz* subtracao = matriz_create(matriz1->rows, matriz1->cols);
    for(int i = 0; i< matriz1->rows; i++){
        for(int j =0; j < matriz1->cols; j++){
            subtracao->array[i][j] = matriz1->array[i][j] - matriz2->array[i][j];
        }
    }
    return subtracao;
}

Matriz* matriz_scalar_mul(Matriz* matriz, double scalar){
    Matriz* mult = matriz_create(matriz->rows, matriz->cols);

    for(int i =0; i < matriz->rows; i++){
        for(int j =0; j< matriz->cols; j++){
            mult->array[i][j] = scalar * matriz->array[i][j];
        }
    }
    return mult;
}

Matriz* matriz_transpose(Matriz* matriz){
    //troca as linhas pelas colunas na criacao da transposta
    Matriz* transp = matriz_create(matriz->cols, matriz->rows);
    for(int i = 0; i < matriz->rows; i++){
        for(int j = 0; j < matriz->cols; j++){
            transp->array[j][i] = matriz->array[i][j];
        }
    }

    return transp;
}

bool matriz_is_symmetric(Matriz* matriz){
    for(int i = 0; i < matriz->rows; i++){
        for(int j = 0; j < matriz->cols; j++){
            if(matriz->array[i][j] != matriz->array[j][i]){
                return false;
            }
        }
    }
    return true;
}